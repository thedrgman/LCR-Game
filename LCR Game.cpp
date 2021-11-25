//
//  LCR Game.cpp
//  LCR Game
//
//  Created by David Gameiro on 9/14/19.
//  Copyright © 2019 David Gameiro. All rights reserved.
//
//  David Gameiro
//  IT-312 Software Development w/C++.Net
//  10/12/19
//  LCR Game
//
//  This game is where a minimum of 3 players start with 3 chips each. Then on their turn they must roll the number of dice
//  equal to the number of chips they have, up to 3 dice. If they roll a 1 then they have to give 1 chip to the person to
//  their left. If they roll a 2 then they have to give 1 chip to the pot in the center. Then if they roll a 3 then they have
//  to give 1 chip to the person to their right. Lastly, if they roll a 4, 5, 6 then nothing is done. They must do this for
//  every dice they roll. Once someone is the only one with chips they won the game.

#include <iostream>
#include <fstream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

int players[] = {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3};
int pot = 0;
int dice1;
int dice2;
int dice3;
int a;
int b;
int c;
int n = 0;

void dice1roll(int);
void dice2roll(int);
void dice3roll(int);

int main() {
    int i;  //Number of players
    int x;  //Current player playing
    int z = 1;  //Used for annoucing how many chips everyone has
    srand (time(NULL)); //Used for rolling the dice
    int won = -1; //Helps to stop the game once someone has won
    string line; //Used to read text file that contains the rules
    
    string line_; //These next lines are used to read the text file that contains the rules
    ifstream file("LCR Rules.txt");
    if (file.is_open()) {
        while (getline(file,line_)) {
            cout << line_ << "\n";
        }
        file.close();
    }
    else {
        cout << "file is not open" << "\n";
    }
    
    cout << "\n\n";
    
    cout << "How many players will be playing? \n"; // Asking how many players are playing
    cin >> i;
    
    while (i < 3){ // Checking to see if there they minimum number of players needed
        cout << "Please add more players, minimum of three players needed to play. \n";
        cout << "How many players will be playing? \n"; //If not enough players are picked then it will keep asking for the correct number of players
        cin >> i;
    }
    
    cout << "Let's Play\n";
    cout << "\n";
    
    while (won == -1){ //To keep the game going until someone wins
    
        x = 1;
        
        cout << "Player "; cout << x; cout << "\n"; //Announces that it is player 1's turn
    
        a = players[i]; // Player to the left
        b = players[x];; // Current player
        c = players[x + 1]; // Player to the right
        
        if (players[x] == 1){ //Having only 1 chip, can only roll 1 dice
            dice1roll(n);
        }
        else if (players[x] == 2) {//Having 2 chips, can only roll 2 die
            dice1roll(n);
            dice2roll(n);
        }
        else if (players[x] > 2) { //Having 3 or more chips, can roll all 3 die
            dice1roll(n);
            dice2roll(n);
            dice3roll(n);
        }
        
        players[i] = a; //Player to the left
        players[x] = b; //Current player
        players[x + 1] = c; //Player to the right
        
        while (z <= i){ //Check to see if anyone won
            if (players[z] + pot == i * 3){ //Adds the number of chips the player has with z and then determines if it is equal to 3 times the number of players playing. If not it goes through all the players.
                won = 1; //This is used to stop the game is someone has won
                cout << "Player "; cout << z; cout << " won!!";
                cout << "\n";
                cout << "\n";
            }
            z++;
        }
        z = 1;
        
        while (z <= i){ //Announce how many chips everyone has
            cout << "Player "; cout << z; cout << " chips "; cout << players[z];
            cout << "\n";
            z++;
        }
        z = 1;
        
        cout << "Chips in the Pot "; cout << pot;//Number of chips in the pot
        cout << "\n";
        cout << "\n";
        
        if (won == 1) { //This stops the game if someone wins
            break;
        }
    
        while (x < i - 1){ //This goes through every player from player 2 to the player before the last player
            x++; //Next Player;
        
            cout << "Player "; cout << x; cout << " \n"; //Announcing player playing from player 2 to the player before the last player
        
            a = players[x - 1];
            b = players[x];
            c = players[x + 1];
        
            if (players[x] == 1){ //Having only 1 chip, can only roll 1 dice
                dice1roll(n);
            }
            else if (players[x] == 2) {//Having 2 chips, can only roll 2 die
                dice1roll(n);
                dice2roll(n);
            }
            else if (players[x] > 2) { //Having 3 or more chips, can roll all 3 die
                dice1roll(n);
                dice2roll(n);
                dice3roll(n);
            }
        
            players[x - 1] = a; //Player to the left
            players[x] = b; //Current player
            players[x + 1] = c; //Player to the right
    
            while (z <= i){
                if (players[z] + pot == i * 3){
                    won = 1;
                    cout << "Player "; cout << z; cout << " won!!";
                    cout << "\n";
                    cout << "\n";
                }
                z++;
            }
            z = 1;
    
            while (z <= i){ //Announce how many chips everyone has
                cout << "Player "; cout << z; cout << " chips "; cout << players[z];
                cout << "\n";
                z++;
            }
            z = 1;
        
            cout << "Chips in the Pot "; cout << pot;
            cout << "\n";
            cout << "\n";
    
            if (won == 1) {
                break;
            }
        }
        
        cout << "Player "; cout << i; cout << " \n"; //Announce the last player is playing
        
        a = players[i-1]; //Player to the left
        b = players[i]; //Current Player
        c = players[1]; //Player to the right
        
        if (players[x] == 1){ //Having only 1 chip, can only roll 1 dice
            dice1roll(n);
        }
        else if (players[x] == 2) {//Having 2 chips, can only roll 2 die
            dice1roll(n);
            dice2roll(n);
        }
        else if (players[x] > 2) { //Having 3 or more chips, can roll all 3 die
            dice1roll(n);
            dice2roll(n);
            dice3roll(n);
        }
        
        players[i-1] = a; //Player to the left
        players[i] = b; //Current player
        players[1] = c; //Player to the right
        
        while (z <= i){
            if (players[z] + pot == i * 3){
                won = 1;
                cout << "Player "; cout << z; cout << " won!!";
                cout << "\n";
                cout << "\n";
            }
            z++;
        }
        z = 1;
        
        while (z <= i){ //Announce how many chips everyone has
            cout << "Player "; cout << z; cout << " chips "; cout << players[z];
            cout << "\n";
            z++;
        }
        z = 1;
    
        cout << "Chips in the Pot "; cout << pot;
        cout << "\n";
        cout << "\n";
        
        if (won == 1) {
            break;
        }
    }
}

void dice1roll(int x){ //Function for rolling dice 1 and determining how the chips are moved
    dice1 = rand() % 6 + 1; //Rolls dice
    if (dice1 == 1){ //If lands on 1 then 1 chip goes to player to the right
        b --;
        a ++;
        cout << "Dice 1 is L \n";
    }
    else if (dice1 == 2){ //If lands on 2 then 1 chip goes to pot
        b --;
        pot ++;
        cout << "Dice 1 is C \n";
    }
    else if (dice1 ==3){ //If lands on 3 then 1 chip goes to player to the left
        b --;
        c ++;
        cout << "Dice 1 is R \n";
    }
    else if (dice1 == 4 or dice1 == 5 or dice1 == 6){ //If lands on 4, 5, 6 then nothing is done
        cout << "Dice 1 is dots, nothing is done \n";
    }
}

void dice2roll(int x){ //Function for rolling dice 2 and determining how the chips are moved
    dice2 = rand() % 6 + 1; //Rolls dice
    if (dice2 == 1){ //If lands on 1 then 1 chip goes to player to the right
        b --;
        a ++;
        cout << "Dice 2 is L \n";
    }
    else if (dice2 == 2){ //If lands on 2 then 1 chip goes to pot
        b --;
        pot ++;
        cout << "Dice 2 is C \n";
    }
    else if (dice2 ==3){ //If lands on 3 then 1 chip goes to player to the left
        b --;
        c ++;
        cout << "Dice 2 is R \n";
    }
    else if (dice2 == 4 or dice2 == 5 or dice2 == 6){ //If lands on 4, 5, 6 then nothing is done
        cout << "Dice 2 is dots, nothing is done \n";
    }
}

void dice3roll(int x){ //Function for rolling dice 3 and determining how the chips are moved
    dice3 = rand() % 6 + 1; //Rolls dice
    if (dice3 == 1){ //If lands on 1 then 1 chip goes to player to the right
        b --;
        a ++;
        cout << "Dice 3 is L \n";
    }
    else if (dice3 == 2){ //If lands on 3 then 1 chip goes to player to the left
        b --;
        pot ++;
        cout << "Dice 3 is C \n";
    }
    else if (dice3 ==3){ //If lands on 3 then 1 chip goes to player to the left
        b --;
        c ++;
        cout << "Dice 3 is R \n";
    }
    else if (dice3 == 4 or dice3 == 5 or dice3 == 6){ //If lands on 4, 5, 6 then nothing is done
        cout << "Dice 3 is dots, nothing is done \n";
    }
}

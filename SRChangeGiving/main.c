//
//  main.c
//  SRChangeGiving
//
//  Created by Tatyana Volkorezova on 15.10.2017.
//  Copyright © 2017 shpp.com. All rights reserved.
//

#include <stdio.h>
//#include <math.h>

const int FIFT = 50;
const int TWENFY = 25;
const int TEN = 10;
const int FIVE = 5;
const int ONE = 1;

int main() {
    
    int income = 0;
    float income_f;
    int count_50 = 0;
    int count_25 = 0;
    int count_10 = 0;
    int count_5 = 0;
    int count_1 = 0;
    int ok=0;
    
    for(;;){
        printf("\nEnter value for giving number of coins(int - hryvnas; float - coins): ");
        ok=scanf("%f", &income_f);
        
        //check is entered value char
        if (!ok){
            printf("It's a string. Pls enter correct value\n");
            fpurge(stdin);
            continue;
        }
        
        //convert to integer (coins)
            income=income_f * 100;
        
        //check is value lower than 0 or lower than 1 coin
        if (income <=0){
            printf("Can't give a change. Enter positive and >= 1 coin value\n\n");
            continue;
        }
        break;
    }
    
    //find quantity of 50 coins
    count_50=income / FIFT;
    int mod_50 = income % FIFT;
    printf("\nCOUNT of 50 coins = %d\n", count_50);
    
    //find quantity of 25 coins
    count_25=mod_50 / TWENFY;
    int mod_25=mod_50 % TWENFY;
    printf("COUNT of 25 coins = %d\n", count_25);
    
    //find quantity of 10 coins
    count_10 = mod_25 / TEN;
    int mod_10 = mod_25 % TEN;
    printf("COUNT of 10 coins = %d\n", count_10);
    
    //find quantity of 5 coins
    count_5 = mod_10 / FIVE;
    int mod_5 = mod_10 % FIVE;
    printf("COUNT of 5 coins = %d\n", count_5);
    
    //find quantity of 1 coins
    count_1 = mod_5 / ONE;
    printf("COUNT of 1 coins = %d\n", count_1);
    
    //display general count of coins
    int count = count_50 + count_25 + count_10 + count_5 + count_1;
    printf("\nGENERAL COIN'S COUNT of CHANGE = %d coins\n", count);
    return 0;
}

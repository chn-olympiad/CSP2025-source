# include <bits/stdc++.h>
using namespace std;
char number[1000005],num[1000000];
int main(){

    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    scanf("%s", number);
    int pos = 0;
    int i = strlen(number);
    for(int j = 0; j <= i; j++){
        if(number[j] == '0'){
            num[++pos] = 0;
        }
        if(number[j] == '1'){
            num[pos] = 1;
            pos++;
        }
        else if(number[j] == '2'){
            num[pos] = 2;
            pos++;
        }
        else if(number[j] == '3'){
            num[pos] = 3;
            pos++;
        }
        else if(number[j] == '4'){
            num[pos] = 4;
            pos++;
        }
        else if(number[j] == '5'){
            num[pos] = 5;
            pos++;
        }
        else if(number[j] == '6'){
            num[pos] = 6;
            pos++;
        }
        else if(number[j] == '7'){
            num[pos] = 7;
            pos++;
        }
        else if(number[j] == '8'){
            num[pos] = 8;
            pos++;
        }
        else if(number[j] == '9'){
            num[pos] = 9;
            pos++;
        }
    }
    for(int j = 0; j <= pos; j++){
        for(int k = j+1; k <= pos; k++){
            if(num[j] < num[k]){
                int temp = num[j];
                num[j] = num[k];
                num[k] = temp;
            }
        }
    }
    for(int j = 0; j <= pos-1; j++){
        printf("%d",num[j]);
    }
    return 0;
}

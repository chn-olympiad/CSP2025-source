#include<bits/stdc++.h>
using namespace std;
bool cmp(char a, char b){
    return a > b;
}
int main(){
    freopen("number.in","r", stdin);
    freopen("number.out","w", stdout);
    char s;
    int flag = 0;
    char number[1000000] = {};
    while( cin >> s ){
        if( s >='0' && s <='9'){
            number[flag] = s;
            flag ++;
        }
    }
    sort(number, number+flag,cmp);
    for(int i=0; i<flag; i++){
        cout << number[i];
    }
}

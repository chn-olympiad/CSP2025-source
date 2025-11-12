#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int my_num[10];
string a;
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin  >>  a;
    for(int i = 0;i < a.size();i++){
        if(a[i] >= '0' && a[i] <= '9'){
            my_num[a[i] - '0']++;
        }
    }
    for(int i = 9;i >= 0;--i){
        if(my_num[i] != 0){
            while(my_num[i]){
                cout  <<  i;
                my_num[i]--;
            }
        }
    }
    return 0;
}

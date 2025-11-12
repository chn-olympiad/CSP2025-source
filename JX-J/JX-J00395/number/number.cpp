#include<bits/stdc++.h>
using namespace std;
string s;
int a[10];
int main(){
    freopen("number.in" , "r" , stdin);
    freopen("number.out" , "w" , stdout);

    cin>> s;
    if(s.size() == 1 && s >= "0" && s <= "9") cout<< s;
    else{
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= '0' && s[i] <= '9'){
                int x = s[i] - '0';
                a[x]++;
            }
        }
        for(int i = 9; i >= 0; i--){
            for(int j = 1; j <= a[i]; j++) cout<< i;
        }
    }
    return 0;
}

#include<iostream>
#include<cstdio>
//define bits/stdc++.h
using namespace std;
string s;
int b[245];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        b[s[i]]++;
    }
    for(char i='9';i>='0';i--){
        for(int j=1;j<=b[i];j++){
            cout<<i;
        }
    }
    return 0;
}

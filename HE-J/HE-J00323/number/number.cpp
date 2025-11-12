#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool cmd(int a,int b){
    if(a < b) return false;
    else return true;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin >> a;
    int b[a.size()],c = a.size();
    for(int i = 0;i < a.size();i++){
        b[i] = a[i] - '0';
    }
    sort(b,b+c,cmd);
    for(int i = 0;i < a.size();i++){
        if(b[i] < 10){
            cout << b[i];
        }
    }
    return 0;
}

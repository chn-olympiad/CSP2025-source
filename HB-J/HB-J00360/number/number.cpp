#include <bits/stdc++.h>
using namespace std;

string b;
string a;
string s;
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(islower(s[i]) == 0){
            b += s[i];
        }
    }
    for(int i = 0; i < b.size(); i++){
        if(b[i] == '9'){
            a += b[i];
        }
    }
    for(int i = 0; i < b.size(); i++){
        if(b[i] == 8){
            a += b[i];
        }
    }
    for(int i = 0; i < b.size(); i++){
        if(b[i] == 7){
            a += b[i];
        }
    }
     for(int i = 0; i < b.size(); i++){
        if(b[i] == 6){
            a += b[i];
        }
    }
     for(int i = 0; i < b.size(); i++){
        if(b[i] == 5){
            a += b[i];
        }
    }
     for(int i = 0; i < b.size(); i++){
        if(b[i] == 4){
            a += b[i];
        }
    }

     for(int i = 0; i < b.size(); i++){
        if(b[i] == 3){
            a += b[i];
        }
    }
     for(int i = 0; i < b.size(); i++){
        if(b[i] == 2){
            a += b[i];
        }
    }
     for(int i = 0; i < b.size(); i++){
        if(b[i] == 1){
            a += b[i];
        }
    }
     for(int i = 0; i < b.size(); i++){
        if(b[i] == 0){
            a += b[i];
        }
    }
    cout << a;
    return 0;
}

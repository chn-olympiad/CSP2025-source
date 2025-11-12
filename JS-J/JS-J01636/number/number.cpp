//If you don't want to get 0pts,you must check:
//cerr???
//freopen???
//name???
//check???
#include<bits/stdc++.h>
using namespace std;
priority_queue<char>number;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(char c:s){
        if(isdigit(c)){
            number.push(c);
        }
    }
    while(!number.empty()){
        putchar(number.top());
        number.pop();
    }
    return 0;
}
//CSP-J 2025 R2 rp++!

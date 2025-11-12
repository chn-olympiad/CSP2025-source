#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,b="";
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]-0=='9'){
            b+="9";
        }
    }
    for(int i=0;i<s.length();i++){
        if(s[i]-0=='8'){
            b+="8";
        }
    }
    for(int i=0;i<s.length();i++){
        if(s[i]-0=='7'){
            b+="7";
        }
    }
    for(int i=0;i<s.length();i++){
        if(s[i]-0=='6'){
            b+="6";
        }
    }
    for(int i=0;i<s.length();i++){
        if(s[i]-0=='5'){
            b+="5";
        }
    }
    for(int i=0;i<s.length();i++){
        if(s[i]-0=='4'){
            b+="4";
        }
    }
    for(int i=0;i<s.length();i++){
        if(s[i]-0=='3'){
            b+="3";
        }
    }
    for(int i=0;i<s.length();i++){
        if(s[i]-0=='2'){
            b+="2";
        }
    }
   for(int i=0;i<s.length();i++){
        if(s[i]-0=='1'){
            b+="1";
        }
    }
    for(int i=0;i<s.length();i++){
        if(s[i]-0=='0'){
            b+="0";
        }
    }
    cout<<b;

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s,o={0};
    cin>>s;

    for(int i=1;i<=s.length();i++){
        if(s[i]<='9'&&s[i]>='0') s[i]=o[i];

    }
    cout<<o;
    return 0;
}

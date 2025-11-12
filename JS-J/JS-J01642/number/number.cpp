#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    char ch=getchar();
    while(isdigit(ch)||isalpha(ch)){
        if(isdigit(ch)) s+=ch;
        ch=getchar();
    }
    sort(s.begin(),s.end(),greater<char>());
    if(s[0]==0) cout<<0<<endl;
    else cout<<s<<endl;
    return 0;
}
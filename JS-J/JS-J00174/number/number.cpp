#include<bits/stdc++.h>
using namespace std;
bool cmp(char x,char y){return x>y;}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,a=""; cin>>s;
    for(int i=0;i<s.size();i++) if('0'<=s[i]&&s[i]<='9') a+=s[i];
    sort(a.begin(),a.end(),cmp);
    cout<<a; return 0;
}//ACPlease!!
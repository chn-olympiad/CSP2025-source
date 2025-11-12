#include<bits/stdc++.h>
using namespace std;
string s,ss="";
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
        if(isdigit(s[i]))
            ss+=s[i];
    sort(ss.begin(),ss.end());
    for(int i=ss.size()-1;i>=0;i--)
        cout<<ss[i];
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

string s,ans;
int a[12];

string f(string s){
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!='0') return s.substr(i);
    }
    return "0";
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(isdigit(s[i])) a[(int)(s[i]-'0')]++;
    }
    for(int i=9;i>=0;i--)
    {
        for(;a[i]>0;a[i]--) ans+=(char)(i+'0');
    }
    cout<<f(ans);
    return 0;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll t[109];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(ll i=0;i<s.size();i++)
    if(s[i]-'0'<=9&&s[i]-'0'>=0)
    t[s[i]-'0']++;
    for(ll i=9;i>=0;i--)
    while(t[i]--)
    cout<<i;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s,t;
map<char,int>mp;
void solve()
{
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]<='9'&&s[i]>='0')
        {
            mp[s[i]]++;
        }
    }
    for(char i='9';i>='1';i--)
    {
        while(mp[i]--)
            cout<<i;
    }
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int T=1;
    while(T--)
    {
        solve();
    }
    return 0;
}

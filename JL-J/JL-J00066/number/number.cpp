#include <bits/stdc++.h>
using namespace std;
int f[10];
string s;
signed main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0' && s[i]<='9')
            f[s[i]-'0']++;
    }
    bool fl=0;
    for(int i=9;i>=1;i--)
    {
        if(f[i])
            fl=1;
        for(int j=1;j<=f[i];j++)
            cout<<i;
    }
    if(!fl)
        cout<<0;
    else
    {
        for(int i=1;i<=f[0];i++)
            cout<<0;
    }
    return 0;
}

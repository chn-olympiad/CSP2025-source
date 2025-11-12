#include<bits/stdc++.h>
#define int long long
using namespace std;
string s,s2,ans;int a[10],f=0;
signed main()
{
    ios::sync_with_stdio(false);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int sz=s.size();
    for(int i=0;i<sz;i++)
        if(isdigit(s[i]))
            a[s[i]-'0']++;
    for(int i=9;i>=1;i--)
    {
        while(a[i])ans+=i+'0',a[i]--,f=1;
    }
    if(f)while(a[0])ans+='0',a[0]--;
    else ans+='0';
    cout<<ans;
    return 0;
}

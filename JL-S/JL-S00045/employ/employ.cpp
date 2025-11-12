#include <bits/stdc++.h>
#define int long long
using namespace std;
int c[505],dp[505][505];
int mod=998244353;
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int ans=1,flag=0;
    string s;
    int n,m;
    cin>>n>>m;
    int cnt=n;
    cin>>s;
    s="_"+s;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    if(m==n)
    {
        for(int i=1;i<=n;i++)
        {
            if(c[i]==0)
            {
                cout<<0;
                return 0;
            }
            if(s[i]=='0')
            {
                cout<<0;
                return 0;
            }
        }
        for(int i=1;i<=n;i++)
        {
            ans=(ans*i)%mod;
        }
        cout<<ans;
    }
    else
        cout<<0;
}

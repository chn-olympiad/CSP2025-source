#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
char s[506];
int c[506],dp[1<<18][19];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    cin>>(s+1);
    for(int i=1;i<=n;i++) cin>>c[i];
    if(n==m)
    {
        int flag=1;
        for(int i=1;i<=n;i++)
            if(s[i]=='0')
            {
                flag=0;
                break;
            }
        for(int i=1;i<=n;i++)
        {
            if(!c[i])
            {
                flag=0;
                break;
            }
        }
        if(!flag)
        {
            cout<<'0';
            return 0;
        }
        long long ans=1;
        for(int i=1;i<=n;i++) ans=ans*i%mod;
        cout<<ans;
        return 0;
    }
    dp[0][0]=1;
    for(int i=0;i<(1<<n);i++)
    {
        int js=0;
        for(int j=1;j<=n;j++) if((i>>j-1)&1) js++;
        for(int j=0;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
                if(!((i>>k-1)&1))
                {
                    int l=i+(1<<k-1);
                    int qi=js-j;
                    if(s[js+1]=='0'||qi>=c[k]) qi++;
                    dp[l][js+1-qi]+=dp[i][j];
                    if(dp[l][js+1-qi]>=mod) dp[l][js+1-qi]-=mod;
                }
        }
    }
    int ans=0;
    for(int i=m;i<=n;i++)
    {
        ans+=dp[(1<<n)-1][i];
        if(ans>=mod) ans-=mod;
    }
    cout<<ans;
    return 0;
}
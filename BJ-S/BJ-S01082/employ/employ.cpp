#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
#define ull unsigned long long
using namespace std;
const int N=505,mod=998244353,M=1e6+5;
int n,m,a[N],c[N],ans,flag=1,cl;
char ch;
ull dp[M][25];
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    faster;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> ch;
        a[i]=ch-'0';
        flag=flag&a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin >> c[i];
        if(c[i]==0)cl=1;
    }
    if(m==1)
    {
        ans=1;
        for(int i=1;i<=n;i++)
        {
            ans=ans*i%mod;
        }
        if(flag==0||cl)cout << 0;
        else cout << ans;
        return 0;
    }
    else if(n<=18)
    {
        dp[0][0]=1;
        for(int i=0;i<n;i++)
        {
            for(int sta=0;sta<(1<<n);sta++)
            {
                if(__builtin_popcount(sta)==i)
                {
                    for(int k=0;k<=i;k++)
                    {
                        dp[sta][k]%=mod;
                        for(int j=1;j<=n;j++)
                        {
                            if(!(sta&(1<<j-1)))
                            {
                                if(k>=c[j]||a[i+1]==0)
                                {
                                    dp[sta^(1<<j-1)][k+1]+=dp[sta][k];
                                }
                                else
                                {
                                    dp[sta^(1<<j-1)][k]+=dp[sta][k];
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=0;i<=n-m;i++)
        {
            ans=(ans+dp[(1<<n)-1][i])%mod;
        }
    }
    else if(flag)
    {
        ans=1;
        for(int i=1;i<=n;i++)
        {
            ans=ans*i%mod;
        }
    }
    cout << ans;
    return 0;
}
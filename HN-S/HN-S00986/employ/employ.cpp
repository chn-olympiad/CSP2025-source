#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=505,mod=998244353;
int n,m,c[maxn],f[1<<18][20],fac=1;
string S;
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>S;
    for(int i=1;i<=n;i++) cin>>c[i];
    if(m==n)
    {
        for(int i=1;i<=n;i++) fac=1ll*fac*i%mod;
        cout<<fac;
        exit(0);
    }
    else if(n>18){cout<<0;exit(0);}
    f[0][0]=1;
    for(int s=0;s<(1<<n);s++)
        for(int x=0;x<n;x++)
        {
            if(((s>>x)&1)==1) continue;
            for(int j=0;j<=n;j++)
            {
                if(f[s][j]==0) continue;
                // cout<<s<<' '<<j<<" "<<f[s][j]<<"\n";
                if(S[__builtin_popcount(s)]=='1') (f[s+(1<<x)][j+(j>=c[x+1])]+=f[s][j])%=mod;
                else (f[s+(1<<x)][j+1]+=f[s][j])%=mod;
            }
        }
    int sum=0;
    for(int i=0;i<=n-m;i++) (sum+=f[(1<<n)-1][i])%=mod;
    cout<<sum<<"\n";
}
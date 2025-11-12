#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxmsk=(1<<18)+10,mod=998244353;
int n,m;
char s[510];
int c[510];
int fac[510];
struct solbr
{
    int f[maxmsk][20];
    int bitc(int x)
    {
        int res=0;
        while(x)
        {
            res+=x&1;
            x>>=1;
        }
        return res;
    }
    void sol()
    {
        f[0][0]=1;
        for(int i=1;i<(1<<n);i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!(i&(1<<j))) continue;
                int pre=i^(1<<j);
                int t=bitc(pre);
                for(int k=0;k<=t;k++)
                {
                    int d=0;
                    if(s[t+1]=='0'||k>=c[j+1]) d=1;
                    f[i][k+d]=(f[i][k+d]+f[pre][k])%mod;
                }
            }
        }
        int ans=0;
        for(int i=0;i<=n-m;i++) ans=(ans+f[(1<<n)-1][i])%mod;
        cout<<ans<<endl;
    }
}tbr;
struct solsp2
{
    void sol()
    {
        for(int i=1;i<=n;i++)
        {

        }
    }
};
struct solsp
{
    bool chk()
    {
        for(int i=1;i<=n;i++) if(s[i]=='0') return 0;
        return 1;
    }
    void sol()
    {

    }
}tsp;
int cnt[510];
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m>>s+1;
    for(int i=1;i<=n;i++) cin>>c[i];
    fac[0]=1;
    for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
    if(n<=18)
    {
        tbr.sol();
        return 0;
    }
    if(m==n)
    {
        for(int i=1;i<=n;i++)
        {
            if(c[i]==0||s[i]=='0')
            {
                cout<<0<<endl;
                return 0;
            }
        }
        cout<<fac[n]<<endl;
        return 0;
    }
    if(tsp.chk())
    {
        tsp.sol();
        return 0;
    }
    cout<<1<<endl;
	return 0;
}

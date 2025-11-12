#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<ctime>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll inf=1e18;
const ll mod=998244353;
inline ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline char gtc()
{
    char ch=getchar();
    while(ch!='0'&&ch!='1')ch=getchar();
    return ch;
}
ll n,m;
ll s[505],a[505],c[505],sum[505];
ll f[505][505],g[505][505];
ll fac[505],invf[505];
ll binom(ll x,ll y){return fac[x]*invf[x-y]%mod*invf[y]%mod;}
ll power(ll a,ll b)
{
    ll r=1,w=a;
    while(b)
    {
        if(b&1)r=r*w%mod;
        w=w*w%mod,b>>=1;
    }
    return r%mod;
}
void solve()
{
    n=read(),m=read();
    fac[0]=1;for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
    invf[n]=power(fac[n],mod-2);
    for(int i=n-1;i>=0;i--)invf[i]=invf[i+1]*(i+1)%mod;
    for(int i=1;i<=n;i++)s[i]=gtc()-'0';
    for(int i=1;i<=n;i++)a[i]=read(),c[a[i]]++;
    sum[0]=c[0];
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+c[i];
    g[0][0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            for(int x=0;x<=i&&x<=sum[j];x++)
            {
                ll tmp=g[j][x]*(sum[j]-x)%mod*fac[i-x]%mod*fac[c[j+1]]%mod;
                for(int y=0;y<=c[j+1]&&y<=i-x;y++)
                {
                    if(!(sum[j]-x))break;
                    f[j+1][x+y+1]+=tmp*invf[y]%mod*invf[c[j+1]-y]%mod*invf[i-x-y];
                    f[j+1][x+y+1]%=mod;
                }
                if(s[i+1]==1&&(n-sum[j]-(i-x)))f[j][x]+=g[j][x],f[j][x]%=mod;
                if(s[i+1]==0)
                {
                    ll tmpp=g[j][x]*fac[i-x+1]%mod*fac[c[j+1]]%mod;
                    for(int y=0;y<=c[j+1]&&y<=i-x+1;y++)
                    {
                        f[j+1][x+y]+=tmpp*invf[y]%mod*invf[c[j+1]-y]%mod*invf[i-x-y+1];
                        f[j+1][x+y]%=mod;
                    }
                }
            }
        }
        for(int j=0;j<=n;j++)
        {
            for(int x=0;x<=n;x++)
            {
                g[j][x]=f[j][x],f[j][x]=0;
            }
        }
    }
    ll res=0;
    for(int i=0;n-i>=m;i++)res+=g[i][sum[i]]*fac[n-sum[i]]%mod;
    cout<<res%mod<<'\n';
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    // clock_t start=clock();
    ll c=0,t=1;
    while(t--)solve();
    // clock_t end=clock();
    // cerr<<(end-start)*1.00/CLOCKS_PER_SEC<<'\n';
    return 0;
}
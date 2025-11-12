#include<bits/stdc++.h>
#define LL long long
#define fr(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);
using namespace std;
const int N=505,mod=998244353;
int n,m,c[N],sum[N],jc[N],inv[N];bool o[N];
string S;
inline int md(int x){return x>=mod?x-mod:x;}
inline void ad(int &x,int y){x+=y;(x>=mod)&&(x-=mod);}
inline int ksm(int x,int p){int s=1;for(;p;(p&1)&&(s=1ll*s*x%mod),x=1ll*x*x%mod,p>>=1);return s;}
namespace sol1{
    #define pc __builtin_popcount
    int f[1<<18|5][19];
    inline void sol()
    {
        f[0][0]=1;int u=1<<n,ans=0;
        for(int i=0;i<u-1;i++)
        {
            int t=pc(i)+1;
            for(int j=0;j<n;j++) if(!(i>>j&1))
            {
                int I=i|(1<<j);
                for(int k=0;k<n;k++)
                {
                    ad(f[I][k+(!o[t]||k>=c[j+1])],f[i][k]);
                }
            }
        }
        for(int i=0;i<=n-m;i++) ad(ans,f[u-1][i]);
        cout<<ans<<"\n";
    }
}
int main()
{
    fr(employ)
    cin.tie(0)->sync_with_stdio(0);cin>>n>>m>>S;
    for(int i=1;i<=n;i++) o[i]=S[i-1]-'0';
    for(int i=1;i<=n;i++) cin>>c[i];

    if(n<=18) return sol1::sol(),0;
    if(m==n)
    {
        if(count(o+1,o+1+n,0)) return cout<<0,0;
        if(count(c+1,c+1+n,0)) return cout<<0,0;
        int s=1;
        for(int i=1;i<=n;i++) s=1ll*s*i%mod;
        return cout<<s,0;
    }

    if(m==1)
    {
        sort(c+1,c+1+n);
        for(int i=1;i<=n;i++) sum[c[i]]++;
        for(int i=1;i<=n;i++) sum[i]+=sum[i-1];
        for(int i=*jc=1;i<=n;i++) jc[i]=1ll*i*jc[i-1]%mod;
        inv[n]=ksm(jc[n],mod-2);for(int i=n;i;i--) inv[i-1]=1ll*inv[i]*i%mod;
        int s=1,ans=0,C=0,CC=0;
        for(int i=1;i<=n;i++)
        {
            if(i==1) CC+=sum[i-1];
                else CC+=sum[i-1]-sum[i-2];
            if(o[i])
            {
                // if(sum[n]-sum[i-1]>=1)
                if(sum[i-1]>=C)
                ans=(ans+1ll*s*(sum[n]-sum[i-1])%mod*jc[n-i]%mod*jc[sum[i-1]]%mod*inv[sum[i-1]-C])%mod;
                // CC+=sum[i-1];
                
                s=1ll*s*CC%mod;CC--;
            }
            else C++;
        }
        return cout<<ans,0;
    }
    return 0;
}
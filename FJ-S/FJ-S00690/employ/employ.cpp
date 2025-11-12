#include<bits/stdc++.h>
using namespace std;
#define maxn 505
#define ll long long
#define frp freopen
#define  fio(in,out) frp(in,"r",stdin),frp(out,"w",stdout)
void bug(){cout<<endl;}
template<typename T,typename ... Ts>
void bug(T x,Ts ... y){cout<<x<<" ",bug(y...);}
template<typename T=int>
T read(){
    T res=0,f=1;char c;
    for(;(c=getchar())<'0'||c>'9';c=='-'?f=-f:0);
    while(c>='0'&&c<='9')res=(res<<3)+(res<<1)+c-'0',c=getchar();
    return res*f;
}
const int mod=998244353;
int n,m,c[maxn];
char s[maxn];
namespace sub1{
    ll fac[maxn];
    void solve(){
        int i;ll ans=1;
        fac[0]=1;
        for(i=1;i<=n;++i)fac[i]=fac[i-1]*i%mod;
        for(i=1;i<=n;++i)if(s[i]!='1'||c[i]==0){
            puts("0");
            return;
        }
        printf("%lld",fac[n]);
    }
}
namespace force{
    ll f[1<<18|5][505],ans;
    void solve(){
        int i,j,k;
        f[0][0]=1;
        for(i=1;i<(1<<n);++i){
            int t=__builtin_popcount(i);
            for(j=0;j<=t;++j){
                for(k=1;k<=n;++k)if(i>>(k-1)&1)
                {
                    int w=(s[t]=='0'||c[k]<=j);
                    f[i][j+w]=(f[i][j+w]+f[i^(1<<k-1)][j])%mod;
                    // bug("!",i,j,k,j+w,f[i][j+w]);
                }
            }
        }
        for(i=0;i<=n-m;++i)ans=(ans+f[(1<<n)-1][i])%mod;
        printf("%lld",ans);
    }
}
int main(){
    int i;
    fio("employ.in","employ.out");
    n=read(),m=read();
    scanf("%s",s+1);
    for(i=1;i<=n;++i)c[i]=read();
    if(n<=18){
        return force::solve(),0;
    }
    if(m==n){
        return sub1::solve(),0;
    }
    return 0;
}
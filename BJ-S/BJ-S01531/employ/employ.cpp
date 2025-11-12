#include <bits/stdc++.h>
#define il inline
using namespace std;
typedef long long ll;
const ll mod=998244353;
il ll qp(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        a=a*a%mod,b>>=1;
    }return ans;
}
il void add(ll &x,ll y){x=(x+y>=mod?x+y-mod:x+y);}
il int read(){
    int x=0,c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) x=x*10+c-48,c=getchar();
    return x;
}
const int N=505,M=(1<<18)+5,K=18;
int n,m,a[N],c[N];char s[N];ll f[M][K+1],fac[N],inv[N],dp[N][N];
il void init(){
    fac[0]=1;for(int i=1;i<=n;++i) fac[i]=fac[i-1]*1ll*i%mod;
    inv[n]=qp(fac[n],mod-2);for(int i=n-1;i>=0;--i) inv[i]=inv[i+1]*(i+1ll)%mod;
}
il ll C(int n,int m){return n<0 || m<0 || n<m?0:fac[n]*inv[m]%mod*inv[n-m]%mod;}
int x,y,z,u,v,w;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d%s",&n,&m,s+1);init();
    for(int i=1;i<=n;++i) a[i]=read();
    if(n<=18){
        int S=(1<<n);f[0][0]=1;
        for(int i=0;i<S-1;++i){
            x=0;for(int j=0;j<n;++j) if((i>>j)&1) ++x;
            for(int k=0;k<=x;++k){
                if(!f[i][k]) continue;
                for(int j=0;j<n;++j){
                    if((i>>j)&1) continue;
                    if(a[j+1]<=k || s[x+1]=='0') add(f[i|(1<<j)][k+1],f[i][k]);
                    else add(f[i|(1<<j)][k],f[i][k]);
                }
            }
        }
        ll ans=0;for(int i=0;i<=n-m;++i) add(ans,f[S-1][i]);
        printf("%lld",ans);exit(0);
    }
    if(m==1){
        for(int i=1;i<=n;++i) ++c[a[i]];
        int num=0;for(int i=1;i<=n;++i) if(s[i]=='0') ++num;
        ll ans=0;
        dp[0][0]=1;
        int ss=0,tot=0;
        for(int i=1;i<=n;++i){
            if(s[i]=='0'){
                ss+=c[i-1];
                for(int j=0;j<=num;++j){
                    if(!dp[i-1][j]) continue;
                    //printf("* %d %d %d %d %lld\n",i-1,j,ss,num,dp[i-1][j]);
                    for(int k=0;k<=c[i-1] && j+k<=num;++k){
                        add(dp[i][j+k],dp[i-1][j]*C(c[i-1],k)%mod);
                    }
                }
            }
            else{
                ss+=c[i-1];
                for(int j=0;j<=num;++j){
                    if(!dp[i-1][j]) continue;
                    //printf("*** %d %d %d %%lld\n",i-1,j,dp[i-1][j],num);
                   // printf("*** %d %d %d %d %lld\n",i-1,j,ss,num,dp[i-1][j]);
                    for(int k=0;k<=c[i-1] && j+k<=num;++k){
                        x=ss-j-k-tot;if(x<=0) break;
                        w=C(c[i-1],k)*x%mod;
                        add(dp[i][j+k],dp[i-1][j]*w%mod);
                        //if(i-1==2 && j==5) puts("*");
                    }
                }
                ++tot;
            }
        }
        for(int i=0;i<=num;++i){
            add(ans,dp[n][i]*C(c[n],num-i)%mod);
        }
        //printf("%d %d %d %lld\n",n,num,ss,ans);
        printf("%lld",(fac[n]-ans*fac[num]%mod+mod)%mod);
        return 0;
    }
    if(m==n){
        x=1;
        for(int i=1;i<=n;++i) if(a[i]==0 || s[i]=='0') x=0;
        if(x) printf("%lld",fac[n]);
        else printf("0");
        return 0;
    }
    return 0;
}

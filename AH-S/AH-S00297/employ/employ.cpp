#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define pr pair<int,int>
using namespace std;
template<typename T>void in(T &x){
    char c=getchar();int f=1;
    while((c<'0'||c>'9')&&c!='-') c=getchar();
    if(c=='-'){c=getchar();f=-1;}
    for(x=0;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
    x*=f;
}
template<typename T>T mn(T a,T b){return a<b?a:b;}
template<typename T>T mx(T a,T b){return b<a?a:b;}
const int N=505,mod=998244353;
int n,m,a[N],sum[N];
int w[N];
char ss[N];
int dp[1<<18][20];
int can[N],lim[N];
ll f[N][N];
ll fac[N];
ll calc(int x,int y){
    ll res=1;
    for(int i=x;i>=x-y+1;--i) res=res*i%mod;
    return res;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    in(n),in(m);
    fac[0]=1;for(int i=1;i<=n;++i) fac[i]=fac[i-1]*i%mod;
    scanf("%s",ss+1);
    for(int i=1;i<=n;++i) in(a[i]);
    sort(a+1,a+1+n);
    for(int i=0;i<=n;++i){
        for(int j=1;j<=n;++j) if(a[j]>i){can[i]=j;break;}
    }
    bool ok=1;int cnt=0;
    for(int i=1;i<=n;++i){if(ss[i]=='0') ok=0;else w[cnt++]=i;}
    if(m==n){
        if(!a[1]||!ok){printf("0\n");return 0;}
        printf("%lld\n",fac[n]);
        return 0;
    }
    if(n<=18){
        int e=1<<n;
        dp[0][0]=1;
        for(int i=0;i<n;++i){
            for(int s=0;s<e;++s){
                if(__builtin_popcount(s)!=i) continue;
                for(int j=1;j<=n;++j){
                    if(s&(1<<(j-1))) continue;
                    for(int k=0;k<=i;++k){
                        bool tf=(ss[i+1]=='1'&&a[j]>k);
                        (dp[s|(1<<(j-1))][k+(!tf)]+=dp[s][k])%=mod;
                    }
                }
            }
        }
        ll ans=0;
        for(int i=0;i<=n-m;++i) ans+=dp[e-1][i];
        ans%=mod;
        printf("%lld\n",ans);
        return 0;
    }
    if(m==1){
        f[0][0]=1;a[0]=-1;
        ll ans=0;
        for(int i=n;i>=1;i--) sum[i]=sum[i+1]+(ss[i]=='1');
        for(int i=0,nxt;i<=n;i=nxt){
            for(int j=0;j<=n;++j) if(a[j]>i-1){ans+=f[i][j]*calc(n-(sum[1]-sum[i+1]),sum[i+1])%mod;f[i][j]=0;}
            nxt=i+1;
            while(nxt<=n&&ss[nxt]=='0') nxt++;
            if(nxt>n) break;
            for(int j=0;j<=n;++j){
                (f[nxt][j]+=f[i][j]*(j-(sum[1]-sum[i+1])))%=mod;
                for(int k=j+1;k<=n;++k) (f[nxt][k]+=f[i][j])%=mod;
//                if(f[i][j]) printf("%d %d %lld\n",i,j,f[i][j]);
            }
        }
        int x=0;
        for(int i=1;i<=n;++i) if(ss[i]=='0') x++;
        ans%=mod;ans=ans*fac[x]%mod;
        printf("%lld\n",ans);
        return 0;
    }
    if(cnt<=18){
        int e=(1<<cnt);ll ans=0;
        for(int i=1;i<=n;++i) sum[i]=sum[i-1]+(ss[i]=='0');
        for(int s=0;s<e;++s){
            if(__builtin_popcount(s)<m) continue;
            int now=0;
            for(int j=0;j<cnt;++j){
                if(s&(1<<j)) lim[j]=can[sum[w[j]-1]+(j-now)],now++;
            }
            ll su=1;
            now=0;
            for(int j=cnt-1;j>=0;j--) if(s&(1<<j)) su=su*(n-lim[j]+1-now)%mod,now++;
            ans+=su*fac[n-now]%mod;
        }
        ans=ans%mod;
        printf("%lld\n",ans);
        return 0;
    }
    return 0;
}

#include<bits/stdc++.h>
#define ll long long 
#define ep emplace
#define fi first
#define se second 
#define pc(x) __builtin_popcount(x)
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int,int>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;c<'0'||c>'9';c=getchar())if(c=='-') f=-1;
    for(;'0'<=c&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
const int N=510,mod=998244353;
int n,m,p[N],c[N],ans;ll f[N][N],cnt[N];
ll dp[1<<18][20];
char s[N];
void misaka(){
    n=read(),m=read();
    scanf("%s",s+1);
    rep(i,1,n) c[i]=read(),p[i]=i;
    if(n<=18){
        dp[0][0]=1;
        rep(S,0,(1<<n)-1)rep(j,0,pc(S)){
            rep(k,1,n)if(~S>>k-1&1){
                int x=pc(S),t=x-j,T=S|(1<<k-1);
                if(s[x+1]=='0'||t>=c[k]) (dp[T][j]+=dp[S][j])%=mod;
                else (dp[T][j+1]+=dp[S][j])%=mod;
            }
        }
        rep(i,m,n) (ans+=dp[(1<<n)-1][i])%=mod;
        printf("%d",ans);
        return;
    }
    if(m==n){
        if(count(s+1,s+n+1,'0')||count(c+1,c+n+1,0)){
            puts("0");
            return;
        }
        ll res=1;
        rep(i,2,n) res=res*i%mod;
        printf("%lld",res);
        return;
    }
    
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    int T=1;
    rep(i,1,T) misaka();
    return 0;
}
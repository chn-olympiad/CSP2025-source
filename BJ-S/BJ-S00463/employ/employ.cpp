#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
template<typename T>
void chkmin(T &x,const T &y){x=min(x,y);}
template<typename T>
void chkmax(T &x,const T &y){x=max(x,y);}
const int inf=0x3f3f3f3f;
const ll infll=0x3f3f3f3f3f3f3f3f;
const int MOD=998244353;
void add(int &x,int y){
    x+=y;
    if(x>=MOD) x-=MOD;
}
int qpow(int a,ll b){
    int mul=1;
    while(b){
        if(b&1) mul=(ll)mul*a%MOD;
        a=(ll)a*a%MOD;
        b>>=1;
    }
    return mul;
}
const int N=505;
int n,m,c[N],dp[(1<<18)+5][25];
char s[N];
int main(){
    #ifndef JZQ
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    #endif
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++) s[i]-='0';
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    if(m==n){
        for(int i=1;i<=n;i++) if(!c[i]||!s[i]){
            printf("0\n");
            return 0;
        }
        int mul=1;
        for(int i=1;i<=n;i++) mul=(ll)mul*i%MOD;
        printf("%d\n",mul);
        return 0;
    }
    dp[0][0]=1;
    for(int S=0;S<(1<<n);S++){
        int cnt=__builtin_popcount(S);
        for(int j=0;j<=cnt;j++){
            for(int i=1;i<=n;i++){
                if((S>>(i-1))&1) continue;
                if(!s[cnt+1]||cnt-j>=c[i]) add(dp[S|(1<<(i-1))][j],dp[S][j]);
                else add(dp[S|(1<<(i-1))][j+1],dp[S][j]);
            }
        }
    }
    int ans=0;
    for(int i=m;i<=n;i++) add(ans,dp[(1<<n)-1][i]);
    printf("%d\n",ans);
    return 0;
}
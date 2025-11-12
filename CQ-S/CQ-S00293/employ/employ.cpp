#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pr pair<int,int>
#define mk make_pair
#define lc x<<1
#define rc x<<1|1
#define N 2005
const int p=998244353;
int f[N][N],ok[N],n,m,c[N][N],cnt[N],jc[N],dp[N],g[N];
signed main(){
    clock_t st=clock();
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;jc[0]=1;
    for(int i=1;i<=n;++i)jc[i]=jc[i-1]*i%p;
    c[0][0]=1;
    for(int i=1;i<=n;++i){
        c[i][0]=1;
        for(int j=1;j<=i;++j)(c[i][j]=c[i-1][j-1]+c[i-1][j])%p;
    }
    int all=0;
    for(int i=1;i<=n;++i){
        char x;cin>>x;
        ok[i]=x-'0';
        if(!ok[i])all|=1<<i-1;
    }
    for(int i=1,x;i<=n;++i){
        cin>>x;++cnt[x];
    }
    for(int i=n;~i;--i)cnt[i]+=cnt[i+1];
    for(int k=0;k<=n;++k){
        memset(f,0,sizeof f);
        f[n+1][k]=1;/*还有k个1没有填*/
        for(int i=n;i;--i){
            for(int j=0;j<=k&&j<=i;++j){
                if(ok[i]){
                    if(f[i+1][j+1]&&ok[i]&&cnt[i-j]-(k-j-1)>=0)f[i][j]+=f[i+1][j+1]*(cnt[i-j]-(k-j-1))%p;
                    f[i][j]+=f[i+1][j];
                }
                else f[i][j]=f[i+1][j];
                f[i][j]%=p;
            }
        }
        dp[k]=f[1][0]*jc[n-k]%p;
    }
    int res=0;
    for(int k=n;k;--k){
        for(int i=k+1;i<=n;++i)dp[k]-=dp[i];
        dp[k]=(dp[k]%p+p)%p;
        if(k>=m)res+=dp[k]%p;
    }  
    cout<<(res%p+p)%p<<"\n";
    cerr<<fixed<<setprecision(10)<<(double)(clock()-st)/CLOCKS_PER_SEC<<"\n";
}
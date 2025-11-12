//好想去 WC，好想与大家在一起，好想去 WC 唱歌……
//为了在这个可能是最后的，或许本来就并不应该存在的赛季，不留遗憾，
//会赢吗？
#include<iostream>
using namespace std;
const int maxn=505;
const int mod=998244353;
int n,m,p[maxn],dp[maxn][maxn],buf[maxn][maxn],inv[maxn];
char str[maxn];
void add(int& x,const int& y){(x+=y)>=mod?x-=mod:0;}
int power(int x,int y){
    int res=1;
    for(;y;y>>=1,x=(long long)x*x%mod)if(y&1)res=(long long)res*x%mod;
    return res;
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m>>str+1;
    for(int i=1;i<=n;++i){
        int x;cin>>x;
        p[x]++;
    }
    for(int i=n-1;i>=0;--i)p[i]+=p[i+1];
    for(int i=m;i<=n;++i)dp[0][i]=1;
    for(int i=1;i<=n;++i)inv[i]=power(i,mod-2);
    for(int i=n+1;i>=2;--i)if(str[i-1]=='1'){
        for(int j=0;j<=n;++j)for(int u=0;u<=n;++u)buf[j][u]=dp[j][u];
        for(int j=0;j<=n-i+1;++j)for(int u=0;u<=i-1;++u)if(dp[j][u]){
            if(u&&p[i-u]>j)add(buf[j+1][u-1],(long long)dp[j][u]*(p[i-u]-j)%mod*inv[n-j]%mod);
            if(p[i-1-u]>j)add(buf[j+1][u],mod-(long long)dp[j][u]*(p[i-1-u]-j)%mod*inv[n-j]%mod);
        }
        for(int j=0;j<=n;++j)for(int u=0;u<=n;++u)dp[j][u]=buf[j][u];
    }
    int ans=0;
    for(int i=m;i<=n;++i)add(ans,dp[i][0]);
    for(int i=1;i<=n;++i)ans=(long long)ans*i%mod;
    cout<<ans;
    return 0;
}
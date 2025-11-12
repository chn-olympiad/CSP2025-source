#include<cstdio>
#include<algorithm>
#define N 500005
#define V (1<<20)+5
int n,k,a[N],s[N],dp[N],g[V],ans;
int main(){
    freopen("xor.in","r",stdin),freopen("xor.out","w",stdout),scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),s[i]=a[i]^s[i-1];//,ans+=a[i];
    for(int i=1;i<V;i++)g[i]=-1e9;
    for(int i=1;i<=n;i++)dp[i]=std::max(dp[i-1],g[s[i]^k]+1),g[s[i]]=std::max(g[s[i]],dp[i]),ans=std::max(ans,dp[i]);
    printf("%d",ans);
}
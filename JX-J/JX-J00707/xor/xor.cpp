#include<cstdio>
#include<algorithm>
using namespace std;
int b[1048576],n,k,dp[500005],a[500005],t[500005];
void solve(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    //for(int i=1;i<=n;i++)printf("%d ",a[i]);
    //printf("\n");
    for(int i=1;i<=n;i++){
        a[i]^=a[i-1];
        if(b[a[i]^k]==0&&(a[i]^k)!=0) t[i]=-1;
        else t[i]=b[a[i]^k];
        b[a[i]]=i;
    }
    //for(int i=1;i<=n;i++)printf("%d ",a[i]);
    //printf("\n");
    //for(int i=1;i<=n;i++)printf("%d ",t[i]);
    //printf("\n");
    for(int i=1;i<=n;i++){
        if(t[i]==-1) dp[i]=dp[i-1];
        else dp[i]=max(dp[i-1],dp[t[i]]+1);
    }
    //for(int i=1;i<=n;i++)printf("%d ",dp[i]);
    //printf("\n");
    printf("%d\n",dp[n]);
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int T=1;//scanf("%d",&T);
    while(T--) solve();
    return 0;
}

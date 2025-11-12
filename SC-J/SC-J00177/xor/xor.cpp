#include<bits/stdc++.h>
using namespace std;

const int maxn=5e5+10;
int pre[maxn],arr[maxn];
const int maxV=1.1e6+10;
int buck[maxV];
int dp[maxn];
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        pre[i]=pre[i-1]^arr[i];
    }
    for(int i=0;i<maxV;i++) buck[i]=-0x3f3f3f3f;
    int ans=0;
    buck[0]=dp[0]=0;
    for(int i=1;i<=n;i++){
        int res=pre[i]^k;
        dp[i]=max(dp[i-1],buck[res]+1);
        buck[pre[i]]=max(buck[pre[i]],dp[i]);
        ans=max(ans,dp[i]);
    }
    printf("%d\n",ans);
    return 0;
}
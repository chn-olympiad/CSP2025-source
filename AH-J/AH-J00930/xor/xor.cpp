#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum[500005],dp[2200005],ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]^a[i];
    }
    for(int i=1;i<=2200000;i++) dp[i]=-1;
    for(int i=1;i<=n;i++){
        dp[sum[i]]=max(ans,dp[sum[i]^k]+1);
        ans=max(ans,dp[sum[i]]);
    }
    printf("%d",ans);
    return 0;
}

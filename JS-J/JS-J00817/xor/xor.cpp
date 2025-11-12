#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],dp[500005],maxn[1050005];
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]^=a[i-1];
    maxn[0]=1;
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        dp[i]=max(dp[i],maxn[k^a[i]]);
        maxn[a[i]]=max(maxn[a[i]],dp[i]+1);
    }
    printf("%d",dp[n]);
    return 0;
}

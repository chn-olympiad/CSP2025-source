#include<bits/stdc++.h>
using namespace std;
#define N 500005    
unordered_map<int,int> mx;
int n,k,a[N],x[N],dp[N],ans;
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for (int i = 1;i <= n;i++) scanf("%d",a + i);
    for (int i = 1;i <= n;i++) x[i] = x[i - 1] ^ a[i];
    mx[0] = 0;
    for (int i = 1;i <= n;i++){
        dp[i] = dp[i - 1];
        if (mx.count(x[i] ^ k)) dp[i] = max(mx[x[i] ^ k] + 1,dp[i]);
        mx[x[i]] = max(mx[x[i]],dp[i]);
        ans = max(ans,dp[i]);
    }
    printf("%d\n",ans);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500005],s[500005],dp[500005][2],pre[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++){
        scanf("%d",a+i);
        s[i]=s[i-1]^a[i];
        pre[i]=-1;
        for (int j=i;j>=1;j--){
            if ((s[j-1]^s[i])==k){
                pre[i]=j;
                break;
            }
        }
    }
    for (int i=1;i<=n;i++){
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
        if (pre[i]!=-1)dp[i][1]=dp[pre[i]][0]+1;
    }
    cout<<max(dp[n][0],dp[n][1]);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[500002],dp[500002];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,ans=0;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        int t;
        scanf("%d",&t);
        a[i]=t^a[i-1];
    }for(int j=1;j<=n;j++){
        for(int i=0;i<j;i++){
            if((a[i]^a[j])!=k)continue;
            for(int v=0;v<=i;v++)dp[j]=max(dp[j],dp[v]+1);
            ans=max(ans,dp[j]);
        }
    }printf("%d\n",ans);
    return 0;
}
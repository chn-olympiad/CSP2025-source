#include<iostream>
#include<cstdio>
using namespace std;
int a[5010];
int sum[5010];
int dp[5010][5010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]^a[i];
    }
    for(int l=0;l<=n;l++){
        for(int i=1;i<=n-l+1&&i<=n;i++){
            dp[i][i+l]=((sum[i+l]^sum[i-1])==k);
            for(int j=0;j<l;j++){
                    dp[i][i+l]=max(dp[i][i+j]+dp[i+j+1][i+l],dp[i][i+l]);
            }
        }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}
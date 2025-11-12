#include<bits/stdc++.h>
using namespace std;
int n,a[220],b[220],c[220];
int dp[220][110][110][110];
int t;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i],&b[i],&c[i]);
        for(int i=1;i<=n;i++){
            for(int j=0;j<=n/2;j++){
                for(int k=0;k<=n/2;k++){
                    for(int l=0;l<=n/2;l++){
                        dp[i][j][k][l]=dp[i-1][j][k][l];
                        if(j>0) dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j-1][k][l]+a[i]);
                        if(k>0) dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j][k-1][l]+b[i]);
                        if(l>0) dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j][k][l-1]+c[i]);
                    }
                }
            }
        }
        printf("%d\n",dp[n][n/2][n/2][n/2]);
    }
    return 0;
}

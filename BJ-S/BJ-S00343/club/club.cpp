#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int t,a[maxn][5],n,dp[300][205][205],ans=0;//dp[i][j][k]
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        memset(dp,0,sizeof dp);
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        dp[1][1][0]=a[1][1];
        dp[1][0][1]=a[1][2];
        dp[1][0][0]=a[1][3];
        for(int i=2;i<=n;i++){
            for(int j=0;j<=(n/2)&&j<=i;j++){
                for(int k=0;k<=(n/2)&&k<=i;k++){
                    int l=i-j-k;
                    if(l>(n/2)){
                        continue;
                    }
                    if(j>0){
                        dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
                    }
                    if(k>0){
                        dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
                    }
                    if(l>0){
                        dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][3]);
                    }
                    if(i==n) ans=max(ans,dp[i][j][k]);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

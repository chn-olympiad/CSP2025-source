#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[100005][5];
int dp[205][205][205];
void ttt(){
    cin>>n;
    ans=-1e9;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n;k++){
                dp[i][j][k]=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=n/2;j>=0;j--){
            for(int k=n/2;k>=0;k--){
                if(j+k>i) continue;
                if(j>=1) dp[j][k][i-j-k]=max(dp[j][k][i-j-k],dp[j-1][k][i-j-k]+a[i][1]);
                if(k>=1) dp[j][k][i-j-k]=max(dp[j][k][i-j-k],dp[j][k-1][i-j-k]+a[i][2]);
                if(j+k<i) dp[j][k][i-j-k]=max(dp[j][k][i-j-k],dp[j][k][i-j-k-1]+a[i][3]);
            }
        }
    }
    for(int i=0;i<=n/2;i++){
        for(int j=0;j<=n/2;j++){
            if(n-j-i>n/2) continue;
            ans=max(ans,dp[i][j][n-j-i]);
        }
    }
    cout<<ans<<'\n';
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--) ttt();
    return 0;
}

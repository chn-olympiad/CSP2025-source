#include<bits/stdc++.h>
using namespace std;
#define N 222
int t,n;
int a[N][3];
int dp[N][N][N];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        memset(dp,0,sizeof(dp));
        int ans=0;
        for(int s=1;s<=n;s++){
            for(int i=0;i<=min(s,n/2);i++){
                for(int j=0;j<=min(s-i,n/2);j++){
                    if(s-i-j>n/2) continue;
                    if(i>0) dp[s][i][j]=max(dp[s-1][i-1][j]+a[s][0],dp[s][i][j]);
                    if(j>0) dp[s][i][j]=max(dp[s-1][i][j-1]+a[s][1],dp[s][i][j]);
                    if(s-i-j>0) dp[s][i][j]=max(dp[s-1][i][j]+a[s][2],dp[s][i][j]);
                    if(s==n) ans=max(ans,dp[s][i][j]);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
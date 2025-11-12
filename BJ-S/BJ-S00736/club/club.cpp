#include<bits/stdc++.h>
using namespace std;
const int maxn=100002;
int n,t,ans;
int a[maxn][4],dp[maxn][4][4];
void solve(){
    dp[1][1][1]=dp[1][2][1]=dp[1][3][1]=a[1][1];
    dp[1][1][2]=dp[1][2][2]=dp[1][3][2]=a[1][2];
    dp[1][1][3]=dp[1][2][3]=dp[1][3][3]=a[1][3];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            for(int k=1;k<=3;k++){
                dp[i][j][k]=dp[i-1][j][k]+a[i][j];
            }
        }
    }
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
            }
        }
        solve();
        int ans=-1;
        for(int i=1;i<=4;i++){
            for(int j=1;j<=4;j++){
                for(int k=1;k<=4;k++){
                    ans=max(ans,dp[n/2][1][i]+dp[n/2][1][j]+dp[n/2][1][k]);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
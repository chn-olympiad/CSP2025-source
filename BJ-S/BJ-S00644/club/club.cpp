#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
int a[N][5];
long long dp[N][4];
int b[4];
int vis[N];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int ans=0;
        cin>>n;
        int q=n/2;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
            }
        }dp[1][1]=a[1][1],dp[1][2]=a[1][2],dp[1][3]=a[1][3];
        for(int i=2;i<=n;i++){
            dp[i][1]=max(dp[i-1][2]+a[i][1],dp[i-1][3]+a[i][1]);
            dp[i][2]=max(dp[i-1][1]+a[i][2],dp[i-1][3]+a[i][2]);
            dp[i][3]=max(dp[i-1][1]+a[i][3],dp[i-1][2]+a[i][3]);
        }
        cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<'\n';
    }//dp[i][j]=max(dp[i][j-1])
    return 0;
}

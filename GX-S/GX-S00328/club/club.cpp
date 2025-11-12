#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
       int n;
       cin >> n;
       int maxp = n/2;
       int dp[n+1];
       int w[n+1][3];
       int vis[3] = {maxp,maxp,maxp};
       for(int i=1;i<=n;i++){
           cin >> w[i][0] >> w[i][1] >> w[i][2];
       }
       dp[0] = 0;
       for(int i=1;i<=n;i++){
            int f = 0;
            int m;
            m = dp[i-1];
            for(int j=0;j<3;j++){
                if(vis[j] == 0) dp[i] = dp[i-1];
                else dp[i] = max(m,dp[i-1]+w[i][j]);
                if(dp[i] != m) f = j;
                m = dp[i];
            }
            vis[f]--;
       }
       cout << dp[n] << endl;
    }
    return 0;
}

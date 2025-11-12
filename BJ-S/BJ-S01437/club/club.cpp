#include <bits/stdc++.h>
using namespace std;
int dp[202][202][202];
int T,n,a,b,c;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> T;
    while (T--){
        cin >> n;
        //cout << n;
        int Max = 0;
        memset(dp,0,sizeof(dp));
        for (int m = 1;m <= n;m++){
            cin >> a >> b >> c;
            for (int i = 0;i <= n / 2;i++){
                for (int j = 0;j <= n / 2;j++){
                    for (int k = 0;k <= n / 2;k++){
                        if (i + j + k > m) continue;
                        if (i > 0) dp[i][j][k] = max(dp[i - 1][j][k] + a,dp[i][j][k]);
                        if (j > 0) dp[i][j][k] = max(dp[i][j - 1][k] + b,dp[i][j][k]);
                        if (k > 0) dp[i][j][k] = max(dp[i][j][k - 1] + c,dp[i][j][k]);
                        if (dp[i][j][k] > Max) Max = dp[i][j][k];
                    }
                }
            }
        }
        cout << Max << '\n';
    }
    return 0;
}

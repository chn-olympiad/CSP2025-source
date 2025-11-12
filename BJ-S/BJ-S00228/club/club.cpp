#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define ll long long
ll T;
int n;
int a[210][4];
int dp[210][110][110][110];
int ans;
int main(){ 
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T --){
        ans = 0;
        cin >> n;
        memset(dp,0,sizeof(dp));
        for(int i = 1;i <= n;i ++){
            cin >> a[i][1] >> a[i][2] >> a[i][3];
        }
        for(int i = 1;i <= n;i ++){
            for(int j1 = 0;j1 <= min(i,n / 2);j1 ++){
                for(int j2 = 0;j1 + j2 <= min(i,n) && j2 <= n / 2;j2 ++){
                    int j3 = min(i,n) - j1 - j2;
                    if(j3 > n / 2){
                        continue;
                    }
                    dp[i][j1][j2][j3] = max(dp[i][j1][j2][j3],dp[i - 1][j1][j2][j3]);
                    if(j1 != 0){
                        dp[i][j1][j2][j3] = max(dp[i][j1][j2][j3],dp[i - 1][j1 - 1][j2][j3]);
                        dp[i][j1][j2][j3] = max(dp[i][j1][j2][j3],dp[i - 1][j1 - 1][j2][j3] + a[i][1]);
                    }
                    if(j2 != 0){
                        dp[i][j1][j2][j3] = max(dp[i][j1][j2][j3],dp[i - 1][j1][j2 - 1][j3]);
                        dp[i][j1][j2][j3] = max(dp[i][j1][j2][j3],dp[i - 1][j1][j2 - 1][j3] + a[i][2]);
                    }
                    if(j3 != 0){
                        dp[i][j1][j2][j3] = max(dp[i][j1][j2][j3],dp[i - 1][j1][j2][j3 - 1]);
                        dp[i][j1][j2][j3] = max(dp[i][j1][j2][j3],dp[i - 1][j1][j2][j3 - 1] + a[i][3]);
                    }
                }
            }
        }
        for(int i = 0;i <= n / 2;i ++){
            for(int j = 0;i + j <= n && j <= n / 2;j ++){
                ll k = n - i - j;
                if(k <= n / 2){
                    ans = max(ans,dp[n][i][j][k]);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6, M = 205;
int t, n;
int a[N], b[N], c[N];
int dp[M][M][M];

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--){
        int ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i ++){
            cin >> a[i] >> b[i] >> c[i];
        }
        if(n<=200){
        for (int d = 1; d <= n; d ++){
            int x = d;
            //cout << x << endl;
            for (int i = 0; i <= x; i ++){
                for (int j = 0; j <= x-i; j ++){
                    int k = x - i - j;
                    if (i > n/2 || j > n/2 ||k > n/2) continue;
                    if (i == 0){
                        if (j==0){
                            if (k==0){
                                dp[i][j][k] = 0;
                            }
                            else{
                                dp[i][j][k] = dp[i][j][k-1]+c[d];
                            }
                        }
                        else{
                            if (k==0){
                                dp[i][j][k] = dp[i][j-1][k]+b[d];
                            }
                            else{
                                dp[i][j][k] = max(dp[i][j-1][k]+b[d], dp[i][j][k-1]+c[d]);
                            }
                        }
                    }
                    else{
                        if (j==0){
                            if (k==0){
                                dp[i][j][k] = dp[i-1][j][k]+a[d];
                            }
                            else{
                                dp[i][j][k] = max(dp[i-1][j][k]+a[d], dp[i][j][k-1]+c[d]);
                            }
                        }
                        else{
                            if (k==0){
                                dp[i][j][k] = max(dp[i-1][j][k]+a[d], dp[i][j-1][k]+b[d]);
                            }
                            else{
                                dp[i][j][k] = max(dp[i-1][j][k]+a[d], max(dp[i][j-1][k]+b[d], dp[i][j][k-1]+c[d]));
                            }
                        }
                    }
                    ans = max(ans, dp[i][j][k]);
                    //cout << i << ' ' << j << ' ' << k << endl;
                }
            }
        }
        cout << ans << endl;}
        else{
            sort(a, a + n);
            int cnt = n/2;
            for (int i = n; i >= 1; i --){
                ans += a[i];
                cnt --;
                if (cnt == 0) break;
            }
            cout << ans << endl;
        }
    }
    return 0;
}

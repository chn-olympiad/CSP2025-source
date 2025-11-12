#include<bits/stdc++.h>
using namespace std;
long long t, a[100005], b[100005], c[100005], clubA, clubB, clubC, n, dp[101][101][101];
bool flagA = true;
bool flagB = true;
bool cmp(int x, int y) {
    return x > y;
}
long long ans;
void dfs(int x, long long sum) {
    if(x > n) {
        ans = max(ans, sum);
        return;
    }
    if(clubA < n / 2) {
        clubA++;
        dfs(x + 1, sum + a[x]);
        clubA--;
    }
    if(clubB < n / 2) {
        clubB++;
        dfs(x + 1, sum + b[x]);
        clubB--;
    }
    if(clubC < n / 2) {
        clubC++;
        dfs(x + 1, sum + c[x]);
        clubC--;
    }
    return;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--) {
        memset(dp, 0, sizeof(dp));
        flagA = true;
        flagB = true;
        ans = 0;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i] >> c[i];
            if(b[i] != 0) {
                flagA = false;
            }if(c[i] != 0) {
                flagA = false;
                flagB = false;
            }
        }
        if(flagA == true) {
            sort(a + 1, a + 1 + n, cmp);
            for(int i = 1; i <= n / 2; i++) {
                ans += a[i];
            }
            cout << ans << endl;
            continue;
        }
        if(n <= 10) {
            //for(int i = 0; i <= n; i++) {
                //
            //}
            clubA = 0;
            clubB = 0;
            clubC = 0;
            dfs(1, 0);
            cout << ans << endl;
            continue;
        }
        if(n <= 200) {
            for(int i = 0; i <= n / 2; i++) {
                for(int j = 0; j <= n / 2; j++) {
                    for(int k = 0; k <= n / 2; k++) {
                        if(i == 0 && j == 0 && k == 0) continue;
                        if(i != 0) dp[i][j][k] = max(dp[i - 1][j][k] + a[i + j + k], dp[i][j][k]);
                        if(j != 0) dp[i][j][k] = max(dp[i][j - 1][k] + b[i + j + k], dp[i][j][k]);
                        if(k != 0) dp[i][j][k] = max(dp[i][j][k - 1] + c[i + j + k], dp[i][j][k]);
                        if(i + j + k == n) {
                            ans = max(ans, dp[i][j][k]);
                            //break;
                        }
                    }
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}

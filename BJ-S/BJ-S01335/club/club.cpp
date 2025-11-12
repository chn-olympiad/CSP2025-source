#include <bits/stdc++.h>
using namespace std;
struct node {
    int a, b, c;
} d[1000005];
int n, dp[205][105][105], t[100005];
void solve() {
    cin >> n;
    int tot = 0;
    for(int i = 1; i <= n; i++) cin >> d[i].a >> d[i].b >> d[i].c, tot += d[i].c;
    if(n <= 200) {
        for(int i = 1; i <= n; i++) for(int j = 0; j <= n / 2; j++) for(int k = 0; k <= n / 2; k++) dp[i][j][k] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= n / 2; j++) {
                for(int k = 0; k <= n / 2; k++) {
                    if(j) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + d[i].a);
                    if(k) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + d[i].b);
                    if(i - j - k) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + d[i].c);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i <= n / 2; i++) for(int j = 0; j <= n / 2; j++) if(i + j >= n / 2) ans = max(ans, dp[n][i][j]);
        cout << ans << "\n";
    } else if(tot == 0) {
        int ans = 0;
        for(int i = 1; i <= n; i++) ans += d[i].a, t[i] = d[i].b - d[i].a;
        sort(t + 1, t + n + 1);
        for(int i = n; i >= n / 2 + 1; i--) ans += t[i];
        for(int i = 1; i <= n / 2; i++) ans += max(0, t[i]);
        cout << ans << "\n";
    } else {
        int asn = 0;
        for(int i = 1; i <= n; i++) asn += max({d[i].a, d[i].b, d[i].c});
        cout << asn << "\n";
    }
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}

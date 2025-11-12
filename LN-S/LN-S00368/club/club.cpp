#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

struct Info {
    pair<int, int> v[3];
};
int n;
ll dp[205][105][105];
Info a[100005];
bool cmp(Info x, Info y) {
    return x.v[0].first > y.v[0].first;
}
void solve() {
    cin >> n;
    int cnt[3] = {0, 0, 0};
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i].v[j].first;
            a[i].v[j].second = j;
            if (a[i].v[j].first > 0)
                cnt[j]++;
        }
    }
    if (n > 2000 && cnt[1] == 0 && cnt[2] == 0) {
        ll ans = 0;
        sort(a + 1, a + n + 1, cmp);
        for (int i = 1; i <= n / 2; i++)
            ans += a[i].v[0].first;
        cout << ans << '\n';
        return;
    }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n / 2; j++)
            for (int k = 0; k <= n / 2; k++)
                dp[i][j][k] = -1e18;
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= n / 2; j++) {
            if (j > i)
                break;
            for (int k = 0; k <= n / 2; k++) {
                if (k > i)
                    break;
                int l = i - j - k;
                if (l <= n / 2) {
                    for (int d = 0; d < 3; d++) {
                        int lj = j - (a[i].v[d].second == 0), lk = k - (a[i].v[d].second == 1);
                        if (lj >= 0 && lk >= 0 && i - 1 - lj - lk <= n / 2)
                            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][lj][lk] + a[i].v[d].first);
                    }
                }
            }
        }
    ll ans = numeric_limits<ll>::min();
    for (int i = 0; i <= n / 2; i++)
        for (int j = 0; j <= n / 2; j++) {
            int k = n - i - j;
            if (k <= n / 2)
                ans = max(ans, dp[n][i][j]);
        }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}

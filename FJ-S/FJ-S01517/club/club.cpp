#include <bits/stdc++.h>

using std::cin;
using std::cout;

const int N = 100010;

int n, a[N][3], p[N], b[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
    int cnt[3] {};
    int ans = 0, tmp = 0;
    for (int i = 1; i <= n; i++) {
        tmp += std::max({a[i][0], a[i][1], a[i][2]});
        if (a[i][0] > a[i][1] && a[i][0] > a[i][2]) {
            cnt[0]++;
        } else if (a[i][1] > a[i][2]) {
            cnt[1]++;
        } else {
            cnt[2]++;
        }
    }
    if (std::max({cnt[0], cnt[1], cnt[2]}) <= n / 2) ans = tmp;
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= n; j++) {
            b[j] = a[j][i];
            int tmp = 0;
            for (int k = 0; k < 3; k++) if (i != k) tmp = std::max(tmp, a[j][k]);
            b[j] -= tmp;
        }
        std::sort(p + 1, p + n + 1, [&](int x, int y) { return b[x] > b[y]; });
        int tmp = 0;
        for (int j = 1; j <= n / 2; j++) {
            tmp += a[p[j]][i];
        }
        for (int j = n / 2 + 1; j <= n; j++) {
            int tmp2 = 0;
            for (int k = 0; k < 3; k++) if (i != k) tmp2 = std::max(tmp2, a[p[j]][k]);
            tmp += tmp2;
        }
        ans = std::max(ans, tmp);
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
#include <bits/stdc++.h>
#define int long long

using namespace std;

const int NR = 1e5 + 5;

int T, n, m, ans, id, vis[NR], cnt[4], a[NR][4];
vector < int > vec;

inline void solve() {
    cnt[1] = cnt[2] = cnt[3] = id = ans = 0, vec.clear();
    cin >> n, m = n / 2;
    for (int i = 1; i <= n; ++i) cin >> a[i][1] >> a[i][2] >> a[i][3];
    for (int i = 1; i <= n; ++i) {
        int mx = max(a[i][1], max(a[i][2], a[i][3]));
        if (mx == a[i][1]) vis[i] = 1, cnt[1] ++;
        else if (mx == a[i][2]) vis[i] = 2, cnt[2] ++;
        else vis[i] = 3, cnt[3] ++;
        ans += mx;
    }
    if (cnt[1] > m) id = 1;
    else if (cnt[2] > m) id = 2;
    else if (cnt[3] > m) id = 3;
    if (id) {
        for (int i = 1; i <= n; ++i) {
            if (vis[i] != id) continue;
            int mx = -1e18;
            for (int j = 1; j <= 3; ++j)
                if (j != id) mx = max(mx, a[i][j] - a[i][id]);
            vec.push_back(mx);
        }
        sort(vec.begin(), vec.end());
        reverse(vec.begin(), vec.end());
        for (int i = 0; i < cnt[id] - m; ++i) ans += vec[i];
    }
    cout << ans << '\n';
}

signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios :: sync_with_stdio(false), cin.tie(0);
    cin >> T;
    while (T --) solve();
    return 0;
}
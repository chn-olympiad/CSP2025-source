#include <bits/stdc++.h>

void IO(const std::string & s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

using i64 = long long;

int n, m;

void solve() {
    std::cin >> n;

    std::vector<std::array<i64, 3>> a(n + 1);
    std::priority_queue<i64> q[3];
    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i][0] >> a[i][1] >> a[i][2];
        ans += std::max({a[i][0], a[i][1], a[i][2]});
        int id[3];
        id[0] = 0, id[1] = 1, id[2] = 2;
        std::sort(id, id + 3, [&](int x, int y) {
            return a[i][x] > a[i][y];
        });
        q[id[0]].emplace(std::max({a[i][id[1]], a[i][id[2]]}) - a[i][id[0]]);
    }

    m = n / 2;
    while (q[0].size() > m) {
        i64 x = q[0].top();
        q[0].pop();
        ans += x;
    }

    while (q[1].size() > m) {
        i64 x = q[1].top();
        q[1].pop();
        ans += x;
    }
    
    while (q[2].size() > m) {
        i64 x = q[2].top();
        q[2].pop();
        ans += x;
    }

    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    IO("club");

    int T;
    std::cin >> T;

    while (T--) {
        solve();
    }
    return 0;
}
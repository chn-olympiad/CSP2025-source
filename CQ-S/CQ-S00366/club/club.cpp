// Author: lzm0107

// 15:03, expect 100

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using aii = array<int, 2>;
using ull = unsigned long long;

const int N = 1e5;

int n, a[N + 10][3];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    int cnt[3] = {0, 0, 0};
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int tmp = max({a[i][0], a[i][1], a[i][2]});
        ans += tmp;
        if (tmp == a[i][0]) {
            ++cnt[0];
        } else if (tmp == a[i][1]) {
            ++cnt[1];
        } else {
            ++cnt[2];
        }
    }
    if (cnt[0] <= n / 2 && cnt[1] <= n / 2 && cnt[2] <= n / 2) {
        cout << ans << '\n';
        return ;
    }
    int out_id;
    if (cnt[0] > n / 2) {
        out_id = 0;
    } else if (cnt[1] > n / 2) {
        out_id = 1;
    } else {
        out_id = 2;
    }
    vector<int> cost;
    for (int i = 1; i <= n; ++i) {
        int dicision, tmp = max({a[i][0], a[i][1], a[i][2]});
        if (tmp == a[i][0]) {
            dicision = 0;
        } else if (tmp == a[i][1]) {
            dicision = 1;
        } else {
            dicision = 2;
        }
        if (dicision == out_id) {
            int second = 0;
            for (int j = 0; j < 3; ++j) {
                if (j != out_id) {
                    second = max(second, a[i][j]);
                }
            }
            cost.push_back(tmp - second);
        }
    }
    sort(cost.begin(), cost.end());
    for (int i = cnt[out_id]; i > n / 2; --i) {
        ans -= cost[cnt[out_id] - i];
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
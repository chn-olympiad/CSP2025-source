#include<bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 3>> a(n + 1);
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }

    array<int, 3> cnt{};
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int p = (int)distance(a[i].begin(), max_element(a[i].begin(), a[i].end()));
        cnt[p]++, ans += a[i][p];
    }

    int p = (int)distance(cnt.begin(), max_element(cnt.begin(), cnt.end()));
    if(cnt[p] <= n / 2) {
        cout << ans << '\n';
        return;
    }

    auto val = [&](int i) {
        int mx = 0;
        for(int j = 0; j < 3; j++) {
            if(j != p) {
                mx = max(mx, a[i][j]);
            }
        }
        return mx - a[i][p];
    };

    vector<int> b(n + 1);
    for(int i = 1; i <= n; i++) {
        b[i] = val(i);
    }

    sort(b.begin() + 1, b.end(), greater<int>());
    for(int i = 1, j = 1; i <= n && j <= cnt[p] - n / 2; i++) {
        if(b[i] <= 0) {
            ans += b[i], j++;
        }
    }

    cout << ans << '\n';
}

int main() {
#ifndef LOCAL
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
#endif
    cin.tie(nullptr) -> ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
// 14:55
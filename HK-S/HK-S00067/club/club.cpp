#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> a(n);
    vector<int> c(3, 0);
    int h = n / 2, ans = 0;
    vector<pair<int, int>> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            int x;
            cin >> x;
            a[i].push_back({x, j});
        }   
        sort(a[i].rbegin(), a[i].rend());
        c[a[i][0].second]++, ans += a[i][0].first;
    }
    int id = 0;
    if (c[0] > h) id = 0;
    if (c[1] > h) id = 1;
    if (c[2] > h) id = 2;
    for (int i = 0; i < n; i++) {
        if (a[i][0].second == id) {
            d.push_back({a[i][0].first - a[i][1].first, i});
        }
    }
    sort(d.begin(), d.end());
    for (int i = 0; i < c[id] - h; i++) {
        ans -= d[i].first;
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) solve();
}
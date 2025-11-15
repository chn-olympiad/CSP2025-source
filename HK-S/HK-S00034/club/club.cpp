#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9+7, inf = 1e18;
void solve() {
    int n, res = 0;
    cin >> n;
    int mx = n/2;
    vector<int> a(n), b(n), c(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> x, y, z;
    for (int i=0; i<n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        if ((a[i] >= b[i]) && a[i] >= c[i]) x.push({a[i]-max(b[i], c[i]), i});
        else if ((b[i] >= a[i]) && (b[i] >= c[i])) y.push({b[i]-max(a[i], c[i]), i});
        else if ((c[i] >= a[i]) && (c[i] >= b[i])) z.push({c[i]-max(a[i], b[i]), i});
    }
    while (x.size() > mx) {
        int u = x.top().first, v = x.top().second;
        if (b[v] >= c[v]) y.push(make_pair(inf, v));
        else z.push(make_pair(inf, v));
        x.pop();
    }
    while (y.size() > mx) {
        int u = y.top().first, v = y.top().second;
        if (a[v] >= c[v]) x.push(make_pair(inf, v));
        else z.push(make_pair(inf, v));
        y.pop();
    }
    while (z.size() > mx) {
        int u = z.top().first, v = z.top().second;
        if (a[v] >= b[v]) x.push(make_pair(inf, v));
        else y.push(make_pair(inf, v));
        z.pop();
    }
    while (!x.empty()) {
        res += a[x.top().second];
        x.pop();
    }
    while (!y.empty()) {
        res += b[y.top().second];
        y.pop();
    }
    while (!z.empty()) {
        res += c[z.top().second];
        z.pop();
    }
    cout << res << '\n';
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    auto frt = freopen("club.in", "r", stdin);
    auto frt2 = freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
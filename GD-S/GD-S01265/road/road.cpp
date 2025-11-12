#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 5;
int n, m, k;
namespace Sol1 {
    vector <tuple <int, int, int>> edg;
    int f[N]; int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
    bool merge(int x, int y) { return (x = find(x)) != (y = find(y)) ? (f[x] = y, true) : false; }
    int solve() {
        for (int i = 1, x, y, z; i <= m; i++) {
            cin >> x >> y >> z;
            edg.push_back({z, x, y});
        } sort(edg.begin(), edg.end()); int ans = 0;
        for (int i = 1; i <= n; i++) f[i] = i;
        for (auto [z, x, y] : edg) if (merge(x, y)) ans += z;
        cout << ans; return 0;
    }
}

signed main() {
    freopen("road.in", "r", stdin); freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m >> k;
    if (k == 0) return Sol1::solve();
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ull unsigned long long
#define uint unsigned int

#define endl "\n"
#define all(x) x.begin(), x.end()
#define all1(x) x.begin() + 1, x.end()

#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

// #define x first
// #define y second

const int inf = 2e9;
const ll INF = 2e18;
const int mod = 1e9 + 7;
const db eps = 1e-6;
const int maxn = 1e5 + 5;
const int N = 1e7 + 7;

void solve() {
    struct Node {
        int u, v, w;
    } ;

    int n, m, k; cin >> n >> m >> k;
    vector<Node> E(m);
    vector<int> fa(n + 1), siz(n + 1, 1);
    iota(all(fa), 0);

    auto find = [&](auto &&self, int x) -> int {
        if (fa[x] != x) fa[x] = self(self, fa[x]);
        return fa[x];
    } ;

    auto merge = [&](auto u, auto v) -> void {
        u = find(find, u), v = find(find, v);
        if (siz[u] < siz[v]) swap(u, v);
        fa[v] = u;
    } ;

    auto query = [&](auto u, auto v) -> bool {
        u = find(find, u), v = find(find, v);
        if (u == v) return 1;
        return 0;
    } ;

    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        E[i].u = u, E[i].v = v, E[i].w = w;
    }

    sort(all(E), [&](auto &x, auto &y) {
        return x.w < y.w;
    }) ;

    int cnt = 0;
    ll ans = 0;
    vector<set<pii>> edges(n + 1);
    for (int i = 0; i < m; i++) {
        int u = E[i].u, v = E[i].v, w = E[i].w;
        if (!query(u, v)) {
            edges[u].insert({v, w});
            edges[v].insert({u, w});
            ans += w;
            cnt += 1;
            merge(u, v);
        }
        if (cnt == n - 1) break;
    }

    cout << ans << endl;
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}

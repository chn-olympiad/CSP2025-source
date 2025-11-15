#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pll pair<int, int>
#define vll vector<int>
#define all(x) (x).begin(), (x).end()
#define fpb push_back

struct EDGE {
    int u, v, w;
};
vector<EDGE> edge;
bool cmp(EDGE a, EDGE b) {
    return a.w < b.w;
}
const int N = 1e4 + 5;
int fa[N], n, m, k, cnt, ans;
int root(int u) {
    if (u == fa[u]) return u;
    return fa[u] = root(fa[u]);
}
void unite(int u, int v) {
    u = root(u), v = root(v);
    fa[u] = root(fa[v]);
}

void solve() {
    // Tests 1-4 (16 marks) (k == 0)
    cin >> n >> m >> k;
    if (k != 0) return;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge.fpb({u, v, w});
    }
    sort(all(edge), cmp);
    for (auto &u : edge) {
        // cout << "###\n";
        // for (int i = 1; i <= n; i++) cout << root(i) << ' ';
        // cout << "###\n";
        if (root(u.u) != root(u.v)) {
            // cout << "OPERATION UNITE\n";
            // cout << u.u << ' ' << u.v << '\n';
            // cout << root(u.u) << ' ' << root(u.v) << '\n';
            unite(u.u, u.v);
            // cout << root(u.u) << ' ' << root(u.v) << '\n';
            cnt++;
            ans += u.w;
        }else {
            // cout << "FAILED\n";
            // cout << u.u << ' ' << u.v << '\n';
            // cout << root(u.u) << ' ' << root(u.v) << '\n';
        }
        if (cnt == n - 1) break;
    }
    cout << ans << '\n';
}


signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); int t1 = 1;
    // cin >> t1; // remove if 1 case
    while (t1--) solve();
}

// i forgot MST...
// iirc need to use DSU
// i also forgot how to write DSU...
// too poorjar
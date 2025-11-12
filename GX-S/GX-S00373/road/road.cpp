#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int maxn = 1e4 + 20;
struct node {
    ll u, v, w;
    friend bool operator<(const node &a, const node &b) {
        return a.w < b.w;
    }
};
vector<node> q;
int fa[maxn], vis[maxn], C[maxn];
int n, m, k;
int ptcnt = 0;

int get(int x) {
    if (x == fa[x])
        return x;
    return fa[x] = get(fa[x]);
}

void merge(int x, int y) {
    if (get(x) != get(y))
        fa[get(x)] = get(y);
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    // double st = clock();
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i ++) {
        ll u, v, w; cin >> u >> v >> w;
        q.push_back({u, v, w});
    }
    for (int i = 1; i <= k; i ++) {
        ll cur = n + i;
        ll c; cin >> c;
        C[cur] = c;
        for (int j = 1; j <= n; j ++) {
            ll a; cin >> a;
            q.push_back({cur, j, a + c});
        }
    }
    // n = n + k;
    for (int i = 1; i <= n + k; i ++) fa[i] = i;
    ll ans = 0;
    sort(q.begin(), q.end());
    for (node cur : q) {
        ll u = cur.u, v = cur.v, w = cur.w;
        if (get(u) != get(v) && ptcnt < n) {
            merge(u, v), ans += w;
            // printf("%lld->%lld, val:%lld\n", u, v, w);
            if (u <= n && vis[u] == 0) ptcnt ++, vis[u] = 1;
            if (v <= n && vis[v] == 0) ptcnt ++, vis[v] = 1;
            if (u > n) {
                if (vis[u] == 0) ans -= C[u];
                vis[u] = 1;
            }
            if (v > n) {
                if (vis[v] == 0) ans -= C[v];
                vis[v] = 1;
            }
        }
    }
    cout << ans << '\n';
    // cout << clock() - st << "ms\n";
    return 0;
}
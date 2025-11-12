#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
struct edge {
    int u2, v2, w2;
} h[N];
int l;
long long n, m, k, u1, v1, w1, ans, cnt;
int c[15], a[15][N];
bool vis[N + 15];
bool cmp (edge x, edge y) {
    return x.w2 < y.w2;
}
void kru () {
    sort (h + 1, h + 1 + l, cmp);
    for (int i = 1; i <= l; i++) {
        int u = h[i].u2, v = h[i].v2;
        bool f = true;
        if (u > v) swap (u, v);
        if (u <= n) {
            if (!vis[u]) {
                ++ cnt;
                vis[u] = true;
                f = true;
            }
        }
        if (v <= n) {
            if (!vis[v]) {
                ++ cnt;
                vis[v] = true;
                f = true;
            }
        }
        if (f) {
            ans += h[i].w2;
            if (v > n) {
                if (vis[v]) {
                    ans -= c[v - n];
                } else {
                    vis[v] = true;
                }
            }
        }
        if (cnt >= n) break;
    }
}
int main () {
    freopen ("road.in", "r", stdin);
    freopen ("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie (0), cout.tie (0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> u1 >> v1 >> w1;
        ++ l;
        h[l] = (edge) {u1, v1, w1};
    }
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            ++ l;
            h[l] = (edge) {n + i, j, c[i] + a[i][j]};
        }
    }
    kru ();
    cout << ans << "\n";
    return 0;
}

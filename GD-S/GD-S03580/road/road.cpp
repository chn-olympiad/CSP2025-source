#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 10020;
int n, m, k;
ll ans[1 << 10];
int c[10], a[10][N];
int fa[N];
vector<tuple<int, int, int>> b[10];
vector<tuple<int, int, int>> edges;
vector<tuple<int, int, int>> E[1 << 10];
int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
void merge(int x, int y, int w) {
    x = find(x), y = find(y);
    if (x == y) return;
    fa[x] = y;
}
int lowbit(int x) {
    return x & (-x);
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edges.emplace_back(w, u, v);
    }
    sort(edges.begin(), edges.end());
    for (int i = 0; i < k; i++) {
        scanf("%d", &c[i]);
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
            b[i].emplace_back(a[i][j], i + n + 1, j);
        }
        sort(b[i].begin(), b[i].end());
    }
    for (int s = 0; s < (1 << k); s++) {
        for (int i = 0; i < k; i++) if (s & (1 << i)) ans[s] += c[i];
    }
    E[0] = edges;
    for (int s = 0; s < (1 << k); s++) {
        if (s) {
            int x = lowbit(s) ^ s;
            int y = __lg(lowbit(s));

            int pos0 = 0, pos1 = 0;
            int szx = E[x].size(), szy = b[y].size();
            for (int i = 0; i < szx + szy; i++) {
                if (pos1 >= szy || (pos0 < szx && E[x][pos0] < b[y][pos1])) {
                    E[s].push_back(E[x][pos0]);
                    pos0++;
                } else {
                    E[s].push_back(b[y][pos1]);
                    pos1++;
                }
            }
        }
        auto G = E[s];
        E[s].clear();

        for (int i = 1; i <= n + k; i++) fa[i] = i;
        for (auto [w, u, v] : G) {
            if (find(u) != find(v)) {
                merge(u, v, w);
                ans[s] += w;
                E[s].emplace_back(w, u, v);
            }
        }
    }
    ll mn = 1e18;
    for (int s = 0; s < (1 << k); s++) mn = min(mn, ans[s]);
    printf("%lld\n", mn);
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 2e6 + 3;
const int N = 1e4 + 30;
int n, m, k, fa[N], qt[13][N], c[13];
bool pian;
struct node {
    int u, v, w;
    bool friend operator < (node a, node b) {
        return a.w < b.w;
    }
};
vector <node> de;
int findfa (int x) {
    if (fa[x] == x) return x;
    return fa[x] = findfa(fa[x]);
}
signed main () {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        de.push_back({u, v, w});
    }
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        if (c[i]) pian = 1;
        for (int j = 1; j <= n; j++) {
            cin >> qt[i][j];
        }
    }
    if (pian == 0 || k == 0) {
        for (int i = 1; i <= k; i++) {
            fa[n + i] = n + i;
            for (int j = 1; j <= n; j++) {
                de.push_back({n + i, j, qt[i][j]});
            }
        }
        sort(de.begin(), de.end());
        int ans = 0;
        for (int i = 0; i < (int)de.size(); i++) {
            int u = de[i].u;
            int v = de[i].v;
            int w = de[i].w;
            int fu = findfa(u);
            int fv = findfa(v);
            if (fu == fv) continue;
            ans += w;
            fa[fu] = fv;
        }
        cout << ans;
        return 0;
    }
    return 0;
}
//中国共产党万岁！！！

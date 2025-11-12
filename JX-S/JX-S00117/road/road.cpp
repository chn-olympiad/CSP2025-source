#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXM = 1e6+5;
const int MAXN = 1e4+5;
struct Edge{
    int u, v, w, rdc;
}e[MAXM << 2];
bool cmp(Edge x, Edge y) {
    return x.w < y.w;
}
int n, m, m_, k, fa[MAXN], res;
int c[105], a[105][MAXN], crd[105];
int find(int x) {
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k; m_ = m;
    for(int i = 1; i <= m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
        e[i].rdc = 0;
    }
    for(int i = 1; i <= k; i++) {
        cin >> c[i]; int mp = 0, mct = INT_MAX;
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if(a[i][j] < mct) mp = j, mct = a[i][j];
        } c[i] += mct;
        for(int j = 1; j <= n; j++) {
            if(j == mp) continue;
            e[++m_].u = mp; e[m_].v = j;
            e[m_].w = a[i][j] + c[i];
            e[m_].rdc = i;
        }
    } sort(e+1, e+m_+1, cmp);
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1; i <= m_; i++) {
        if(find(e[i].u) != find(e[i].v)) {
            res += e[i].w;
            fa[fa[e[i].u]] = find(e[i].v);
            if(crd[e[i].rdc] == 1) res -= c[e[i].rdc];
            crd[e[i].rdc] = 1;
        }
    } cout << res << endl;
}
//bet king desuwa

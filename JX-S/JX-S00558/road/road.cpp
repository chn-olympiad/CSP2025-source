#include <bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int, int>;
struct edge{
    int u, v, w;
    bool operator<(const edge & o) const {
        return w < o.w;
    }
} e[1000005], e1[100005];
int n, m, k, w[1000005], c[15], a[15][10005], vis[15], fa[10005], sz[10005], ans = 1e18;
int ff(int x){
    if (fa[x] == x) return x;
    return fa[x] = ff(fa[x]);
}
void mm(int x, int y){
    int fx = ff(x), fy = ff(y);
    if (fx == fy) return;
    if (sz[fx] > sz[fy]) sz[fx] += fy, fa[fy] = fx;
    else sz[fy] += fx, fa[fx] = fy;
}
int kruskal(){
    for (int i = 1; i <= n; i++) fa[i] = i, sz[i] = 1;
    for (int i = 1; i <= m; i++) e1[i] = e[i];
    sort(e + 1, e + m + 1);
    int cnt = 0, sm = 0;
    for (int i = 1; i <= m; i++){
        if (ff(e[i].u) != ff(e[i].v)){
            mm(e[i].u, e[i].v);
            cnt++;
            sm += e[i].w;
            if (cnt == n - 1) return sm;
        }
    }
    return -1;
}
signed main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++){
        cin >> e[i].u >> e[i].v >> w[i];
    }
    for (int i = 1; i <= k; i++){
        cin >> c[i];
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    }
    for (int s = 0; s < (1 << k); s++){
        int tmp = s, sum = 0;
        for (int i = 1; i <= k; i++) vis[i] = 0;
        for (int i = 1; i <= k; i++){
            if (tmp % 2) vis[i] = 1, sum += c[i];
            tmp /= 2;
        }
        for (int i = 1; i <= m; i++){
            e[i].w = w[i];
            for (int j = 1; j <= k; j++) if (vis[j]) e[i].w = min(e[i].w, a[j][e[i].u] + a[j][e[i].v]);
        }
        int sss = kruskal();
        ans = min(ans, sss + sum);
        for (int i = 1; i <= m; i++) e[i] = e1[i];
    }
    cout << ans;
    return 0;
}

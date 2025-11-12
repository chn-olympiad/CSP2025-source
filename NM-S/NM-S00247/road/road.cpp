#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e4+5, MAXM = 2e6+5;
struct ed{
    int u, v;
    ll w;
    bool operator< (const ed& e){
        return w < e.w;
    }
}edge[MAXM];
int fa[MAXN];
ll c[20], a[20][MAXN];
int find(int x){
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
int n, m, k, cnt = 0;
ll kruskal(){
    ll ans = 0;
    int tot = n;
    sort(edge + 1, edge + 1 + cnt);
    for (int i = 1; i <= cnt; ++i){
        int u = edge[i].u, v = edge[i].v;
        int fu = find(u), fv = find(v);
        if (fu == fv) continue;
        else {
            --tot;
            ans += edge[i].w;
            fa[fu] = fv;
        }
        if (tot == 1) break;
    }
    return ans;
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    //freopen("road3.in", "r", stdin);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) fa[i] = i;
    for (int i = 1; i <= m; ++i)
        scanf("%d%d%lld", &edge[i].u, &edge[i].v, &edge[i].w);
    cnt = m;
    for (int i = 1; i <= k; ++i){
        int p = 0;
        scanf("%d", &c[i]);
        for (int j = 1; j <= n; ++j){
            scanf("%lld", &a[i][j]);
            if (a[i][j] == 0) p = j;
        }
        if (p){
            for (int v = 1; v <= n; ++v){
                if (v == p) continue;
                edge[++cnt] = {p, v, a[i][v]};
            }
        }
    }
    ll ans = kruskal();
    printf("%lld\n", ans);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e4 + 10, M = 2e6 + 10, K = 15;
const ll INF = 1e17;
int n, m, k, fa[N], c[K], a[K][N], idx;
ll ans = INF;
struct E{
    int u, v, w;
}e[M], us[M], fi[M];
int find(int x){
    if(fa[x] != x)fa[x] = find(fa[x]);
    return fa[x];
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i ++){
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    sort(e + 1, e + 1 + m, [](auto a, auto b){
        return a.w < b.w;
    });
    for(int i = 1; i <= k; i ++){
        cin >> c[i];
        for(int j = 1; j <= n; j ++)cin >> a[i][j];
    }
    for(int i = 1; i <= n; i ++)fa[i] = i;
    for(int i = 1; i <= m; i ++){
        int u = e[i].u, v = e[i].v;
        if(find(u) == find(v))continue;
        us[++ idx] = e[i];
        fa[find(u)] = find(v);
    }
    for(int i = 0; i < (1 << k); i ++){
        for(int j = 1; j <= n + k; j ++)fa[j] = j;
        int cnt = 0;
        ll res = 0;
        for(int j = 0; j < k; j ++){
            if((i >> j) & 1){
                res += c[j + 1];
                for(int o = 1; o <= n; o ++)fi[++ cnt] = {j + n + 1, o, a[j + 1][o]};
            }
        }
        for(int j = 1; j <= idx; j ++)fi[++ cnt] = us[j];
        sort(fi + 1, fi + 1 + cnt, [](auto a, auto b){
            return a.w < b.w;
        });
        for(int j = 1; j <= cnt; j ++){
            int u = fi[j].u, v = fi[j].v, w = fi[j].w;
            if(find(u) == find(v))continue;
            res += w;
            fa[find(u)] = find(v);
        }
        ans = min(ans, res);
    }
    cout << ans;
    return 0;
}
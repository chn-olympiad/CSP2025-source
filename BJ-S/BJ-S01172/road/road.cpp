#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, m, k, fa[N], sz[N], e[15][N], ans = 0;
struct Edge{
    int u, v, w;
    bool operator< (const Edge o) const{
        return w <o.w;
    }
}g[N];
int f(int x){
    return fa[x] == x ? x : fa[x] = f(fa[x]);
}
void mg(int x, int y){
    if(x != y){
        if(sz[x] > sz[y]) swap(x, y);
        x = f(x);
        y = f(y);
        fa[x] = y;
    }
}

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >>n >>m >> k;
    for(int i = 1; i <= m; i++){
        cin >> g[i].u >> g[i].v >> g[i].w;
    }
    for(int i = 1; i <= k; i++) {
        cin >>e[i][0];
        for(int j = 1; j <= n; j++) cin >> e[i][j];
    }
    sort(g + 1, g + m +1);
    for(int i = 1; i <= n; i++) fa[i] = i, sz[i] = 0;
    for(int i = 1; i <= m; i++){
        int u = g[i].u;
        int v = g[i].v;
        int w = g[i].w;
        //cout << u << " " << v <<endl;
        if(f(u) != f(v)) mg(u, v), ans += w;
    }
    cout << ans;
}

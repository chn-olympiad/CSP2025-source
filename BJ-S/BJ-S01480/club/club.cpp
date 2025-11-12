#include <bits/stdc++.h>
using namespace std;
struct edge {
    int u, v, w;
};
struct node {
    int v, w;
};
int n, m, k;
edge g[10005];
vector<node> town[15];
int changetown[15];
bool vis[10005];
int fa[10005];
void init() {
    for(int i = 0; i < n; i++) {
        fa[i] = i;
    }
}
int get(int x) {
    if(fa[x] == x) return x;
    return get(fa[x]);
}
bool cmp(edge x, edge y) {
    if(x.w != y.w) {
        return x.w < y.w;
    }
    return changetown[x.u] + town[x.u][x.v].w < y.w;
}
int kruscal() {
    int sum = 0;
    sort(g, g + m, cmp);
    for(int i = 0; i < m; i++) {
        int x = g[i].u, y = g[i].v, w = g[i].w;
        int tx = -1;
        if(x <= k) tx = changetown[x] + town[x][y].w;
        x = get(x);
        y = get(y);
        if(x != y && tx == -1) {
            fa[x] = y;
            sum += w;
        } else if(x != y && tx != -1) {
            int minn = min(tx, w);
            sum += minn;
            fa[x] = y;
        }
    }
    return sum;
}
int main() {
    //Oh, shit!
    
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    init();
    cin >> n >> m >> k;
    int u, v, w;
    int city[10005];
    int idx = 0;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        city[i] = u;
        city[i + 1] = v;
        idx += 2;
        g[i] = {u, v, w};
    }
    unique(city, city + idx);
    for(int j = 0; j < k; j++) {
        int c;
        cin >> c;
        changetown[j] = c;
        for(int i = 0; i < n; i++) {
            int cost;
            cin >> cost;
            town[j].push_back({city[i], cost});
            town[city[i]].push_back({j, cost});
        }
    }
    cout << kruscal();
    return 0;
}
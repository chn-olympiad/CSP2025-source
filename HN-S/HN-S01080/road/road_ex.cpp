#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
using namespace std;

const int N = 2e4 + 5;
const int M = 2e6 + 5;
int n, m, k, u, v, w, cnt, tot, c[N], deg[N], col[N], val[N], Val[N], a[15][N];
bool vis[N];
map<pi, int> mp;
struct Node {
    int u, v, w;
} e[M], g[M];

namespace Union_Find_Set {
    int fa[N];

    inline void init() {
        for(int i = 1 ; i < N ; ++ i)
            fa[i] = i;

        return ;
    }

    inline int find(int x) {
        if(x != fa[x]) fa[x] = find(fa[x]);

        return fa[x];
    }

    inline void merge(int x, int y) {
        x = find(x), y = find(y);

        if(x == y) return ;

        fa[y] = x;

        return ;
    }
}

using namespace Union_Find_Set;

inline void kruskal() {
    sort(g + 1, g + 1 + m, [&](Node a, Node b) {
        return a.w < b.w;
    });

    init();

    int num = 0, res = 0;

    for(int i = 1 ; i <= cnt ; ++ i) {
        u = find(g[i].u), v = find(g[i].v), w = g[i].w;

        if(u == v) continue ;

        ++ num;
        res += w;
        merge(u, v);
        Mp[{u, v}] = w;
        if(num == n - 1) break ;
    }
    
    sort(e + 1, e + 1 + cnt, [&](Node a, Node b) {
        return a.w < b.w;
    });

    init();

    int num = 0, res = 0;

    for(int i = 1 ; i <= cnt ; ++ i) {
        u = find(e[i].u), v = find(e[i].v), w = e[i].w;

        if(u == v) continue ;

        ++ num;
        res += w;
        merge(u, v);
        mp[{u, v}] = w;
        ++ deg[u], ++ deg[v];
        if(num == tot - 1) break ;
    }

    for(int i = n + 1 ; i <= tot ; i += 2) {
        if(deg[i] == 1 && deg[i + 1] == 2) vis[i] = vis[i + 1] = true;
        else if(deg[i] == 2 && deg[i + 1] == 1) vis[i] = vis[i + 1] = true;
    }

    for(auto i : mp) {
        auto p = i.first;
        int x = p.first, y = p.second, w = i.second;

        if(vis[x] || vis[y]) res -= w;
    }

    int tmp = 0;
    vector<int> vec[N];

    for(int i = n + 1 ; i <= tot ; i += 2)
        col[i] = col[i + 1] = ++ tmp;

    for(auto i : mp) {
        auto p = i.first;
        int x = p.first, y = p.second, w = i.second;

        if(col[x] || col[y]) {
            int Col = (col[x] == 0) ? col[y] : col[x]; 

            val[Col] += w;
            vec[Col].pb(x), vec[Col].pb(y);
        }
    }

    for(int i = 1 ; i <= tmp ; ++ i)
        for(auto j : vec[i])
            

    cout << res;

    return ;
}

signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    ios_base :: sync_with_stdio(NULL);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    for(int i = 1 ; i <= m ; ++ i) {
        cin >> u >> v >> w;

        e[i] = {u, v, w};
    }

    tot = n, cnt = m;

    for(int i = 1 ; i <= k ; ++ i) {
        cin >> c[i];

        tot += 2;

        e[++ cnt] = {tot - 1, tot, c[i]};

        for(int j = 1 ; j <= n ; ++ j) {
            cin >> a[i][j];

            e[++ cnt] = {tot, j, a[i][j]};
            e[++ cnt] = {tot - 1, j, a[i][j]};
        }
    }

    kruskal();

    return 0;
}
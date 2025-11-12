#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e4 + 5;
int n, m, k, c[maxn], a[maxn][maxn];
struct Node { int v, w; };
struct Edge {int u, v, w;};
vector <Node> G[maxn];

inline int r() {
    int x=0, f=1;char ch=getchar();
    while (ch < '0' || ch > '9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch >= '0' && ch <= '9') {x = x*10+ch-'0'; ch=getchar();}
    return x*f;
}

struct DSU {
    int fa[maxn + 15];
    void init(int n) {for (int i = 1;i <= n;i++) fa[i] = i;}
    int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return 0;
        fa[x] = y;
        return 1;
    }
}dsu;

bool cmp(Edge x, Edge y) {
    return x.w < y.w;
}

int kruskal()
{
    int ans = 0, cnt = 0;
    vector <Edge> edges;
    for (int u = 1;u <= n + k;u++) {
        for (auto e : G[u]) {
            int v = e.v, w = e.w;
            edges.push_back({u, v, w});
        }
    }
    dsu.init(n + k);
    sort(edges.begin(), edges.end(), cmp);
    for (auto e : edges) {
        int u = e.u, v = e.v, w = e.w;
        if (dsu.find(u) != dsu.find(v)) {
            dsu.merge(u, v);
            ans += w;
            cnt++;
            if (cnt == n + k - 1) break;
        }
    }
    return ans;
}


signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    n = r(), m = r(), k = r();
    for (int i = 1;i <= m;i++) {
        int u = r(), v = r(), w = r();
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    for (int i = 1;i <= k;i++) {
        c[i] = r();
        for (int j = 1;j <= n;j++) {
            a[i][j] = r();
            G[i + n].push_back({j, a[i][j]});
            G[j].push_back({i + n, a[i][j]});
        }
    }
    cout << kruskal();
    return 0;
}







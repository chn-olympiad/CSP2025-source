#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 1e4 + 5;
const int K = 15;

struct Edge {
    int u, v;
    LL w;
    int build;

    Edge(int _u, int _v, LL _w, int _build) {
        u = _u, v = _v, w = _w, build = _build;
    }

    friend bool operator < (Edge a, Edge b) {
        return a.w < b.w;
    }
};

int n, m, k;
LL dis[N][N];
int build[N][N];
LL base[K], cost[N];
vector <Edge> edges;
int bin[N];
bool vis[K];
LL ans;

void bemin(LL &a, LL b) {
    a = a < b ? a : b;
}

int root(int x) {
    if (bin[x] == x)
        return x;
    
    return bin[x] = root(bin[x]);
}

void inp() {
    scanf("%d%d%d", &n, &m, &k);
    memset(dis, 0x3f, sizeof dis);

    while (m -- ) {
        int u, v;
        LL w;
        scanf("%d%d%lld", &u, &v, &w);
        bemin(dis[u][v], w);
    }

    for (int t = 1; t <= k; t ++ ) {
        scanf("%lld", &base[t]);

        for (int i = 1; i <= n; i ++ )
            scanf("%lld", &cost[i]);
        
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ )
                if (dis[i][j] > base[t] + cost[i] + cost[j]) {
                    dis[i][j] = base[t] + cost[i] + cost[j];
                    build[i][j] = t;
                }
    }
}

void work() {
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            if (i != j)
                edges.push_back(Edge(i, j, dis[i][j], build[i][j]));
    
    sort(edges.begin(), edges.end());

    for (int i = 1; i <= n; i ++ )
        bin[i] = i;
    
    int cnt = 0;

    for (auto item : edges) {
        int u = root(item.u);
        int v = root(item.v);
        LL w = item.w;

        if (u != v) {
            bin[v] = u;
            ans += w;
            cnt ++ ;

            if (vis[item.build])
                ans -= base[item.build];
            
            vis[item.build] = true;

            if (cnt == n - 1)
                break;
        }
    }

    printf("%lld\n", ans);
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    inp();
    work();

    fclose(stdin);
    fclose(stdout);

    return 0;
}
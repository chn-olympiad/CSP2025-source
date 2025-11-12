#include <cstdio>
#include <queue>

#define int long long

using namespace std;

const int N = 1e4 + 10;
const int M = 1e6 + 50;

int n, m, k;
int g[15][N];
int c[15], p[N];

struct node {
    long long c;
    int a, b;
    bool operator>(const node& x) const {
        return c > x.c;
    }
};

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    scanf("%lld%lld%lld", &n, &m, &k);

    priority_queue<node, vector<node>, greater<node>> pq;
    for (int i = 1; i <= m; i ++ ) {
        int u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        pq.push({w, u, v});
    }

    for (int i = 1; i <= k; i ++ ) {
        scanf("%lld", &c[i]);
        for (int j = 1; j <= n; j ++ )
            scanf("%lld", &g[i][j]);
    }
    for (int i = 1; i < n; i ++ ) {
        for (int v = i + 1; v <= n; v ++ )
            for (int j = 1; j <= k; j ++ ) {
                long long dist = g[j][i] + g[j][v] + c[j];
                pq.push({dist, i, v});
                pq.push({dist, v, i});
            }
    }

    // 最小生成树
    long long res = 0;
    for (int i = 1; i <= n; i ++ ) p[i] = i;
    int cnt = 0;
    while (cnt != n - 1) {
        auto t = pq.top();
        pq.pop();
        int u = t.a, v = t.b;
        long long dist = t.c;
        int pa = find(u), pb = find(v);
        if (pa != pb) {
            res += dist;
            p[u] = pb;
            cnt ++ ;
        }
    }
    

    printf("%lld\n", res);
    
    return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
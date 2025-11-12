#include <bits/stdc++.h>

using namespace std;

const int N = 1000100;

struct Node {
    int u, v, w;
    bool operator < (const Node &a) const {
        return w < a.w;
    }
};

vector <Node> g;

int n, m, k;
int fa[N];
int vis[N];

int find (int x) {
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

long long tot = 0;

int main () {
    freopen ("road.in", "r", stdin);
    freopen ("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i ++ ) fa[i] = i;
    for (int i = 1; i <= m; i ++ ) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g.push_back({u, v, w});
    }
    for (int i = 1; i <= k; i ++ ) {
        int c;
        scanf ("%d", &c);
        for (int j = 1; j <= n; j ++ ) {
            int w;
            scanf("%d", &w);
            // if (j == 1) vis[c] = w;
            // g.push_back({i, j, w});
        }
    }
    sort (g.begin(), g.end());
    int cnt = 0;
    for (Node now : g) {
        int u = now.u, w = now.w, v = now.v;
        int f1 = find(u), f2 = find(v);
        if (f1 == f2) continue;
        cnt ++ ;
        tot += w;
        fa[f1] = f2;
        if (cnt == n - 1) break;
    }
    cout << tot << '\n';
    return 0;
}

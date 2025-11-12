#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 1e4 + 100, MAXM = 1e6, MAXK = 10, inf = 1.01e9;
struct edge {
    int u, v, w;
} E[MAXM + 5], E2[MAXN * (MAXK + 1) + 5];
int n, m, k;
struct ddssuu{
    int father[MAXN + 5];
    void init(int N) {
        for (int i = 0; i <= N; i ++) father[i] = i;
    }
    int find(int x) {return father[x] == x ? x : father[x] = find(father[x]);}
    bool merge(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return 0;
        father[u] = v;
        return 1;
    }
} dsu[1030];

int v[MAXK + 5][MAXN + 5], val[MAXK + 5];
ll res[1030];
int read() {
    int x = 0;char ch = getchar();
    while (ch < '0' || ch > '9') ch  =getchar();
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x;
}
int main() {
    #ifndef LOCAL
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    #else
    freopen("./road/road4.in", "r", stdin);
    freopen("code.out", "w", stdout);
    clock_t BEGINT = clock();
    #endif

    n = read(), m = read(), k = read();
    for (int i = 1; i <= m; i ++) {
        int u = read(), v = read(), w = read();
        E[i] = {u, v, w};
    }
    sort(E + 1, E + 1 + m, [](edge a, edge b) {
        return a.w < b.w;
    });
    dsu[0].init(n);
    ll Mst = 0; int cnt = 0;
    for (int i = 1; i <= m; i ++) {
        int u = E[i].u, v = E[i].v, w = E[i].w;
        if (dsu[0].merge(u, v)) {
            Mst += w;
            E2[++ cnt] = E[i];
        }
    }
    res[0] = Mst;
    for (int i = 1; i <= k; i ++) {
        val[i] = read();
        for (int j = 1; j <= n; j ++) v[i][j] = read();
    }
    for (int i = 1; i <= k; i ++)
    for (int j = 1; j <= n; j ++)
    E2[++ cnt] = {i + n, j, v[i][j]};
    sort(E2 + 1, E2 + 1 + cnt, [](edge a, edge b) {
        return a.w < b.w;
    });
    for (int s = 1; s < (1 << k); s ++) dsu[s].init(n + k);
    for (int i = 1; i <= cnt; i ++) {
        int u = E2[i].u, v = E2[i].v, w = E2[i].w;
        for (int s = 1; s < (1 << k); s ++)
            if (u <= n || (s >> (u - n - 1) & 1)) {
                if (dsu[s].merge(u, v)) {
                    res[s] += w;
                }
            }
    }
    ll ans = Mst;
    for (int s=  0; s < (1 << k); s ++) {
        for (int j = 1; j <= k; j ++) {
            if (s >> (j - 1) & 1) res[s] += val[j];
        }
        ans = min(ans, res[s]);
    }
    cout<<ans;

    #ifdef LOCAL
    clock_t ENDT = clock();
    cerr<<endl<<fixed<<setprecision(3)<<(double)(ENDT - BEGINT) / CLOCKS_PER_SEC;
    #endif
    return 0;
}
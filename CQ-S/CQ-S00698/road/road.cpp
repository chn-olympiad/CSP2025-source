#include <bits/stdc++.h>
using namespace std;
const int N = 1105;
const int M = 1e6 + 5;
const int KK = 15;
struct Edge {
    int u;
    int v;
    int w;
    bool operator < (const Edge& oth) const {
        return w < oth.w;
    }
}E[2][M + N * KK];
int n, m, K, fa[N + KK], c[KK], a[KK][N], siz[N + KK];
long long mi = LLONG_MAX, sum = 0;
inline int Find(int u) {
    return fa[u] == u ? u : fa[u] = Find(fa[u]);
}
inline void Kruskal(int x) {
    for (int i = 1;i <= n + K;i++) {
        fa[i] = i;
        siz[i] = 1;
    }
    sort(E[0] + 1, E[0] + 1 + x);
    int Ecnt = 0;
    for (int i = 1;i <= x;i++) {
        int u = E[0][i].u;
        int v = E[0][i].v;
        int w = E[0][i].w;
        int fu = Find(u);
        int fv = Find(v);
        if (fu == fv)
            continue;
        else {
            if (siz[fu] < siz[fv])
                swap(fu, fv);
            siz[fu] += siz[fv];
            fa[fv] = fu;
            sum += w;
            if (x == m)
                E[1][++Ecnt] = E[0][i];
        }
    }
    mi = min(mi, sum);
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> K;
    for (int i = 1;i <= m;i++)
        cin >> E[0][i].u >> E[0][i].v >> E[0][i].w;
    for (int i = 1;i <= K;i++) {
        cin >> c[i];
        for (int j = 1;j <= n;j++)
            cin >> a[i][j];
    }
    sum = 0;
    Kruskal(m);
    for (int i = 1;i < (1 << K);i++) {
        int cnt = n - 1;
        for (int j = 1;j < n;j++)
            E[0][j] = E[1][j];
        sum = 0;
        for (int j = 1;j <= K;j++)
            if ((i >> (j - 1)) & 1) {
                sum += c[j];
                for (int k = 1;k <= n;k++)
                    E[0][++cnt] = { k,j + n,a[j][k] };
            }
        Kruskal(cnt);
    }
    cout << mi;
    return 0;
}

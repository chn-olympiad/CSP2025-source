

#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

using namespace std;

const int MAXN = 2e4 + 9, MAXM = 2e6 + 9, MAXK = 19;
int n, m, k;
int x[MAXM], y[MAXM], z[MAXM];
vector<pair<int, int>> G[MAXN];
int c[MAXK], a[MAXK][MAXN];

struct Edge {
    int x, y, z;
}e[MAXM];
int fa[MAXN];

int Read () {
    char c = cin.get();
    int num = 0;
    while ('0' <= c && c <= '9') num = num * 10 + (c - '0'), c = cin.get();
    return num;
}

bool Compare (Edge one, Edge two) {
    return one.z < two.z;
}

int Find (int u) {
    if (u == fa[u]) return u;
    return fa[u] = Find(fa[u]);
}

int Kruskal () {
    for (int i = 1; i <= m; i++) e[i].x = x[i], e[i].y = y[i], e[i].z = z[i];
    sort(e + 1, e + m + 1, Compare);

    for (int i = 1; i <= 2 * n; i++) fa[i] = i;

    int res = 0;
    for (int i = 1; i <= m; i++) {
        int fx = Find(e[i].x), fy = Find(e[i].y);
        if (fx != fy) fa[fx] = fy, res += e[i].z;
    }
    return res;
}

signed main () {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    n = Read(), m = Read(), k = Read();
//    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        x[i] = Read(), y[i] = Read(), z[i] = Read();
//        cin >> x[i] >> y[i] >> z[i];
        G[x[i]].push_back({y[i], z[i]});
        G[y[i]].push_back({x[i], z[i]});
    }
    for (int i = 1; i <= k; i++) {
        c[i] = Read();
//        cin >> c[i];
        for (int j = 1; j <= n; j++) {
            a[i][j] = Read();
//            cin >> a[i][j];
        }
    }

    if (k == 0) {
        cout << Kruskal() << '\n';
        return 0;
    }

    bool flag = 1;
    for (int i = 1; i <= k; i++)
        if (c[i] != 0) flag = 0;
    if (flag) {
        for (int i = 1; i <= k; i++)
            for (int j = 1; j <= n; j++)
                x[++m] = n + i, y[m] = j, z[m] = a[i][j];
        cout << Kruskal() << '\n';
        return 0;
    }

    int ans = 1e18;
    for (int i = 0; i < (1 << k); i++) {
        int cost = 0, oriM = m;
        for (int j = 1; j <= k; j++) {
            if (i & (1 << (j - 1))) {
                cost += c[j];
                for (int l = 1; l <= n; l++)
                    x[++m] = n + j, y[m] = l, z[m] = a[j][l];
            }
        }
        ans = min(ans, cost + Kruskal());
        m = oriM;
    }
    cout << ans << '\n';

    return 0;
}

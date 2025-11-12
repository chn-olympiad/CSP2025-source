# include <bits/stdc++.h>
using namespace std;
# define int long long
const int MAXN = 1e4 + 20;
const int MAXM = 1e6 + 10;
int n, m, k;
struct edge {
    int u, v, w;
}e[MAXM << 1], e2[MAXM << 1], e3[MAXM];
int tot = 0, c[20], a[20][MAXN];
int fa[MAXN];
int getfa(int x) {
    if (x == fa[x]) return fa[x];
    else return fa[x] = getfa(fa[x]);
}
bool cmp(edge A, edge B) {
    return A.w < B.w;
}
vector <pair <int, int> > g[MAXN], vec[MAXN];
int fst = 0;
int kruskal(int S) {
    int tot2 = tot, res = 0; 
    for (int i = 1; i <= n + k; i++) fa[i] = i;
    for (int i = 1; i <= k; i++){ 
        if ((S >> i - 1) & 1) {
            res += c[i];
            for (int j = 1; j <= n; j++) {
                e[++tot2] = {n + i, j, a[i][j]};
            }
        }
    }
    for (int i = 1; i <= tot2; i++) {
        e2[i] = e[i];
    }
    sort(e2 + 1, e2 + tot2 + 1, cmp);
    for (int i = 1; i <= tot2; i++) {
        int u = getfa(e2[i].u), v = getfa(e2[i].v), w = e2[i].w;
        if (u == v) continue;
        fa[u] = v;
        res += w;
        g[e2[i].u].push_back({e2[i].v, w});
        g[e2[i].v].push_back({e2[i].u, w});
    }
    fst = res;
    return res;
}
int dfn[MAXN], Clock = 0;
void dfs(int u, int fa) {
    dfn[u] = ++Clock;
    for (auto [v, w] : g[u]) {
        if (v == fa) continue;
        dfs(v, u);
    }
}
int cid = 0, col[MAXN];
void dfs2(int u, int fa, int c) {
    col[u] = c;
    for (auto [v, w] : g[u]) {
        if (v == fa || v > n) continue;
        dfs2(v, u, c);
    }
}
int cid2 = 0, col2[MAXN], flag[20];
void dfs3(int u, int fa, int c) {
    col2[u] = c;
    for (auto [v, w] : g[u]) {
        if (v == fa || (v > n && flag[v - n])) continue;
        dfs3(v, u, c);
    }
}
int mn[1000][1000], bao[1000], mn2[1000][1000];
int etot = 0;
int solve(int S) {
    int res = fst;
    memset(flag, 0, sizeof flag);
    for (int i = 1; i <= k; i++) {
        if (!((S >> i - 1) & 1)) {
            continue;
        }
            flag[i] = 1;
        res -= c[i];
        for (auto [v, w] : g[i + n]) res -= w;
    }
    // if (S == 1) cout << res << endl ;
    for (int i = 1; i <= n; i++) col2[i] = 0;
    cid2 = 0;
    for (int i = 1; i <= n + k; i++) {
        if (!col2[i] && (i <= n || !flag[i - n])) dfs3(i, 0, ++cid2);
    }
    // if (S == 1) {
    //     for (int i = 1; i <= n; i++) cout << col2[i] << " " ;
    //     cout << endl ;
    // }
    memset(bao, 0, sizeof bao);
    for (int i = 1; i <= n; i++) {
        bao[col[i]]= col2[i];
    }
    for (int i = 1; i <= cid2; i++) {
        for (int j = 1; j <= cid2; j++) mn2[i][j] = 1e18;
    }
    // for (int i = 1; i <= cid; i++) cout << bao[i] << " " ;
    // cout << endl ;
    for (int i = 1; i <= cid; i++) {
        for (int j = 1; j <= cid; j++) {
            mn2[bao[i]][bao[j]] = min(mn2[bao[i]][bao[j]], mn[i][j]);
        }
    }
    // cout << col2[n + 2] << " " << col2[2] << endl ;
    for (int i = 1; i <= k; i++) {
        if (((S >> i - 1) & 1)) continue;
        // cout << i << endl ;
        for (int j = 1; j <= n; j++) {
            // cout << j << endl ;
            mn2[col2[n + i]][col2[j]] = min(mn2[col2[n + i]][col2[j]], a[i][j]);
            mn2[col2[j]][col2[n + i]] = min(mn2[col2[j]][col2[n + i]], a[i][j]);
        }
    }
    etot = 0;
    // cout << mn2[1][2] << endl ;
    for (int i = 1; i <= cid2; i++) {
        for (int j = 1; j<= cid2; j++) {
            e3[++etot] = {i, j, mn2[i][j]};
        }
    }
    for (int i = 1; i <= cid2; i++) fa[i] = i;
    sort(e3 + 1, e3 + etot + 1, cmp);
    for (int i = 1; i <= etot; i++) {
        int u = getfa(e3[i].u), v = getfa(e3[i].v), w = e3[i].w;
        if (u == v) continue;
        fa[u] = v;
        res += w;
    }
    return res;
}
signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1, u , v, w; i <= m; i++) {
        cin >> u >> v >> w;
        e[++tot] = {u, v, w};
        vec[u].push_back({v, w});
        vec[v].push_back({u, w});
    }
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    if (k == 0 || m <= 100000) {
        int S = (1 << k) - 1;
        int ans = kruskal(S);
        for (int i = 0; i < (1 << k); i++) {
            ans = min(ans, kruskal(i));
        }
        cout << ans << endl ;
        return 0;
    }
    int S = (1 << k) - 1;
    int ans = kruskal(S);
    // cout << ans << endl ;
    for (int i = 1; i <= n; i++) {
        if (!col[i]) dfs2(i, 0, ++cid);
    }
    // cerr << cid << endl ;
    // return 0;
    memset(mn, 0x3f,sizeof mn);
    for (int i = 1; i <= m; i++) {
        int u = col[e[i].u], v = col[e[i].v];
        mn[u][v] = min(mn[u][v], e[i].w);
        mn[v][u] = min(mn[v][u], e[i].w);
    }
    // for (int i = 1; i <= n; i++) cout << col[i] << " " ;
    // cout << endl ;
    // cout << solve(2) << endl ;
    for (int i = 0; i <(1 << k); i++) {
        ans= min(ans, solve(i));
        // cout << i << " " << solve(i) << endl ;
    }
    cout << ans << endl ;
    return 0;
}
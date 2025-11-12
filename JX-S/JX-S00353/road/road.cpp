#include <bits/stdc++.h>

#define int long long
#define fi first
#define se second
#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define LL long long
#define mem(a, b) memset(a, b, sizeof a)
#define PII pair<int, int> 
#define PDD pair<double, double>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define Array(a) vector<array<int, a>>

using namespace std;

const double eps = 1e-8;
const int N = 20005, M = 1500005, INF = 1e18;
const int Mod = 1e9 + 7;
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int n, m, k;
struct Edge {
    int u, v, w;
}e[M], ano[M];
int fa[N];
int cost[15], d[15][N];
// int g[1015][1015], b[1015][1015];

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') f = (ch == '-' ? -f : f), ch = getchar();
    while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch - '0'), ch = getchar();
    return x * f;
}

inline bool cmp(Edge X, Edge Y) {
    return X.w < Y.w;
}

inline int getfa(int x) {
    return fa[x] == x ? fa[x] : fa[x] = getfa(fa[x]);
}

inline void Work1() {
    int ans = INF;
    for (int state = 0; state < (1 << k); state++) {
        int res = 0;
        int cnt = m;
        for (int i = 1; i <= m; i++) ano[i] = e[i];
        int times = 0;
        for (int i = 1; i <= k; i++)
            if (state >> (i - 1) & 1) {
                times++;
                res += cost[i];
                for (int j = 1; j <= n; j++) e[++cnt] = {n + times, j, d[i][j]};
            }
        sort(e + 1, e + cnt + 1, cmp);
        for (int i = 1; i <= n + times; i++) fa[i] = i;
        int lst = 0;
        for (int i = 1; i <= cnt; i++) {
            int fx = getfa(e[i].u), fy = getfa(e[i].v);
            if (fx == fy) continue;
            fa[fx] = fy;
            lst++;
            res += e[i].w;
            if (lst == n + times - 1) break;
        }
        ans = min(ans, res);
    }
    cout << ans << '\n';
    return ;
}

signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    IO;
    // cout << "CSP-S 2025 RP++" << '\n';
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) cin >> e[i].u >> e[i].v >> e[i].w;
    bool A = 1;
    for (int i = 1; i <= k; i++) {
        cin >> cost[i];
        if (cost[i]) A = 0;
        for (int j = 1; j <= n; j++) cin >> d[i][j];
    }
    if (n == 1) cout << 0 << '\n';
    else if (A) {
        int cnt = m;
        for (int i = 1; i <= k; i++)
            for (int j = 1; j <= n; j++) e[++cnt] = {n + i, j, d[i][j]};
        sort(e + 1, e + cnt + 1, cmp);

        for (int i = 1; i <= n + k; i++) fa[i] = i;
        int ans = 0;
        int times = 0;
        for (int i = 1; i <= cnt; i++) {
            int fx = getfa(e[i].u), fy = getfa(e[i].v);
            if (fx == fy) continue;
            fa[fx] = fy;
            times++;
            ans += e[i].w;
            if (times == n + k - 1) break;
        } 
        cout << ans << '\n';
    }
    else Work1(); // Use 2^5 state to check the min of the tree
    return 0;    
}
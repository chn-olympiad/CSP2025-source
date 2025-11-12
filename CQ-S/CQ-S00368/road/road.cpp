#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second 
#define pb push_back 
#define mk make_pair 
#define db double 
using namespace std;
const int MAXN = 2e4 + 5, MAXM = 2e6 + 5, MAXK = 12, INF = 1e18;

int n, m, k, N, ans, cnt, now;
int a[MAXK][MAXN], g[MAXK], vis[MAXN], dis[MAXN], in[MAXN], fa[MAXN], si[MAXN];
vector<pii> G[MAXN];

priority_queue<pii> q;

struct edge {
    int u, v, w;
} e[MAXM];

bool cmp(edge x, edge y) {
    return x.w < y.w;
}

void ms() {
    for (int i = 1; i <= N; i ++) fa[i] = i, si[i] = 1;
}

int fs(int x) {
    return x == fa[x] ? x : fa[x] = fs(fa[x]);
}

void Kruscal() {
    ms();
    ans = 0;
    for (int i = 1; i <= cnt; i ++){
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if (!g[u] || !g[v]) continue;
        int fu = fs(u), fv = fs(v);
        if (fu != fv){
            fa[fu] = fv;
            si[fv] += si[fu];
            ans += w;
            if (si[fv] == now) break;
        }
    }
}

void Prim() {
    ans = 0;
    for (int i = 1; i <= N; i ++) vis[i] = 0, dis[i] = INF;
    while (!q.empty()) q.pop();
    q.push(mk(0, 1));
    in[1] = 1;
    while (!q.empty()){
        int u = q.top().se, dist = q.top().fi;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        ans -= dist;
        // printf("%lld %lld\n", u, dist);
        for (pii tmp : G[u]){
            int v = tmp.fi, w = tmp.se;
            if (!g[v]) continue;
            if (dis[v] > w){
                dis[v] = w;
                q.push(mk(-dis[v], v));
            }
        }
    }
}

void Solve() {
    cnt = 0;
    cin >> n >> m >> k;
    for (int i = 1, u, v, w; i <= m; i ++){
        cin >> u >> v >> w;
        G[u].pb(mk(v, w)), G[v].pb(mk(u, w));
        e[++ cnt] = (edge){u, v, w};
    }
    for (int i = 1; i <= k; i ++){
        for (int j = 0; j <= n; j ++){
            cin >> a[i][j];
            if (j == 0) continue;
            G[n + i].pb(mk(j, a[i][j])), G[j].pb(mk(n + i, a[i][j]));
            e[++ cnt] = (edge){n + i, j, a[i][j]};
        }
    }
    for (int i = 1; i <= n; i ++) g[i] = 1;
    N = n + k;
    int Ans = 1e18;
    sort(e + 1, e + cnt + 1, cmp);
    for (int i = 0; i < (1ll << k); i ++){
        now = n;
        int sum = 0;
        for (int j = 1; j <= k; j ++){
            if ((1ll << (j - 1)) & i) g[n + j] = 1, sum += a[j][0], now ++;
            else g[n + j] = 0;
        }
        // printf("Prim %lld\n", i);
        // Prim();
        Kruscal();
        // puts("");
        Ans = min(Ans, ans + sum);

    }
    printf("%lld\n", Ans);
}

signed main() {
    // if (!system("fc road.out road4.ans")) puts("Yes");
    // else puts("No");
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) Solve();
    return 0;
}
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int W = 1e6 + 6;
const int N = 2e5 + 4;
struct node{
    int u, v, w;
    bool operator > (const node &s) const  {
        return w < s.w;
    }
}d[W];
bool cmp(node x, node y) {
    return x.w < y.w;
}
vector<pii> e[N];
int n, m, k, ans = LLONG_MAX;
int a[11][N];
int c[11];
int dx = 0;
int f[N];
void init() {
    for (int i = 1; i <= n + k; i++) {
        f[i] = i;
    }
    return ;
}
int find(int x) {
    return (f[x] == x) ? (f[x]) : (f[x] = find(f[x]));
}
bool vis[N];
node xx[N];
int dis[N];
void dijkstra(int s) {
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    dis[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > q;
    memset(vis, false, sizeof(vis));
    while (!q.empty()) {
        pii t = q.top();
        q.pop();
        int u = t.second;
        if (vis[u]) continue;
        vis[u] = 1;
        for (pii k : e[u]) {
            int v = k.first, w = k.second;
            if (vis[v]) continue;
            if (v > n) {
                w += c[v - n];
            }
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push(make_pair(dis[v], v));
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += dis[i];
    }
    ans = min(ans, sum);
    return ;
}
void DSU(int x) {
    int sum = 0, cnt = 0;
    priority_queue<node, vector<node>, greater<node> > q;
    for (int i = 1; i <= dx; i++) q.push(xx[i]);
    for (int i = 1; i <= k; i++) {
        if ((x >> (i - 1)) & 1) {
            for (int j = 1; j <= n; j++) {
                q.push(node{i + n, j, a[i][j]});
            }
        }
    }
    init();
    while (!q.empty()) {
        node t = q.top();
        q.pop();
        int u = t.u, v = t.v, w = t.w;
        int X = find(u), Y = find(v);
        if (X != Y) {
            f[X] = Y;
            sum += w;
            if (u <= n && v <= n) cnt++;
        }
        if (cnt == n - 1) {
            ans = min(ans, sum);
            return ;
        }
    }
    return ;
}
signed main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> d[i].u >> d[i].v >> d[i].w;
        e[d[i].u].push_back(make_pair(d[i].v, d[i].w));
        e[d[i].v].push_back(make_pair(d[i].u, d[i].w));
    }
    sort(d + 1, d + m + 1, cmp);
    if (k == 0) {
        int sum = 0, cnt = 0;
        init();
        for (int i = 1; i <= m; i++) {
            int X = find(d[i].u), Y = find(d[i].v);
            if (X != Y) {
                f[X] = Y;
                sum += d[i].w;
                cnt++;
            }
            if (cnt == n - 1) {
                cout << sum << "\n";
                return 0;
            }
        }
        cout << sum << "\n";
        return 0;
    }
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            e[i + n].push_back(make_pair(j, a[i][j]));
            e[j].push_back(make_pair(i + n, a[i][j]));
        }
    }
    if (n <= 1e3 + 3) for (int i = 1; i <= n; i++) {
        dijkstra(i);
    }
    else {
        for (int i = 1; i <= n; i += sqrt(n)) {
            dijkstra(i);
        }
    }
    init();
    int sum = 0, cnt = 0;
    for (int i = 1; i <= m; i++) {
        int X = find(d[i].u), Y = find(d[i].v);
        if (X != Y) {
            sum += d[i].w;
            cnt++;
            f[X] = Y;
            xx[cnt] = node{d[i].u, d[i].v, d[i].w};
        }
        if (cnt == n - 1) {
            break;
        }
    }
    dx = cnt;
    ans = min(ans, sum);
    for (int i = 0; i < pow(2, k); i++) {
        DSU(i);
    }
    cout << ans << "\n";
    return 0;
}

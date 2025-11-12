#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<algorithm>
#include<queue>
#define int long long
#ifdef int
#define inf 0x3f3f3f3f3f3f3f3fll
#else
#define inf 0x3f3f3f3f
#endif
#define fopen(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);
#define pii pair<int, int>
#define fi first
#define se second
#define maxn 10055
#define maxm 1000005
#define maxk 15

using namespace std;

int n, m, k, en, c[maxk], a[maxk][maxn];

struct Edge {
    int u, v, w;
    bool operator<(Edge b) {
        return w < b.w;
    }
} e[maxm * 2];

struct dsu {
    int f[maxn];
    void clear() {
        for(int i = 0; i < maxn; i++) {
            f[i] = i;
        }
    }
    dsu() {
        clear();
    }
    inline int find(int x) { return x == f[x] ? x : (f[x] = find(f[x])); }
    bool merge(int u, int v) {
        int fu = find(u), fv = find(v);
        if(fu == fv) return false;
        f[fu] = fv;
        return true;
    }
} f;

vector<Edge> p, q[maxk];

int ans = inf, sum;

void work() {
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        e[i] = (Edge){u, v, w};
    }
    f.clear();
    sort(e + 1, e + m + 1);
    for(int i = 1; i <= m; i++) {
        if(f.merge(e[i].u, e[i].v)) p.push_back(e[i]);
    }
    for(int j = 0; j < k; j++) {
        cin >> c[j];
        for(int i = 1; i <= n; i++) {
            cin >> a[j][i];
            q[j].push_back((Edge){n + 1 + j, i, a[j][i]});
        }
        sort(q[j].begin(), q[j].end());
    }
    for(int s = 0; s < (1 << k); s++) {
        sum = 0;
        f.clear();
        vector<Edge> g = p;
        for(int j = 0; j < k; j++) {
            if((s >> j) & 1) {
                for(Edge _e : q[j]) g.push_back(_e);
                sum += c[j];
            }
        }
        sort(g.begin(), g.end());
        for(Edge _e : g) {
            if(f.merge(_e.u, _e.v)) sum += _e.w;
        }
        ans = min(ans, sum);
    }
    cout << ans << '\n';
}

signed main() {
    // int st = clock();
    fopen("road");
    ios::sync_with_stdio(false); cin.tie(0);
    int _ = 1;
    // cin >> _;
    while(_--) work();
    // cerr << (1.0 * (clock() - st) / CLOCKS_PER_SEC) << endl;
}
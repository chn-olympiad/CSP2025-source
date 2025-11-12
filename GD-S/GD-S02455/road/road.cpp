#include <bits/stdc++.h>
#define rep(_x,_y,_z) for(int _x=(_y); _x <= (_z); _x++)
#define rrep(_x,_y,_z) for(int _x=(_y); _x >= (_z); _x--)
#define fi first
#define se second
using namespace std;
using pii = pair<int, int>;
using ll = long long;

struct Node {
    int u, v, w;
    int f;
    bool operator < (const Node & o) const {
        return w < o.w;
    }
};

vector<Node> e;

int fa[10050][1050];
int f(int u, int w) {
    if (fa[u][w] == u) return u;
    return fa[u][w] = f(fa[u][w], w);
}

int c[15], a[15][10050];
ll cost[1050];

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    rep(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        e.push_back({u, v, w, 0});
    }
    rep(i, 1, k) {
        cin >> c[i];
        rep(j, 1, n) {
            cin >> a[i][j];
            e.push_back({j, n+i, a[i][j], i});
        }
    }
    rep(j, 0, (1<<k)-1) rep(i, 1, n+k) fa[i][j] = i;
    rep(i, 0, (1<<k)-1) {
        rep(j, 1, k) {
            if ((i >> (j-1)) & 1) cost[i] += c[j];
        }
    }
    sort(e.begin(), e.end());
    for (auto p : e) {
        if (f(p.u, 0) == f(p.v, 0)) continue;
        rep(i, 0, (1<<k)-1) {
            if (f(p.u, i) == f(p.v, i)) continue;
            if (p.f && !((i >> (p.f-1)) & 1)) continue;
            cost[i] += p.w;
            fa[f(p.u, i)][i] = f(p.v, i);
        }
    }
    ll ans = 1e18;
    rep(i, 0, (1<<k)-1) ans = min(ans, cost[i]);
    cout << ans << endl;
}
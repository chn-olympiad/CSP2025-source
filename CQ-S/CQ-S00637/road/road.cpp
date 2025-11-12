#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, m, k, fa[1024][10015], rk[1024][10015];
ll rs, ds[1024];
struct edge { int u, v, w; } e[1100005];
vector<edge> E;

int Fd(int i, int x) { return fa[i][x] == x ? x : fa[i][x] = Fd(i, fa[i][x]); }
void Un(int i, int x, int y) {
    if (rk[i][x] > rk[i][y]) swap(x, y);
    fa[i][x] = y;
    rk[i][y] += rk[i][x] == rk[i][y];
}

signed main() {
#ifdef LARRIX
    freopen("road4.in", "r", stdin);
    freopen("sample.out", "w", stdout);
#else
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) cin >> e[i].u >> e[i].v >> e[i].w;
    sort(e + 1, e + m + 1, [](edge x, edge y){ return x.w < y.w; });
    for (int i = 0; i < 1024; i++) for (int j = 1; j <= n + k; j++) fa[i][j] = j, rk[i][j] = 1;
    for (int i = 1; i <= m; i++) {
        int x = Fd(0, e[i].u), y = Fd(0, e[i].v);
        if (x != y) {
            rs += e[i].w;
            Un(0, x, y);
            E.push_back(e[i]);
        }
    }
    for (int i = 1; i <= k; i++) {
        int x; cin >> x;
        for (int j = 1; j < 1024; j++) if (j >> i - 1 & 1) ds[j] += x;
        for (int j = 1; j <= n; j++) {
            E.push_back({i + n, j, 0});
            cin >> E.back().w;
        }
    }
    sort(E.begin(), E.end(), [](edge x, edge y){ return x.w < y.w; });
    for (auto i : E) {
        int x = i.u, y = i.v;
        if (x <= n) {
            for (int j = 1; j < 1024; j++) {
                int xx = Fd(j, x), yy = Fd(j, y);
                if (xx != yy) {
                    ds[j] += i.w;
                    Un(j, xx, yy);
                }
            }
        } else {
            for (int j = 1; j < 1024; j++) if (j >> x - n - 1 & 1) {
                int xx = Fd(j, x), yy = Fd(j, y);
                if (xx != yy) {
                    ds[j] += i.w;
                    Un(j, xx, yy);
                }
            }
        }
    }
    for (int i = 1; i < 1024; i++) rs = min(rs, ds[i]);
    cout << rs << '\n';
    return 0;
}
/*
g++ -o road road.cpp -std=c++14 -O2 -DLARRIX ; if [ $? -eq 0 ]; then /usr/bin/time -f "%es, %MKB" ./road ; fi
*/
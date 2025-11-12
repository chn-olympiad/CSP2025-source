#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>

using namespace std;

const int kmax = 1e4 + 13;
const int kmaxM = 1e6 + 3;
const int kmaxK = 13;

struct E {
    int x, y, w;
} e[kmaxM], _e[kmax];

int n, m, k;
int ec;
int a[kmaxK][kmax];
int c[kmaxK];
long long res = 1e18;
int dc, d[kmaxK];

namespace Dsu {

    int f[kmax];

    int F(int x) {
        return f[x] == x ? x : f[x] = F(f[x]);
    }

    void Init(int n) {
        for(int i = 1; i <= n; i++) f[i] = i;
    }
}

void Solve(int lim) {
    m = 0;
    for(int i = 1; i <= ec; i++) e[++m] = _e[i];
    long long tot = 0;
    dc = 0;
    for(int i = 1; i <= k; i++) {
        if((lim >> (i - 1)) & 1) {
            d[i] = (++dc) + n;
            tot += c[i];
            for(int j = 1; j <= n; j++) {
                e[++m] = {d[i], j, a[i][j]};
            }
        }
    }
    sort(e + 1, e + m + 1, [](E p, E q) { return p.w < q.w; });
    Dsu::Init(n + dc);
    int ct = 0;
    for(int i = 1; i <= m; i++) {
        int x = Dsu::F(e[i].x);
        int y = Dsu::F(e[i].y);
        if(x == y) continue;
        Dsu::f[x] = y, tot += e[i].w;
        if(++ct == n + dc - 1) break;
    }
    res = min(res, tot);
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++) {
        cin >> e[i].x >> e[i].y >> e[i].w;
    }
    sort(e + 1, e + m + 1, [](E p, E q) { return p.w < q.w; });
    Dsu::Init(n);
    for(int i = 1; i <= m; i++) {
        int x = Dsu::F(e[i].x);
        int y = Dsu::F(e[i].y);
        if(x == y) continue;
        _e[++ec] = e[i];
        Dsu::f[x] = y; 
    }
    for(int i = 1; i <= k; i++) {
        cin >> c[i];
        for(int j = 1; j <= n; j++) cin >> a[i][j];
    }
    for(int i = 0; i < 1 << k; i++) {
        Solve(i);
    }
    cout << res << '\n';
    // cerr << 1.0 * clock() / CLOCKS_PER_SEC << '\n';
    return 0;
}
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 10005, maxm = 1000005;
int n, m, k, c;
struct edge {
    int x, y, w, id;
    bool operator < (const edge &a) const {return w < a.w;}
} a[maxm];
int s[maxn];
int fa[maxn], sz[maxn];
int ans = 1e18;
int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
int calc(int S) {
    for (int i = 1; i <= n + k; i++) fa[i] = i, sz[i] = 1;
    int sum = 0;
    for (int i = 1; i <= c; i++) {
        if (a[i].id && !((S >> a[i].id - 1) & 1)) continue;
        int fx = find(a[i].x), fy = find(a[i].y);
        if (fx == fy) continue;
        if (sz[fx] > sz[fy]) swap(fx, fy);
        fa[fx] = fy, sz[fy] += sz[fx]; sum += a[i].w;
    }
    for (int i = 1; i <= k; i++)
        if ((S >> i - 1) & 1) sum += s[i];
    return sum;
}
signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) cin >> a[i].x >> a[i].y >> a[i].w, a[i].id = 0;
    sort(a + 1, a + 1 + m);
    for (int i = 1; i <= n; i++) fa[i] = i, sz[i] = 1;
    for (int i = 1; i <= m; i++) {
        int fx = find(a[i].x), fy = find(a[i].y);
        if (fx == fy) continue;
        if (sz[fx] > sz[fy]) swap(fx, fy);
        fa[fx] = fy, sz[fy] += sz[fx]; a[++c] = a[i];
    }
    for (int i = 1; i <= k; i++) {
        cin >> s[i];
        for (int j = 1; j <= n; j++) {
            int w; cin >> w;
            a[++c] = (edge){i + n, j, w, i};
        }
    }
    cerr << clock() * 1. / CLOCKS_PER_SEC << '\n';
    sort(a + 1, a + 1 + c);
    for (int i = 0; i < (1 << k); i++) ans = min(ans, calc(i));
    cout << ans << '\n';
    cerr << clock() * 1. / CLOCKS_PER_SEC << '\n';
    return 0;
}
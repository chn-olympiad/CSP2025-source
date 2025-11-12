#include <bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int N = 2e4 + 10, M = 2e6 + 10;
const ll oo = 1e18;
int n, m, mm, k, f[N], a[12][N];
ll ans = oo, ret, ret2;
struct EDGE {
    int u, v, w, id;
} e[M], e2[N];
bool cmp(EDGE x, EDGE y) {
    return x.w < y.w;
}
bool cmpid(EDGE x, EDGE y) {
    return x.id < y.id;
}
int gf(int x) {
    return x == f[x] ? x : f[x] = gf(f[x]);
}
void clear() {
    for (int i = 1; i <= n + k; i++)
        f[i] = i;
}
void kk() {
    clear();
    sort(e + 1, e + m + 1, cmp);
    for (int i = 1, cnt = 0; i <= m; i++) {
        auto [u, v, w, id] = e[i];
        int fu = gf(u), fv = gf(v);
        if (fu == fv)
            continue;
        f[fu] = fv;
        e2[++cnt] = e[i];
        e2[cnt].id = cnt;
        if (cnt + 1 == n)
            return;
    }
}
void kk2() {
    clear();
    sort(e2 + 1, e2 + mm + 1, cmp);
    for (int i = 1, cnt = 0; i <= mm; i++) {
        auto [u, v, w, id] = e2[i];
        int fu = gf(u), fv = gf(v);
        if (fu == fv)
            continue;
        f[fu] = fv;
        ret += w;
        if (ret >= ans)
            return;
        if (cnt + 1 == n) {
            ans = ret;
            return;
        }
    }
}
signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    IOS;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
        e[i].id = i;
    }
    for (int i = 0; i < k; i++)
        for (int j = 0; j <= n; j++)
            cin >> a[i][j];
    kk();
    for (int s = 0; s < 1 << k; s++) {
        mm = n - 1;
        ret = 0;
        for (int i = 0; i < k; i++) {
            if (!(s >> i & 1))
                continue;
            ret += a[i][0];
            for (int j = 1; j <= n; j++)
                e2[++mm] = {n + i + 1, j, a[i][j], n};
        }
        kk2();
        ans = min(ans, ret);
        sort(e2 + 1, e2 + mm + 1, cmpid);
    }
    cout << ans;
    return 0;
}

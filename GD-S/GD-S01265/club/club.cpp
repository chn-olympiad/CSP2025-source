#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 5;
int n; struct A { int t[3], v, x, y; } a[N];

signed main() {
    freopen("club.in", "r", stdin); freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; for (cin >> T; T--; ) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].t[0] >> a[i].t[1] >> a[i].t[2];
            int o[3] = {0, 1, 2};
            sort(o, o + 3, [&](int x, int y) { return a[i].t[x] > a[i].t[y]; });
            a[i].v = a[i].t[o[0]] - a[i].t[o[1]], a[i].x = o[0], a[i].y = o[1];
        } sort(a + 1, a + n + 1, [](A x, A y) { return x.v > y.v; });
        int c[3] = {}, ans = 0;
        for (int i = 1; i <= n; i++) {
            if (c[a[i].x] < n / 2) c[a[i].x]++, ans += a[i].t[a[i].x];
            else c[a[i].y]++, ans += a[i].t[a[i].y];
        } cout << ans << '\n';
    }
    return 0;
}

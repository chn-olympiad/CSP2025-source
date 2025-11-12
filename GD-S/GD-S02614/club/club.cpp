#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using f64 = double;

constexpr int N = 1e5 + 7;
constexpr f64 MXT = 0.2;

int n, lim, flgb, flgc;
int sa, sb, sc;
bool vis[N];

struct elem {
    int x, y, z;
} a[N];

std::random_device rdv;
std::mt19937 myrand(rdv());

bool cmp(const elem &a, const elem &b) { return (a.x == b.x ? a.y > b.y : a.x > b.x); }

void solve2() {
    i64 ans = 0;
    std::sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= lim; i++) {
        ans += a[i].x;
    }
    std::cout << ans << "\n";
}

void solve3() {
    i64 ans = 0;
    std::sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= lim; i++) {
        ans += a[i].x;
    }
    std::cout << ans << "\n";
}

void solve() {
    std::cin >> n; lim = n / 2;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i].x >> a[i].y >> a[i].z;
        if (a[i].y != 0) { flgb = 0; }
        if (a[i].z != 0) { flgc = 0; }
    }
    if (flgb) { solve2(); return; }
    if (flgc) { solve3(); return; }
    int cnt = 0; i64 ans = 0;
    while (cnt <= 100000) {
        i64 res = 0;
        while (1) {
            sa = myrand() % (lim + 1); sb = myrand() % (n - sa + 1); sc = n - sa - sb;
            if (sc > lim || sc < 0 || sb > lim)
                continue;
            break;
        }
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= sa; i++) {
            int x = myrand() % n + 1;
            for (; vis[x]; x = myrand() % n + 1);
            res += a[x].x; vis[x] = 1;
        }
        for (int i = 1; i <= sb; i++) {
            int x = myrand() % n + 1;
            for (; vis[x]; x = myrand() % n + 1);
            res += a[x].y; vis[x] = 1;
        }
        for (int i = 1; i <= n; i++) {
            if (!vis[i])
                res += a[i].z;
        }
        ans = std::max(ans, res);
        cnt++;
    }
    std::cout << ans << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

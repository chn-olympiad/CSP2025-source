#include <bits/stdc++.h>

const int N = 1e5 + 5;
int a[N], b[N], c[N], ans, n, m;
bool A, B;

void dfs(int i, int al, int bl, int cl, int sum) {
    ans = std::max(ans, sum);
    if (i > n) return;
    if (al + 1 <= m) dfs(i + 1, al + 1, bl, cl, sum + a[i]);
    if (bl + 1 <= m) dfs(i + 1, al, bl + 1, cl, sum + b[i]);
    if (cl + 1 <= m) dfs(i + 1, al, bl, cl + 1, sum + c[i]);
}

void solve() {
    ans = 0;
    A = B = 1;
    std::cin >> n;
    m = n / 2;
    for (int i = 1; i <= n; i ++) {
        std::cin >> a[i] >> b[i] >> c[i];
        if (c[i] != 0) A = B = 0;
        else if (b[i] != 0) A = 0;
    }
    if (A) {
        std::sort (a + 1, a + 1 + n);
        for (int i = n; i > n / 2; i --) ans += a[i];
        std::cout << ans << '\n';
        return;
    }
    dfs(1, 0, 0, 0, 0);
    std::cout << ans << '\n';
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    std::cin >> t;
    while (t --) solve();
    return 0;
}

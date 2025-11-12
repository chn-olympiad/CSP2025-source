#include <bits/stdc++.h>
#define int long long
int n, m, a[105], r;
signed main() {
    std::freopen("seat.in", "r", stdin), std::freopen("seat.out", "w", stdout);
    std::cin >> n >> m;
    for (int i = 1; i <= n * m; ++i)
        std::cin >> a[i];
    r = a[1], std::sort(a + 1, a + n * m + 1, [](int a, int b) {
        return a > b;
    });
    for (int i = 1; i <= n * m; ++i)
        if (a[i] == r)
            if (((i + n - 1) / n) % 2)
                std::cout << ((i + n - 1) / n) << ' ' << (i - ((i + n - 1) / n - 1) * n);
            else
                std::cout << ((i + n - 1) / n) << ' ' << (n + 1 - i + ((i + n - 1) / n - 1) * n);
    return 0;
}

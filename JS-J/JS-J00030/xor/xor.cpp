#include <bits/stdc++.h>
#define int long long
int n, k, a[500005], sum[500005], p[500005], lst, ans;
signed main() {
    std::freopen("xor.in", "r", stdin), std::freopen("xor.out", "w", stdout);
    std::cin >> n >> k, memset(p, -1, sizeof(p));
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i], sum[i] = sum[i - 1] ^ a[i];
        if (p[sum[i] ^ k] >= lst)
            lst = i, ++ans;
        p[sum[i]] = i;
    }
    std::cout << ans;
    return 0;
}

#include<iostream>
#include<cstdlib>
#include<algorithm>

constexpr int N = 5000 + 5, V = 5000 + 1;
constexpr int MOD = 998244353;

int n, a[N], f[V], sum[N];

int fp(int a, int b) {
    if(!a || !b) return !b;
    int res = fp(a, b >> 1);
    res = (1ll * res * res) % MOD;
    if(b & 1) res = (1ll * res * a) % MOD;
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::freopen("polygon.in", "r", stdin);
    std::freopen("polygon.out", "w", stdout);

    std::cin >> n;
    for(int i = 1; i <= n; ++i) std::cin >> a[i];
    std::sort(a + 1, a + n + 1);

    f[a[1]] = f[0] = 1;
    for(int i = 2; i <= n; ++i) {
        for(int j = V - 1; j >= a[i]; --j) (f[j] += f[j - a[i]]) %= MOD;
        for(int j = 0; j <= a[i + 1]; ++j) (sum[i] += f[j]) %= MOD;
    }

    int ans = 0;
    for(int i = 3; i <= n; ++i) (ans += (fp(2, i - 1) - sum[i - 1] + MOD) % MOD) %= MOD;
    std::cout << ans << "\n";

    return 0;
}

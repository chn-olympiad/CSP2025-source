// AC!
// jiazhichen844 bless me
// DTL123 bless me
// xuanxuanni bless me
// throwAC bless me
// AutumnQ bless me
// chennie bless me
// Sving1024 bless me
// cmhcmh bless me
// Cubber/Aubber bless me
// Richard1211 bless me
// FlamingBlade bless me
// A_foolish_guy bless me
// jiangly bless me
// tourist bless me

#include<bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

// n <= 20 is easy. (1 << n) 
// max_{ai} <= 1 is trivial also. We can choose anything. O(n) can get answer
// emmm...

// I can sort it
/*
    then i only need judge if the sum of a_i (i is what i chose) greater than double 
    the last one what i chose
*/

/*
    i think that i can do this transform
    sum_{a_i (i is what i chose)} > 2 * max_{a_i} 
    ---> sum_{a_i (i is what i chose too, but except the last one)} > max_{a_i}
    Then after sorting, the problem will become
    how many subsequences in subarray[1...i - 1], the sum of their value > a[i] (i > 2)
*/

/*
    dp[i] means the number = i
*/
namespace tourist{
void solve() {
    static constexpr i64 mod = 998244353;
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1, 0);
    bool tag = true;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        if (a[i] != 1) tag = false;
    }

    i64 ans = 0;
    std::sort(a.begin(), a.end());

    auto qpow = [&](i64 base, i64 power) -> i64{
        i64 ret = 1;
        while (power) {
            if (base & 1ll) {
                ret *= base;
                ret %= mod;
            }
            base *= base;
            base %= mod;
            power >>= 1ll;
        }

        return ret;
    };

    std::vector<i64> inv(5005);
    for (int i = 1; i <= 5000; ++i) inv[i] = qpow((i64)i, mod - 2);
    std::vector<i64> fac(5005, 1);
    std::vector<i64> ifac(5005, 1);
    for (int i = 1; i <= 5000; ++i) {
        ifac[i] = ifac[i - 1] * inv[i];
        ifac[i] %= mod;
        fac[i] = fac[i - 1] * i;
        fac[i] %= mod;
    }

    auto C = [&](int M, int N) -> i64{
        if (M < N) return 0;
        if (M == N) return 1;
        return fac[M] * ifac[N] % mod * ifac[M - N] % mod;
    };
    if (n <= 20) {
        for (int i = 1; i < (1 << n); ++i) {
            int mx = -1;
            int sum = 0;
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    ++cnt;
                    mx = std::max(mx, a[j + 1]);
                    sum += a[j + 1];
                }
            }

            // std::cerr << i << ' ' << mx << ' ' << sum << ' ' << cnt << '\n';
            if (cnt >= 3 and sum > 2 * mx) {
                // std::cerr << i << '\n';
                ++ans;
            }
        }

        std::cout << ans % mod << '\n';
    } else if (tag) {
        for (int i = 3; i <= n; ++i) {
            ans += C(n, i);
            ans %= mod;
        }

        std::cout << ans << '\n';
    } else {
        // std::cerr << "Debug" << '\n';
        std::vector<std::vector<int> > dp(n + 1, std::vector<int>((a[n] * 2 + 1), 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= (a[n] * 2); ++j) {
                // std::cerr << "Debug" << '\n';
                dp[i][j] = dp[i - 1][j];
                for (int k = 1; k <= i; ++k) {
                    if (j >= a[i]) {
                        dp[i][j] += dp[i - k][j - a[i]];
                        dp[i][j] %= (int)mod;
                    }
                }
            }
        }

        // for (int i = 1; i <= n; ++i) {
        //     for (int j = 1; j <= 1000; ++j) std::cerr << dp[i][j] << ' ';
        //     std::cerr << '\n';
        // }

        for (int i = 3; i <= n; ++i) {
            for (int j = 0; j <= 2 * a[i]; ++j) {
                i64 sum = 0;
                if(dp[i - 1][j] > 1) sum += dp[i - 1][j];
                ans += fac[i - 1] - sum;
                ans %= mod;
            }
        }

        std::cout << (ans + mod) % mod << '\n';
    }
}
}

int tests = 1;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    assert(freopen("polygon.in", "r", stdin));
    assert(freopen("polygon.out", "w", stdout));
    while (tests--) {
        tourist::solve();
    }

    return 0;
}
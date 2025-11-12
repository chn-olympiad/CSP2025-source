#include <bits/stdc++.h>
using namespace std;

using u32 = uint32_t;
using u64 = uint64_t;
using i32 = int32_t;
using i64 = int64_t;

constexpr u64 N = 500, K = 18, P = (119 << 23) + 1;

u64 dp[1 << K][K + 1];

u64 bitmask_dp(u32 n, u32 m, string s, const vector<u32> &c) {
    u64 ans = 0;
    dp[0][0] = 1;
    for (u32 S = 0; S < (1 << n); S++)
        for (u32 l = 0; l < n; l++)
            for (u32 ci = 0; ci <= __builtin_popcount(S); ci++)
                if (((~S) >> l) & 1) {
                    u32 day = __builtin_popcount(S);
                    bool fail = (ci >= c[l] || s[day] == '0');
                    (dp[S | (1 << l)][ci + fail] += dp[S][ci]) %= P;
                }
    for (u32 ci = 0; ci <= n - m; ci++) ans = (ans + dp[(1 << n) - 1][ci]) % P;
    return ans;
}

u64 dp_m1[N];

u64 m1(u32 n, u32 m, string s, const vector<u32> &c) {
    vector<u32> p;
    for (u32 i = 0; i < n; i++) if (s[i] == '1') {
        u32 cnt = 0;
        for (u32 j : c) cnt += (j <= i);
        p.push_back(cnt);
    } else p.push_back(n);
    sort(p.begin(), p.end(), greater<>());
    u64 fac = 1, ans = 1;
    for (u32 i = 1; i <= n; i++) {
        u32 cc = 0;
        for (u32 j : p) cc += (j >= i);
        fac *= i, ans *= (cc - (n -i));
        fac %= P, ans %= P;
    }
    return (fac - ans + P) % P;
}

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    u32 n, m;
    cin >> n >> m;
    string s;
    vector<u32> c(n);
    cin >> s;
    for (auto &i : c) cin >> i;
    if (n <= 18) cout << bitmask_dp(n, m, s, c) << endl;
    else if (m == n) {
        if (s == string(n, '1') && (*min_element(c.begin(), c.end())) > 0) {
            u64 ans = 1;
            for (u32 i = 1; i <= n; i++) ans = ans * i % P;
            cout << ans << endl;
        } else cout << 0 << endl;
    } else if (m == 1) {
        cout << m1(n, m, s, c) << endl;
    }
}
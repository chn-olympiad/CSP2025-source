#include <algorithm>
#include <cstdio>
#include <iostream>
#define MAXN 5003
#define MOD 998244353
using namespace std;
using ui = unsigned int;
using ulli = unsigned long long;

inline ulli inv(ulli x)
{
    ui k = MOD - 2;
    ulli rv = 1;
    while (k)
    {
        if (k & 1U)
            rv = rv * x % MOD;
        x = x * x % MOD;
        k >>= 1U;
    }
    return rv;
}

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    static int a[MAXN];
    ui n;
    cin >> n;
    for (ui i = 0; i < n; ++i)
        cin >> a[i];
    if (n <= 20)
    {
        int sm, mx, ans = 0;
        for (ui i = 0, tmp, cur; i < (1U << n); ++i)
        {
            tmp = i, sm = mx = 0;
            while (tmp)
            {
                cur = __builtin_ctz(tmp);
                sm += a[cur], mx = max(mx, a[cur]);
                tmp ^= 1U << cur;
            }
            if (sm > (mx << 1))
                ++ans;
        }
        cout << ans;
        return 0;
    }
    static ulli fac[MAXN], ifac[MAXN];
    fac[0] = ifac[0] = 1;
    for (ui i = 1; i <= n; ++i)
        fac[i] = fac[i - 1] * i % MOD, ifac[i] = inv(fac[i]);
    ulli ans = 0;
    for (ui i = 3; i <= n; ++i)
        ans = (ans + fac[n] * ifac[i] % MOD * ifac[n - i]) % MOD;
    cout << ans;
    return 0;
}

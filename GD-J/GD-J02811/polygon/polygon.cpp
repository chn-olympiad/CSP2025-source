# include <bits/stdc++.h>
# define ull unsigned long long
using namespace std;

static const int N = 5e3 + 5;
static const ull MOD = 998244353;
ull n, a[N], fac[N], ifac[N];

inline ull fpow (ull bs, ull pw = MOD - 2)
{
    ull ret = 1;
    while (pw)
    {
        if (pw & 1)
        {
            ret = ret * bs % MOD;
        }
        bs = bs * bs % MOD;
        pw >>= 1;
    }
    return ret;
}

inline void init ()
{
    fac[0] = 1; for (int i = 1; i <= n; i++) { fac[i] = fac[i - 1] * i % MOD; }
    ifac[n] = fpow (fac[n]); for (int i = n - 1; i >= 0; i--) { ifac[i] = ifac[i + 1] * (i + 1) % MOD; }
    return ;
}

inline ull cmb (ull n, ull m)
{
    if (n < m || n == 0) { return 0ll; }
    return fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;
}

inline void sub40 ()
{
    ull ans = 0;
    for (int i = 0; i < (1 << n); i++)
    {
        ull mx = 0, sum = 0, cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (i & (1ull << (j - 1)))
            {
                sum += a[j];
                mx = max (mx, a[j]);
                cnt ++;
            }
        }
        if (cnt >= 3 && sum > mx * 2) { ans ++; }
    }
    if (ans > MOD) { ans %= MOD; }
    cout << ans << "\n";
}

inline void sub80 (int mx)
{
    if (mx == 0) { cout << 0 << "\n"; return ; }
    ull cnt1 = 0, cnt0 = 0; init ();
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1)
        {
            cnt1 ++;
        }
        else
        {
            cnt0 ++;
        }
    }

    if (cnt1 <= 1) { cout << 0 << "\n"; return ; }
    ull ans = 0;
    for (int x = 3; x <= cnt1; x++)
    {
        for (int y = 0; y <= cnt0; y++)
        {
            ans = (ans + cmb (cnt1, x) * cmb (cnt0, y)) % MOD;
        }
    }
    cout << ans << "\n";
    return ;
}

int main ()
{
    freopen ("polygon.in", "r", stdin);
    freopen ("polygon.out", "w", stdout);
    ios_base :: sync_with_stdio (0);
    cin.tie (nullptr), cout.tie (nullptr);
    cin >> n; for (int i = 1; i <= n; i++) { cin >> a[i]; }
    if (n <= 20) { sub40 (); return 0; }
    ull mx = 0; for (int i = 1; i <= n; i++) { mx = max (mx, a[i]); }
    if (mx <= 1) { sub80 (mx); return 0; }
    return 0;
}
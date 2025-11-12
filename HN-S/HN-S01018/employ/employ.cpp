#include <bits/stdc++.h>
#define mod 998244353
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define file(s) freopen(#s".in", "r", stdin), freopen(#s".out", "w", stdout)
using namespace std;
template <typename T> inline bool ckmin(T &x, T y) {return (y < x) && (x = y, true);}
template <typename T> inline bool ckmax(T &x, T y) {return (x < y) && (x = y, true);}
int n, m; char s[505];
namespace bf
{
#define N 18
    int p[N], f[1 << N][N];
    inline void Add(int &x, int y) {(x += y) >= mod && (x -= mod);}
    inline void main()
    {
        for (int i = 0; i < n; ++ i) cin >> p[i];
        f[0][0] = 1;
        for (int s = 1, ct, i, j; s < 1 << n; ++ s)
        {
            ct = __builtin_popcount(s);
            if (::s[ct] == '0')
            {
                for (j = 0; j < n; ++ j)
                    if (s >> j & 1)
                        for (i = 1; i <= ct; ++ i)
                            Add(f[s][i], f[s ^ 1 << j][i - 1]);
            }
            else
            {
                for (j = 0; j < n; ++ j)
                    if (s >> j & 1)
                        for (i = 0; i < ct; ++ i)
                            if (i >= p[j]) Add(f[s][i + 1], f[s ^ 1 << j][i]);
                            else Add(f[s][i], f[s ^ 1 << j][i]);
            }
        }
        int ans = 0, all = (1 << n) - 1;
        for (int i = 0; i <= n - m; ++ i) Add(ans, f[all][i]);
        cout << ans;
    }
#undef N
}
namespace test15
{
    inline void main()
    {
        bool flg = true;
        for (int i = 1; i <= n; ++ i) flg &= s[i] == '1';
        for (int i = 1, x; i <= n; ++ i) cin >> x, flg &= (bool)x;
        if (!flg) cout << 0;
        else
        {
            int res = 1;
            for (int i = 1; i <= n; ++ i) res = 1ll * res * i % mod;
            cout << res;
        }
    }
}
namespace sub3
{
#define N 505
    inline void Add(int &x, int y) {(x += y) >= mod && (x -= mod);}
    inline void Sub(int &x, int y) {(x -= y) < 0 && (x += mod);}
    int p[N], ct, f[N << 1][N]; pii a[N << 1];
    inline void main()
    {
        for (int i = 1; i <= n; ++ i)
            if (s[i] == '1') a[++ ct] = {i - 1, 1};
        for (int i = 1, x; i <= n; ++ i) cin >> x, a[++ ct] = {x, 0};
        sort(a + 1, a + ct + 1), reverse(a + 1, a + ct + 1), f[0][0] = 1;
        int ct0 = 0, ct1 = 0;
        for (int i = 1, j; i <= ct; ++ i)
        {
            if (a[i].se)
            {
                ++ ct1;
                for (j = 0; j < i; ++ j) f[i][j] = f[i - 1][j];
            }
            else
            {
                ++ ct0;
                for (j = 0; j <= ct0 && j <= ct1; ++ j)
                {
                    f[i][j] = f[i - 1][j];
                    if (ct1 && j) Add(f[i][j], 1ll * f[i - 1][j - 1] * (ct1 - j + 1) % mod);
                }
            }
        }
        int ans = 1, res = 1;
        for (int i = 1; i <= n; ++ i) ans = 1ll * ans * i % mod;
        for (int i = 1; i <= n - ct1; ++ i) res = 1ll * res * i % mod;
        Sub(ans, 1ll * res * f[ct][ct1] % mod);
        cout << ans;
    }
#undef N
}
signed main()
{
    file(employ);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> (s + 1);
    if (n <= 18) bf::main();
    else if (n == m) test15::main();
    else sub3::main();
    return 0;
}
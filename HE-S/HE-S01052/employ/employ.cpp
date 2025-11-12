#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <tuple>

using namespace std;

const int N = 500 + 10, mod = 998244353; // don't hack my hash, or I will write 2 mod + ull hash !!!!!!

#define int long long

using pii = pair <int, int>;
using ull = unsigned long long;
const ull base = 131;

#define fi first
#define se second

int dp[N][N], c[N], tot[N], cnt, pos[N], fac[N], res[N], inv[N];
char s[N];

int qpow(int x, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1) res = res * x % mod;
        x = x * x % mod;
        b >>= 1;
    }
    return res;
}

int C(int n, int m)
{
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

signed main()
{
    freopen("data.in", "r", stdin); freopen("data.out", "w", stdout);
     freopen("employ.in", "r", stdin); freopen("employ.out", "w", stdout);
    ios :: sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n; cin >> n;
    int m; cin >> m;
    int tmp = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        if (s[i] == '1')
        {
            cnt++;
            pos[cnt] = tmp + pos[cnt - 1];
            tmp = 0;
        }
        else tmp++;
    }
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= n; i++) cin >> c[i], fac[i] = fac[i - 1] * i % mod, inv[i] = qpow(fac[i], mod - 2);
    sort(c + 1, c + 1 + n);
    dp[0][0] = 1;
    int ans = 0;
    for (int j = 1; j <= cnt; j++)
    {
        for (int i = 0; i <= cnt; i++)
        {
            int posi = upper_bound(c + 1, c + 1 + n, i + pos[j]) - c - 1 - i; // will leave
            if (posi < 0) continue;
            // for (int k = 0; k < j; k++)
            // {
            (dp[i + 1][j] += dp[i][j - 1] * posi) %= mod;
            // }
            (dp[i][j] += dp[i][j - 1]) %= mod;
        }
    }
    // for (int i = 0; i <= n; i++)
    // {
    //     int flag = 1;
    //     for (int j = i; j <= n; j++)
    //     {

    //     }
    // }
    // cerr << dp[1][2] << ' ';
    // for (int i = m; i <= n; i++) ans += dp[n - i][cnt];
    // for (int i = 0; i <= n; i++) ans += 
    for (int i = 0; i <= cnt; i++) dp[i][cnt] = dp[i][cnt] * fac[n - i] % mod;
    for (int i = 0; i <= cnt; i++)
    {
        int flag = 1;
        for (int j = i; j <= cnt; j++)
        {
            (res[i] += C(j, i) * flag % mod * dp[j][cnt]) %= mod;
            flag = mod - flag;
        }
        cerr << res[i] << ' ';
    }
    for (int i = 0; i <= cnt - m; i++) ans += res[i];
    cout << ans % mod << '\n';

    return 0;
}

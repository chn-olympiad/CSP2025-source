#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <ctime>
#include <random>
#include <chrono>

typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef unsigned int uint;

using namespace std;

const int MAXN = 510, mod = 998244353;

ll fac[MAXN];

int n, m;
char s[MAXN];

int c[MAXN], cnt[MAXN];
int a[MAXN], q;

ll f[2][MAXN][MAXN];

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> s + 1;
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
    for (int i = 1, j = 0; i <= n; i++)
    {
        if (s[i] == '1') a[++q] = j;
        else j++;
    }
    for (int i = 1; i <= n; i++) cin >> c[i], cnt[c[i]]++;
    for (int i = n - 1; i >= 0; i--) cnt[i] += cnt[i + 1];

    if (q < m) return cout << "0\n", 0;
    // for (int i = 1; i <= q; i++) cout << a[i] << ' '; cout << '\n';
    // for (int i = 0; i <= n; i++) cout << cnt[i] << ' '; cout << '\n';
    int p = 0;
    for (int i = 0; i <= q - m; i++) f[p][i][0] = 1;
    for (int i = q; i >= 1; i--)
    {
        memset(f[!p], 0, sizeof(f[!p]));
        for (int j = 0; j <= min(q - m, i); j++)
            for (int k = 0; k <= q - i; k++) if (f[p][j][k])
            {
                if (cnt[a[i] + j + 1] > k)
                {
                    f[!p][j][k + 1] = (f[!p][j][k + 1] + f[p][j][k] * (cnt[a[i] + j + 1] - k)) % mod;
                }
                if (j)
                {
                    f[!p][j - 1][k] = (f[!p][j - 1][k] + f[p][j][k]) % mod;
                    if (cnt[a[i] + j] > k) f[!p][j - 1][k + 1] = (f[!p][j - 1][k + 1] - f[p][j][k] * (cnt[a[i] + j] - k)) % mod;
                }
            }
        p ^= 1;
        // for (int j = 0; j <= q - m; j++, cout << '\n')
        //     for (int k = 0; k <= q; k++)
        //         cout << f[p][j][k] << ' ';
        // cout << '\n';
    }
    ll ans = 0;
    for (int i = 0; i <= q; i++) ans = (ans + f[p][0][i] * fac[n - i]) % mod;
    cout << (ans < 0 ? ans + mod : ans) << '\n';
    return 0;
}
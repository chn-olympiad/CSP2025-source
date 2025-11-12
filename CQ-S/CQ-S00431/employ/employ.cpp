#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned ui;
typedef unsigned long long ull;

const int MAXN = (1 << 18) + 5;
const ll MOD = 998244353ll;

int tt = 1;

int n, m;
string st;
int c[MAXN];
int f[MAXN][20];

void solve()
{
    cin >> n >> m >> st;
    st = " " + st;
    for (int i = 1; i <= n; i++) cin >> c[i];
    if (n > 18)
    {
        if (m == 1)
        {
            ll ans = 1;
            for (int i = 1; i <= n; i++) ans *= i, ans %= MOD;
            cout << ans << "\n";
            return;
        }
    }
    f[0][0] = 1;
    for (int s = 1; s < (1 << n); s++)
    {
        int cc = __builtin_popcount(s);
        for (int i = 0; i <= cc; i++) {
            int tmp = s;
            while (tmp) {
                int b = tmp & (-tmp);
                int j = __builtin_ctz(b) + 1;
                // cout << "debug: " << s << " " << i << " " << j << "\n"; 
                if (st[cc] == '0')
                {
                    if (i > 0)
                    {
                        f[s][i] += f[s - b][i - 1], f[s][i] %= MOD;
                    }
                }
                else if (i == 0)
                {
                    if (c[j] != 0) f[s][i] += f[s - b][i], f[s][i] %= MOD;
                }
                else if (c[j] > i)
                {
                    f[s][i] += f[s - b][i], f[s][i] %= MOD;
                }
                else if (c[j] != i)
                {
                    f[s][i] += f[s - b][i - 1], f[s][i] %= MOD;
                }
                tmp -= b;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; n - i >= m; i++) ans += f[(1 << n) - 1][i], ans %= MOD;
    cout << ans << "\n";
}

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    // scanf("%d", &tt);
    while (tt--) solve();    
    return 0;
}
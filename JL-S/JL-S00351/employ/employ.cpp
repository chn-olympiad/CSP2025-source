#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 510, mod = 998244353;

int n, m;
char s[N];
int c[N];
int f[1 << 18][19];
int cnt[1 << 18];

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    scanf("%d%d%s", &n, &m, s + 1);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &c[i]);
    bool flag1 = true;
    if (m != n) flag1 = false;
    if (flag1)
    {
        int ans = 1;
        for (int i = 1; i <= n; i ++ )
            if (s[i] == '0') ans = 0;
        for (int i = 1; i <= n; i ++ ) ans = (LL)ans * i % mod;
        printf("%d\n", ans);
    }
    else
    {
        f[0][0] = 1;
        for (int i = 1; i < 1 << n; i ++ ) cnt[i] = cnt[i ^ (i & -i)] + 1;
        for (int i = 0; i < (1 << n) - 1; i ++ )
            for (int j = 0; j < n; j ++ )
                if (!(i >> j & 1))
                {
                    int S = (i ^ (1 << j));
                    for (int k = 0; k <= cnt[S]; k ++ )
                    {
                        int t = k + (c[j + 1] <= k || s[cnt[S]] == '0');
                        //cout << i << ' ' << k << ' ' << S << ' ' << t << ' ' << cnt[S] << endl;
                        f[S][t] = (f[S][t] + f[i][k]) % mod;
                    }
                }
        //cout << f[(1 << n) - 1][2] << endl;
        int ans = 0;
        for (int k = 0; k <= n - m; k ++ ) ans = (ans + f[(1 << n) - 1][k]) % mod;
        printf("%d\n", ans);
    }

    return 0;
}
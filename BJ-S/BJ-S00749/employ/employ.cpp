#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MAXN2 = 18;
const LL MAXN = 1005;
const LL MOD = 998244353;
LL n, m, A[MAXN], fac[MAXN], f[(1 << MAXN2) + 5][MAXN2 + 1], g[MAXN][MAXN], cnt[MAXN]; string s;
int main()
{
    freopen("employ.in", "r", stdin); freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> s;
    fac[0] = 1; for(LL i = 1; i <= n; i ++) fac[i] = (fac[i - 1] * i) % MOD;
    if(n <= 18)
    {
        for(LL i = 0; i < n; i ++) cin >> A[i];
        f[0][0] = 1; s = ' ' + s;
        for(LL i = 1; i < (1 << n); i ++)
        {
            LL num = __builtin_popcount(i);
            for(LL j = 0; j < n; j ++)
            {
                if(!(i & (1 << j))) continue;
                for(LL k = 0; k < num; k ++)
                {
                    if(k >= A[j] || s[num] == '0') f[i][k + 1] = (f[i][k + 1] + f[i ^ (1 << j)][k]) % MOD;
                    else f[i][k] = (f[i][k] + f[i ^ (1 << j)][k]) % MOD;
                }
            }
        }
        LL ans = 0;
        for(LL i = 0; i <= n - m; i ++) ans = (ans + f[(1 << n) - 1][i]) % MOD;
        cout << ans << '\n';
        return 0;
    }
    else
    {
        for(LL i = 1; i <= n; i ++) { cin >> A[i]; if(A[i] > n) A[i] = n; }
        s = ' ' + s;
        if(m == n)
        {
            bool Flag = true;
            for(LL i = 1; i <= n; i ++) if(A[i] == 0) Flag = false;
            for(LL i = 1; i <= n; i ++) if(s[i] == '0') Flag = false;
            if(!Flag) cout << 0 << '\n';
            else cout << fac[n] << '\n';
            return 0;
        }
        else if(m == 1)
        {
            LL ans = fac[n], cnt0 = 0, anss;
            for(LL i = 1; i <= n; i ++) cnt[A[i]] ++;
            g[0][cnt[0]] = 1; // for(LL i = 0; i <= n; i ++) cout << cnt[i] << " ";
            // cout << '\n';
            for(LL i = 1; i <= n; i ++)
            {
                if(s[i] == '0')
                {
                    cnt0 ++;
                    for(LL j = 0; j <= n; j ++)
                        g[i][j + cnt[i]] = (g[i][j + cnt[i]] + g[i - 1][j]) % MOD;
                    continue;
                }
                for(LL j = 1; j <= n; j ++)
                    g[i][j - 1 + cnt[i]] = (g[i][j - 1 + cnt[i]] + g[i - 1][j] * j % MOD) % MOD;
            }
            anss = g[n][cnt0] * fac[cnt0] % MOD;
            cout << (ans - anss + MOD) % MOD << '\n';
            return 0;
        }
        else
        {
            cout << fac[n] << '\n';
        }
    }
    return 0;
}

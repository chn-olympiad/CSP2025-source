#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 998244353;

char s[505];
int cnt[505], pre[505];
ll F[505][505], G[505][505], A[505][505], C[505][505], fac[505];
inline void chkadd(ll &x, ll y) { (x += y) >= mod && (x -= mod); }

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0);

    int n, m; cin >> n >> m >> s + 1;
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        cnt[x]++;
    }
    for (int i = 0; i <= n; i++) pre[i] = cnt[i] + (i ? pre[i - 1] : 0);

    for (int i = 0; i <= n; i++)
    {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) C[i][j] = C[i - 1][j], chkadd(C[i][j], C[i - 1][j - 1]);
    }
    for (int i = 0; i <= n; i++)
    {
        A[i][0] = 1;
        for (int j = 1; j <= i; j++) A[i][j] = A[i][j - 1] * (i - j + 1) % mod;
    }
    fac[0] = 1; for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;

    F[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '1')
        {
            for (int j = 0; j < i; j++)
                for (int k = 0; k < i; k++)
                {
                    if (!F[j][k]) continue;
                    chkadd(G[j][k + 1], F[j][k]); int x = i - 1 - k;
                    for (int p = 0; p <= cnt[j + 1] && p <= k; p++)
                        (G[j + 1][k - p] += F[j][k] * (pre[j] - x) % mod * A[k][p] % mod * C[cnt[j + 1]][p]) %= mod;
                }
        }
        else
        {
            for (int j = 0; j < i; j++)
                for (int k = 0; k < i; k++)
                {
                    if (!F[j][k]) continue; int x = i - 1 - k;
                    for (int p = 0; p <= cnt[j + 1] && p <= k; p++)
                    {
                        (G[j + 1][k - p] += F[j][k] * (pre[j + 1] - p - x) % mod * A[k][p] % mod * C[cnt[j + 1]][p]) %= mod;
                        (G[j + 1][k - p + 1] += F[j][k] * A[k][p] % mod * C[cnt[j + 1]][p]) %= mod;
                    }
                }
        }
        for (int j = 0; j <= i; j++) for (int k = 0; k <= i; k++) F[j][k] = G[j][k], G[j][k] = 0;
    }

    ll ans = 0;
    for (int j = 0; j <= n - m; j++) (ans += F[j][n - pre[j]] * fac[n - pre[j]]) %= mod;
    cout << ans;
    return 0;
}
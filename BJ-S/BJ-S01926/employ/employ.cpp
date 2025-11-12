#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pii>
#define pb push_back
#define fi first
#define se second
using namespace std;
const int mod = 998244353;
int ksm(int a, int b)
{
    int t = 1;
    while (b)
    {
        if (b & 1) t = t * a % mod;
        a = a * a % mod, b >>= 1;
    }
    return t;
}
int fac[510], invfac[510];
int A(int n, int m)
{
    if (m < 0 || m > n) return 0;
    return fac[n] * invfac[n - m] % mod;
}
int C(int n, int m)
{
    if (m < 0 || m > n) return 0;
    return fac[n] * invfac[n - m] % mod * invfac[m] % mod;
}
int f[510], c[510], a[510], s[510], dp[20][20];
signed main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vi vec;
    for (int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        f[i] = ch - '0';
        if (f[i] == 1) vec.pb(i);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        a[c[i]]++;
    }
    s[0] = a[0];
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
    invfac[n] = ksm(fac[n], mod - 2);
    for (int i = n - 1; i >= 0; i--) invfac[i] = invfac[i + 1] * (i + 1) % mod;
    if (vec.size() <= 18)
    {
        int ans = 0;
        for (int o = 0; o < (1 << vec.size()); o++)
        {
            if (__builtin_popcount(o) < m) continue;
            int cnt = 0;
            vi v;
            for (int i = 0; i < vec.size(); i++)
            {
                v.pb(vec[i] - cnt - 1);
                if ((o >> i) & 1) cnt++;
            }
            v.pb(n);
            sort(v.begin(), v.end());
            v.erase(unique(v.begin(), v.end()), v.end());
            vpii w(v.size());
            cnt = 0;
            for (int i = 0; i < vec.size(); i++)
            {
                int x = lower_bound(v.begin(), v.end(), vec[i] - cnt - 1) - v.begin();
                if ((o >> i) & 1) w[x + 1].fi++;
                else w[x].se++;
                if ((o >> i) & 1) cnt++;
            }
            int sum = n - vec.size(), M = vec.size() - cnt;
            dp[0][0] = 1;
            for (int i = 0; i < v.size(); i++)
            {
                sum += w[i].fi;
                int t = s[v[i]] - (i == 0 ? 0 : s[v[i - 1]]);
                for (int j = 0; j <= M; j++) dp[i + 1][j] = 0;
                for (int j = 0; j <= M; j++)
                {
                    if (!dp[i][j]) continue;
                    for (int k = 0; k <= t && j + k <= M; k++)
                    {
                        dp[i + 1][j + k] = (dp[i + 1][j + k] + dp[i][j] * C(t, k) % mod * A(sum + j, t - k)) % mod;
                    }
                }
                M -= w[i].se;
                for (int j = 0; j <= M; j++) dp[i + 1][j] = dp[i + 1][j + w[i].se] * A(j + w[i].se, w[i].se) % mod;
                sum -= t - w[i].se;
            }
            ans = (ans + dp[v.size()][0]) % mod;
        }
        cout << ans << endl;
        return 0;
    }
    if (m == 1)
    {
        int sum = 0, ans = 1;
        for (int i = 1; i <= n; i++)
        {
            sum += a[i - 1];
            if (f[i] == 1) ans = ans * sum % mod, sum--;
        }
        sum += a[n];
        ans = ans * fac[sum] % mod;
        ans = (fac[n] - ans + mod) % mod;
        cout << ans << endl;
        return 0;
    }
    if (m == n)
    {
        for (int i = 1; i <= n; i++) if (f[i] == 0 || c[i] == 0)
        {
            cout << 0 << endl;
            return 0;
        }
        cout << fac[n] << endl;
        return 0;
    }
    
    return 0;
}
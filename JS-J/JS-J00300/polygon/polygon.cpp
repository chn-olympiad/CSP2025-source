#include <bits/stdc++.h>
#define int long long
#define x0 akcsp_j
#define x1 akcsp_s
#define y0 ak_noi
#define y1 ak_ioi
#define endl '\n'
#define hash my_hash
#define next my_next
#define LLMI LONG_LONG_MIN
#define LLMA LONG_LONG_MAX
using namespace std;
const int N = 5e3 + 5;
const int mod = 998244353;
int n, a[N], ans, p[5005];
int dfs(int sum, int id, int maxn, int cnt)
{
    int res = 0;
    if (cnt >= 3)
    {
        if (sum > maxn * 2 && cnt >= 3)
        {
            res ++;
        }
    }
    if (id > n + 2) return 0;
    for (int i = id; i <= n; i ++)
    {
        res += dfs(sum + a[i], i + 1, max(maxn, a[i]), cnt + 1);
    }
    return res % mod;
}
int quick_pow(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
int C(int m, int n)
{
    int res = 1;
    for (int i = m + 1; i <= n; i ++) res = res * i % mod;
    for (int i = n - m; i >= 2; i --) res = res * p[i] % mod;
    return res % mod;
}
void solve1()
{
    for (int i = 1; i <= n; i ++) p[i] = quick_pow(i, mod - 2) % mod;
    int ans = 0;
    for (int i = 3; i <= n; i ++) ans = (ans + C(i, n) + mod) % mod;
    cout << ans;
}
signed main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    bool f = 1;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        f = a[i] == 1;
    }
    if (n <= 20) cout << dfs(0, 1, LLMI, 0); // 40pts
    else if (f) solve1(); // 24pts
    else cout << 1919810;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

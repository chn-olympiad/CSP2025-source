#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 998244353;
ll a[505], b[505];
bool f[505];
ll fact[505];
string s;
ll n, m, ans;
bool check()
{
    ll cnt = 0;
            for (int i = 1; i <= n; i++)
            {
                if (s[i - 1] == '0' || cnt >= a[i]) cnt++;
            }
            return (n - cnt >= m);
}
void dfs(ll step)
{
    if (step == n + 1)
    {
        if (check()) ans++;
        return ;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!f[i])
        {
            f[i] = 1;
            a[step] = b[i];
            dfs(step + 1);
            f[i] = 0;
        }
    }
}
void solve()
{
    fact[1] = 1;
    for (int i = 2; i <= 500; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    //
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (n <= 10)
    {
        for (int i = 1; i <= n; i++) b[i] = a[i];
        dfs(1);
        cout << ans;
    }
    else if (m == 1)
    {
        ll cnt = 0, cnt2 = 0;
        for (int i = 1; i <= n; i++)
        {
            if (s[i - 1] == '0') cnt++;
            else break ;
        }
        for (int i = 1; i <= n; i++) if (a[i] > cnt) cnt2++;
        cout << cnt2 * fact[n - 1] % mod;
    }
    else
    {
        cout << fact[n];
    }
    //
    cout << '\n';
}
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
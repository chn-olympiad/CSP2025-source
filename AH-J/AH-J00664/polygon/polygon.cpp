#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 998244353;
ll f[5005];
ll a[5005];
ll n, ans;
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    f[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = a[i] + 1; j <= 5001; j++)
        {
            ans = ans + f[j];
            ans %= mod;
        }
        for (int j = 5001; j >= 5001 - a[i]; j--)
        {
            f[5001] += f[j];
            f[5001] %= mod;
        }
        for (int j = 5000 - a[i]; j >= 0; j--)
        {
            f[j + a[i]] += f[j];
            f[j + a[i]] %= mod;
        }
    }
    cout << ans << '\n';
    return 0;
}

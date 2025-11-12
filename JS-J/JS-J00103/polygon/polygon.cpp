#include <bits/stdc++.h>
using namespace std;
int n, a[50];
unsigned int ym;
unsigned int ans;
using ll = long long;
ll pow2(int exp)
{
    ll res = 1;
    for (int i = 1; i <= exp; i++)
    {
        res = (res * 2) % 998244353;
    }
    return res;
}
bool chk()
{
    int sum = 0;
    int maxx = 0;
    for (int i = 0; i < n; i++)
    {
        if ((ym >> i) & 1)
        {
            sum += a[i];
            maxx = max(maxx, a[i]);
        }
    }
    return (sum > 2 * maxx);
}
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    if (n > 32)
    {
        cout << (pow2(n) + 998244353 - 1 - n - n * (n - 1) / 2) % 998244353;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ym = 1; ym < (1 << n); ym++)
    {
        ans += chk();
    }
    cout << ans % 998244353;
    return 0;
}

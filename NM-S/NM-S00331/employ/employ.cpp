#include <bits/stdc++.h>
using namespace std;
int n, m;
int c[505];
string s;
const int mod = 998244353;
long long C(int a, int b)
{
    if (a == 1)
    {
        return b;
    }
    if (a == 0 || b == 0)
    {
        return 0;
    }
    if (a == b)
    {
        return 1;
    }
    long long x = 1, y = 1;
    int tmp = a;
    for (int i = 1; i <= tmp; i++)
    {
        x *= a;
        a--;
        y *= b;
        b--;
    }
    return y / x;
}
long long dowith(int m, int n)
{
    long long f = C(m, n);
    long long sc = 1;
    for (int i = 1; i <= m; i++)
    {
        sc *= i;
    }
    f *= sc;
    return f;
}
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    long long ans = 0;
    for (int i = m; i <= n; i++)
    {
        ans += dowith(i, n);
    }
    ans %= mod;
    cout << ans << endl;
    return 0;
}

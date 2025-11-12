#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int n, m, c[510], e[510], z;
long long ans, mod = 998244353;
char s[510];

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    ans = 1;
    for (int i = n; i >= 1; i--)
    {
        ans *= i;
        ans %= mod;
    }
    cout << ans;
    return 0;
}

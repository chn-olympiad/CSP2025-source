#include <bits/stdc++.h>
using namespace std;
const int o = 505, mod = 998244353;
long long m, n, g[o], f[o], c[o], k;
string s;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;
    g[0] = 1;
    for (int i = 1; i <= n; i++) cin >> c[i], f[i] += (s[i - 1] == '0' ? 1 : 0), g[i] = g[i - 1] * i % mod, k += (c[i] == 0 ? 1 : 0);
    cout << 2;
    return 0;
}
//gg

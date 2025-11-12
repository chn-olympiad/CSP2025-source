#include <bits/stdc++.h>
using namespace std;
const int N = 507, MOD = 998244353;
long long c[N];
long long n, m, ans = 1, t = 0;
string s;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    cin >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        if (c[i] == 0)
            t++;
    }
    n -= t;
    if (m == 1)
    {
        cout << n % MOD;
        return 0;
    }
    for (int i = 0; i < m; i++)
        ans = (ans * ((n - i) % MOD) ) % MOD;
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

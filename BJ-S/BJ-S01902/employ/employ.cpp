#include <bits/stdc++.h>
using namespace std;

const long long mod = 998244353;
long long n, m, c[1005], ans = 1;
string s;

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    for (long long i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    for (long long i = 2; i <= n; i++)
    {
        ans = ans * i % mod;
    }
    cout << ans;
    return 0;
}
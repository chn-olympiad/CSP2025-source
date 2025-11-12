#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
#define int long long
const int MOD = 998244353;

int n, m;
string s;
int a[MAXN];

int QuickPow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

signed main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n >> m;
    cin >> s;
    s = " " + s;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    int ans = 1;
    for (int i = 1; i <= n; i ++)
    {
        ans = ans * i % MOD;
    }
    cout << ans << "\n";

    return 0;
}
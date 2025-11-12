#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505, mod = 998244353;
ll n, ans, c[N][N], m;
int main()
{
    freopen ("employ.in", "r", stdin);
    freopen ("employ.out", "w", stdout);
    cin >> n >> m;
    string x;
    cin >> x;
    for (int i = 1; i <= n; i ++)
    {
        ll a;
        cin >> a;
    }
    ll num = 1;
    for (int i = 1; i <= n; i ++)
    {
        num = (num * i) % mod;
    }
    cout << num;
    return 0;
}
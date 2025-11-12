#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int n, m, c[505];
long long ans;
string s;
int A(int x, int y)
{
    long long res = 1;
    x = x%mod;
    y = y%mod;
    for (int i = y; i >= y-x+1; i--)
    {
        res = (res*i)%mod;
    }
    return res%mod;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    ans = A(m, n);
    cout << ans%mod;
    return 0;
}

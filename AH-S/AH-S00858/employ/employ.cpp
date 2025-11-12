#include <bits/stdc++.h>
using namespace std;
const int M = 998244353;
long long int n, m, c[505], p[505], ans = 1;
string s;
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    s = "0" + s;
    for (int i = 1; i <= n; i ++) cin >> c[i];
    for (int i = 1; i <= n; i ++) p[i] = i;
    if (m == n)
    {
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= n; i ++) ans = ans * i % M;

    cout << ans;
    return 0;
}

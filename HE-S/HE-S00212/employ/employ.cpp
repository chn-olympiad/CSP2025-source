#include <bits/stdc++.h>
using namespace std;
int n, m, cnt = 0;
const int mod = 998244353;
int c[505];
string s;
int main()
{
    freopen ("employ.in", "r", stdin);
    freopen ("employ.out", "w", stdout);
    ios :: sync_with_stdio (false);
    cin.tie (0);
    cout.tie (0);
    cin >> n >> m;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    do
    {
        cnt = (cnt + 1) % mod;
    }while (next_permutation (c, c + n));
    cout << cnt << '\n';
    return 0;
}

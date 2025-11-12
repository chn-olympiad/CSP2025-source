#include <bits/stdc++.h>
using namespace std;
int n, m, c[503];
unsigned long mod = 998244353, dp[503][503];
string s;
int main()
{
    //freopen("employ.in", "r", stdin);
    //freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    sort(c, c+n);
    dp[0][0] = 1;
    dp[0][1] = 1;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int a[100];
int n;
long long ans = 0;
const long long mod = 998244353;
void dfs (int pos, int last, int sum, int cnt)
{
    if (a[last] * 2  < sum && last == pos - 1 && cnt >= 3)
    {
        ans = (ans + 1) % mod;
    }
    if (pos == n + 1)
    {
        return;
    }
    dfs(pos + 1, last, sum, cnt);
    dfs(pos + 1, pos, sum + a[pos], cnt + 1);
}
int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort (a + 1, a + n + 1);
    dfs(1, 0, 0, 0);
    cout << ans << endl;
    return 0;
}
// 40pts sum:300pts

#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
int ans;
constexpr int mod = 998244353;
bitset<1 << 20 + 1> st;
void dfs(int x, int max_, int sum, int num, int mask)
{
    if (num >= 3 && sum > 2 * max_ && !st[mask])
    {
        ans++;
        ans %= mod;
        st[mask] = 1;
    }
    if (x > n)
    {
        return;
    }
    dfs(x + 1, max(max_, a[x]), sum + a[x], num + 1, mask | (1 << x));
    dfs(x + 1, max_, sum, num, mask);
}
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dfs(1, 0, 0, 0, 0);
    cout << ans;
}
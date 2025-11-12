#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int n, a[5005];
long long ans;
bool f[5005];
void dfs(int k, int m)
{
    if(k > n)
    {
        if(m < 3) return;
        int sum = 0, maxn = -1;
        for(int i = 1; i <= n; i++)
            if(f[i]) sum += a[i], maxn = max(maxn, a[i]);
        if(sum > 2 * maxn) ans++;
        ans %= MOD;
        return;
    }
    dfs(k + 1, m);
    f[k] = 1;
    dfs(k + 1, m + 1);
    f[k] = 0;
}
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    dfs(1, 0);
    cout << ans;
    return 0;
}

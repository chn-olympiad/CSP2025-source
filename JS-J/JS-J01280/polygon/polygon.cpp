#include <iostream>
using namespace std;

const int MOD = 998244353;
int n, a[5010], ans;

void dfs(int x, int sum, int maxn)
{
    if (x == n + 1)
    {
        ans = (ans + (sum > maxn * 2)) % MOD;
        return;
    }
    dfs(x+1, sum+a[x], max(maxn, a[x]));
    dfs(x+1, sum, maxn);
}

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (n <= 25)
    {
        dfs(1, 0, -2e9);
    }
    else
    {
        long long mul = n * (n-1), under = 2;
        for (int i = 3; i <= n; i++)
        {
            mul *= 1ll * (n - i + 1);
            under *= 1ll * i;
            ans += mul / under;
        }
    }
    cout << ans << endl;
    return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;


const int mod = 998244353;
int maxn = -2e9, n, a[5005];
bool cmp(int x, int y)
{
    return x > y;
}
long long c[5005][5005], ans;

void dfs(int last, int step, int maxn, long long sum)
{
    if (sum > 2 * maxn)
    {
        for (int i = 1;i <= n-last;i++)
        {
            ans = (ans + c[n-last][i]) % mod;
        }
        ans = (ans + 1) % mod;
        return;
    }
    if (step == n + 1) return;
    for (int i = last + 1;i <= n;i++)
    {
        dfs(i, step + 1, max(maxn, a[i]), sum + a[i]);
    }
}


int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        maxn = max(maxn, a[i]);
    }
    sort(a + 1, a + n + 1, cmp);
    c[0][0] = 1, c[0][1] = 0;
        for(int i = 1;i <= n-1;i++)
        {
            c[i][0] = 1;
            for (int j = 1;j <= i;j++) c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
        }
    if (maxn == 1)
    {
        for (int i = 2;i <= n-1;i++)
        {
            for (int j = 2;j <= i;j++) ans = (ans + c[i][j]) % mod;
        }
        cout << ans;
    }
    else
    {
        dfs(0, 1, 0, 0);
        cout << ans;
    }
    return 0;
}

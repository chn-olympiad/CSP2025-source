#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
int n,ans;
int a[5005];
bool f[5005];

void mk()
{
    int sum = 0,maxn = -1;
    for (int i = 1;i <= n;i++)
    {
        if (f[i])
        {
            sum += a[i];
            maxn = max(maxn,a[i]);
            cout << a[i] << " ";
        }
    }
    if (sum > 2 * maxn)
        ans = (ans + 1) % MOD;
    cout << ans << "\n";
    return ;
}

void dfs(int x,int c)
{
    if (c >= 3)
        mk();
    if (x == n + 1)
        return ;
    f[x] = true;
    dfs(x + 1,c + 1);
    f[x] = false;
    dfs(x + 1,c);
    return ;
}

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++)
        cin >> a[i];
    cout << n << "\n";
    dfs(1,0);
    cout << ans % MOD;
    return 0;
}

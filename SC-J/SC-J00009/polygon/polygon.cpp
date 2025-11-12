#include <iostream>
#include <cstdio>
using namespace std;

int a[5005],ans,n;
int f[5005][5005];
const int mod = 998244353;
void dfs(int step,int maxn,int sum)
{
    if (step > n)
    {
        if (sum > 2 * maxn)
        {
            ans++;
        }
        return;
    }
    dfs(step + 1,max(maxn,a[step]),sum + a[step]);
    dfs(step + 1,maxn,sum);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >>n;
    for (int i = 1; i <= n; i++)
    {
        cin >>a[i];
    }
    if (n <= 20)
    {
        dfs(1,0,0);
        cout <<ans;
    }
    else
    {
        f[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            f[i][0] = 1;
            f[i][i] = 1;
            for (int j = 1; j < i; j++)
            {
                f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
                f[i][j] %= mod;
            }
        }
        for (int i = 3; i <= n; i++)
        {
            ans += f[n][i];
            ans %= mod;
        }
        cout <<ans;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
bool vis[5005];
long long n,a[5005],ans;
int st = 0;
const int mod = 998244353;
void dfs(int x,int step,long long mx,long long sum)
{
    if (x == step)
    {
        if (sum > 2 * mx)
        {
            ans = (ans + 1) % mod;
        }
        return ;
    }
    for (int i = 1;i <= n;i++)
    {
        if (vis[i] == 1) continue;
        vis[i] = 1;
        st++;
        dfs(x,step + 1,max(mx,a[i]),sum + a[i]);

    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    int f = 0;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        if (a[i] != 1)f = 1;
    }
    if (f == 0)
    {
        ans = 1;
        long long mul = 1;
        for (int i = 1;i <= n;i++)
        {
            int t = n;
            for (int j = 1;j <= i;j++)
            {
                mul *= t;
                t--;
            }
        }
        ans = (ans + mul % mod) % mod;
        cout <<ans << endl;
        return 0;
    }
    for (int i = 3;i <= n;i++)
    {
        dfs(i,0,0,0);
        memset(vis,0,sizeof(vis));
    }
    cout <<ans <<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n,T;
int nums[N];
int po[N][4];
int nb[N];
int ans = 0;
void dfs(int u,int n)
{
    if (u > n)
    {
        int nb[4] = {0};
        for (int i = 1;i <= n;i ++)
        {
            nb[nums[i]] ++;
        }
        if (nb[1] > n / 2 || nb[2] > n / 2 || nb[3] > n / 2)
        {
            return;
        }
        int res = 0;
        for (int i = 1;i <= n;i ++)
        {
            res += po[i][nums[i]];
        }
        ans = max(ans,res);
        return;
    }
    for (int i = 1;i <= 3;i ++)
    {
        nums[u] = i;
        dfs(u + 1,n);
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> T;
    while (T --)
    {
        cin >> n;
        ans = 0;
        for (int i = 1;i <= n;i ++)
        {
            for (int j = 1;j <=3;j ++)
            {
                scanf("%d",&po[i][j]);
            }
        }

        dfs(1,n);
        cout << ans << endl;
    }
    return 0;
}

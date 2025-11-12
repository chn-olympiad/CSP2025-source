#include <bits/stdc++.h>
using namespace std;
int a[5005],n;
const int MOD = 998244353;
int ans = 0;
void dfs(int step,int tot,int num)
{
    if (step > n)
    {
        if (num >= 3)
        {
            ans++;
        }
        return;
    }
    if ((tot + a[step]) > (a[step] * 2) || num < 3)
    {
        dfs(step + 1,tot + a[step],num + 1);
    }

    dfs(step + 1,tot,num);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    dfs(1,0,0);
    cout << ans << endl;
    return 0;
}

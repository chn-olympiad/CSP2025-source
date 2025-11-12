#include <bits/stdc++.h>
using namespace std;
int a[100005][5], n, cnt[5], ans;
void dfs(int step, int sum)
{
    if (step > n)
    {
        ans = max(ans, sum);
        return;
    }
    for (int i = 1; i <= 3; i++)
    {
        if (cnt[i] + 1 <= n / 2)
        {
            cnt[i]++;
            dfs(step + 1, sum + a[step][i]);
            cnt[i]--;
        }
    }
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    for (cin >> t; t; t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                cin >> a[i][j];
            }
        }
        ans = -1;
        dfs(1, 0);
        cout << ans << endl;
    }
    return 0;
}

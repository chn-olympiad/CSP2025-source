#include <bits/stdc++.h>
using namespace std;
int n;
const int MAXN = 5005;
int a[MAXN], pre[MAXN];
//int amax;
int ans = 0;

// hasChosen  = totalLength
int dp[MAXN];

void dfs(int hasChosen, int curridx, int total, int nowmax)
{
    if (total > nowmax * 2 && hasChosen >= 3)
    {
        //cout << total << endl;
        ans++;
    }
    if (hasChosen >= n || curridx > n)
    {
        return;
    }
    for (int i = curridx + 1; i <= n; i++)
    {
        if (hasChosen + n - i + 1 < 3) break;
        dfs(hasChosen + 1, i, total + a[i], max(nowmax, a[i]));
    }
}
int getBlock(int l, int r)
{
    return pre[r] - pre[l - 1];
}
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    if (n < 3)
    {
        cout << 0 << endl;
    }
    else
    {
        // normal
        // IO : IN
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            pre[i] = pre[i - 1] + a[i];
        }
        // blatant dfs
        dfs(0, 0, 0, 0);
        cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
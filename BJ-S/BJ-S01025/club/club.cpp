#include <bits/stdc++.h>
using namespace std;
int t, n, a[100005][3], b[100005], a1 = 1, a2 = 1;
int ans = 0;

bool cmp(int x, int y)
{
    return x > y;
}

void dfs(int dth, int cur, int x, int b, int c)
{
    if (dth == n+1)
    {
        if (cur > ans)
            ans = cur;
        return ;
    }
    if (x < n / 2)
        dfs(dth+1, cur+a[dth][0], x+1, b, c);
    if (b < n / 2)
        dfs(dth+1, cur+a[dth][1], x, b+1, c);
    if (c < n / 2)
        dfs(dth+1, cur+a[dth][2], x, b, c+1);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            if (a[i][2] != 0)
                a2 = 0;
            if (a[i][1] != 0)
                a1 = 0;
            b[i] = a[i][0];
        }
        if (a1)
        {
            sort(b+1, b+n+1, cmp);
            for (int i = 1; i <= n / 2; i++)
                ans += b[i];
        }
        else
            dfs(1, 0, 0, 0, 0);
        cout << ans << endl;
    }
    return 0;
}

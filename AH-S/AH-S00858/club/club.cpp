#include <bits/stdc++.h>
using namespace std;
int t, n, a[100001][4], num[4];
long long int ans;
int b[100005];
void dfs(int i, long long int cans)
{
    if (i == n + 1) ans = max(ans, cans);
    for (int j = 1; j <= 3; j ++)
    {
        if (num[j] < n / 2)
        {
            cans += a[i][j];
            num[j] ++;
            dfs(i + 1, cans);
            num[j] --;
            cans -= a[i][j];
        }
    }
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t --)
    {
        cin >> n;
        num[1] = num[2] = num[3] = 0, ans = 0;
        for (int i = 1; i <= n; i ++) cin >> a[i][1] >> a[i][2] >> a[i][3];
        dfs(1, 0);
        cout << ans << "\n";
    }
    return 0;
}

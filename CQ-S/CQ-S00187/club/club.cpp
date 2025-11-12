#include <bits/stdc++.h>
using namespace std;
int n, a[100005][3], sum[3], m, c[100005], t;
bool cmp(int x, int y)
{
    return x >= y;
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        cin >> n;
        sum[0] = 0;
        sum[1] = 0;
        sum[2] = 0;
        for (int i = 1; i <= n; i++)
        {
            c[i] = -20005;
            for (int j = 0; j <= 2; j++)
            {
                cin >> a[i][j];
                sum[j] += a[i][j];
            }
        }
        if (sum[0] >= sum[1] && sum[0] >= sum[2])
        {
            m = 0;
        }
        else if (sum[1] >= sum[2])
        {
            m = 1;
        }
        else
        {
            m = 2;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= 2; j++)
            {
                if (j == m)
                {
                    continue;
                }
                c[i] = max(c[i], a[i][j] - a[i][m]);
            }
        }
        sort(c + 1, c + n + 1, cmp);
        for (int i = 1; i <= n / 2; i++)
        {
            sum[m] += c[i];
        }
        cout << sum[m] << endl;
    }
    return 0;
}
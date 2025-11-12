#include <bits/stdc++.h>
using namespace std;

int p[100005][4], ne[100005];

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int num0 = 0;
        memset(p, 0, sizeof(p));
        for (int i = 1; i <= n; ++i)
        {
            cin >> p[i][1] >> p[i][2] >> p[i][3];
            if (p[i][2] == 0) num0++;
        }
        if (num0 == n)
        {
            for (int i = 1; i <= n; ++i) ne[i] = p[i][1];
            sort(ne + 1, ne + n + 1, cmp);
            int ans = 0;
            for (int i = 1; i <= n / 2; ++i)
            {
                ans += ne[i];
            }
            cout << ans << endl;
        }
        else if (n == 2)
        {
            int x = max(p[1][1] + p[2][2], max(p[1][1] + p[2][3], max(p[1][2] + p[2][3], max(p[1][2] + p[2][1], max(p[1][3] + p[2][1], p[1][3] + p[2][2])))));
            cout << x << endl;
        }
    }
    return 0;
}

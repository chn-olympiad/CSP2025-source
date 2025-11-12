#include<bits/stdc++.h>
using namespace std;
int n, a[100005][4], t, b[100005][4];
bool c[100005];
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    for (int e = 1;e <= t;e++)
    {
        cin >> n;
        int ans = 0, x = 0, y = 0, z = 0;
        for (int i = 1;i <= n;i++)
        {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            ans += max(a[i][1], max(a[i][2], a[i][3]));
            if (a[i][1] >= a[i][2] and a[i][1] >= a[i][3]) x++;
            if (a[i][2] >= a[i][1] and a[i][2] >= a[i][3]) y++;
            if (a[i][3] >= a[i][2] and a[i][3] >= a[i][1]) z++;
            b[i][1] = a[i][1] - max(a[i][1], max(a[i][2], a[i][3]));
            b[i][2] = a[i][2] - max(a[i][1], max(a[i][2], a[i][3]));
            b[i][3] = a[i][3] - max(a[i][1], max(a[i][2], a[i][3]));
        }
        if (x > n / 2)
        {
            for (int i = 1;i <= n;i++)
            {
                if(b[i][1] == 0)
                {
                    b[i][0] = max(b[i][2], b[i][3]);
                    c[i] = 1;
                }
            }
            int f;
            b[0][0] = -100000;
            for (int i = 1;i <= x - (n / 2);i++)
            {
                f = 0;
                for (int j = 1;j <= n;j++)
                {
                    if (c[j] and b[j][0] > b[f][0])
                        f = j;
                }
                ans += b[f][0];
                c[f] = 0;
            }
        }
        if (y > n / 2)
        {
            for (int i = 1;i <= n;i++)
            {
                if(b[i][2] == 0)
                {
                    b[i][0] = max(b[i][1], b[i][3]);
                    c[i] = 1;
                }
            }
            int f;
            b[0][0] = -100000;
            for (int i = 1;i <= y - (n / 2);i++)
            {
                f = 0;
                for (int j = 1;j <= n;j++)
                {
                    if (c[j] and b[j][0] > b[f][0])
                        f = j;
                }
                ans += b[f][0];
                c[f] = 0;
            }
        }
        if (z > n / 2)
        {
            for (int i = 1;i <= n;i++)
            {
                if(b[i][3] == 0)
                {
                    b[i][0] = max(b[i][2], b[i][1]);
                    c[i] = 1;
                }
            }
            int f;
            b[0][0] = -100000;
            for (int i = 1;i <= z - (n / 2);i++)
            {
                f = 0;
                for (int j = 1;j <= n;j++)
                {
                    if (c[j] and b[j][0] > b[f][0])
                        f = j;
                }
                ans += b[f][0];
                c[f] = 0;
            }
        }
        cout << ans << endl;
        for (int i = 1;i <= n;i++) c[i] = 0;
    }
    return 0;
}


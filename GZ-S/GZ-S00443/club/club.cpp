//GZ-S00443 华麟 郭一菲
#include <bits/stdc++.h>
using namespace std;
long long a[105], b[105], c[10005], d[10005];
f{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int cnt = 0;
        long long maxn = -1000;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i] >> b[i] >> c[i];
        }
        if (n == 2)
        {
            maxn = max(a[1] + b[2], a[1] + c[2]);
            maxn = max(maxn, a[2] + b[1]);
            maxn = max(maxn, c[2] + b[1]);
            maxn = max(maxn, c[1] + a[2]);
            maxn = max(maxn, c[1] + b[2]);
        }
        else if (n == 4)
        {

            for (int i1 = 1; i1 <= 3; i1++)
            {
                for (int i2 = 1; i2 <= 3; i2++)
                {
                    for (int i3 = 1; i3 <= 3; i3++)
                    {
                        for (int i4 = 1; i4 <= 3; i4++)
                        {
                            if ((i1 == i2 && i1 == i3) ||(i1 == i2) && (i1 == i4) || (i2 == i3) && (i2 == i4) || (i1 == i3) && (i1 == i4))break;
                            long long x, y, z, q;
                            if (i1 == 1)x = a[1];
                            if (i1 == 2)x = b[1];
                            if (i1 == 3)x = c[1];
                            if (i2 == 1)y = a[2];
                            if (i2 == 2)y = b[2];
                            if (i2 == 3)y = c[2];
                            if (i3 == 1)z = a[3];
                            if (i3 == 2)z = b[3];
                            if (i3 == 3)z = c[3];
                            if (i4 == 1)q = a[4];
                            if (i4 == 2)q = b[4];
                            if (i4 == 3)q = c[4];
                            maxn = max(maxn, x + y + z + q);
                        }
                    }
                }
            }
        }
        else{
            maxn = 0;
            sort(a + 1, a + n + 1);
            for (int i = n; i > n / 2; i--)
            {

                maxn += a[i];
            }
        }
        cout << maxn<< endl;
    }
    return 0;
}

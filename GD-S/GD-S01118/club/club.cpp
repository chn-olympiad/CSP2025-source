#include <cstdio>
#include <cstring>
#include <algorithm>
#define max(_x, _y) (_x > _y ? _x : _y)

using namespace std;

int t, n, x, y, ans, id[3], b[100005], a[100005][3], f[205][105][105][3];

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (register int i = 1; i <= n; ++i)
        {
            scanf("%d%d%d", a[i], a[i] + 1, a[i] + 2);
        }
        if (n > 1000)
        {
            for (register int i = 1; i <= n; ++i)
            {
                b[i] = a[i][0];
            }
            sort(b + 1, b + n + 1);
            ans = 0;
            for (register int i = n / 2 + 1; i <= n; ++i)
            {
                ans += b[i];
            }
            printf("%d\n", ans);
            continue;
        }
        memset(f, -0x3f, sizeof(f));
        f[0][0][0][0] = f[0][0][0][1] = f[0][0][0][2] = 0;
        for (register int i = 1; i <= n; ++i)
        {
            for (id[0] = 0; id[0] <= n / 2; ++id[0])
            {
                for (id[1] = 0; id[1] <= n / 2 && id[0] + id[1] <= i; ++id[1])
                {
                    id[2] = i - id[0] - id[1];
                    if (id[2] > n / 2)
                    {
                        continue;
                    }
                    for (register int chose = 0; chose < 3; ++chose)
                    {
                        x = y = 0;
                        if (chose == 0)
                        {
                            x = 1;
                        }
                        else if (chose == 1)
                        {
                            y = 1;
                        }
                        if (id[chose] == 0)
                        {
                            continue;
                        }
                        for (register int j = 0; j < 3; ++j)
                        {
                            if (f[i - 1][id[0] - x][id[1] - y][j] < 0)
                            {
                                continue;
                            }
                            f[i][id[0]][id[1]][chose] = max(f[i][id[0]][id[1]][chose], f[i - 1][id[0] - x][id[1] - y][j] + a[i][chose]);
                        }
                    }
                }
            }
        }
        ans = 0;
        for (register int i = 0; i <= n / 2; ++i)
        {
            for (register int j = 0; j <= n / 2; ++j)
            {
                for (register int k = 0; k < 3; ++k)
                {
                    ans = max(ans, f[n][i][j][k]);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

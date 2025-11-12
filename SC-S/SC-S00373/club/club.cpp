#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int a[N][4], d[N], n, ans, sum, val[N];

void solve()
{
    ans = sum = 0;
    scanf("%d", &n);
    int tot[4] = {0, 0, 0, 0};
    for (int i = 1;i <= n;++ i)
    {
        d[i] = 0;
        int mx = 0;
        for (int j = 1;j <= 3;++ j)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j] >= mx)
                d[i] = j, mx = a[i][j];
        }
        ++ tot[d[i]];
    }
    for (int i = 1;i <= n;++ i)
        ans += a[i][d[i]];
    for (int i = 1;i <= 3;++ i)
        if (tot[i] > n / 2)
        {
            int cnt = 0;
            for (int j = 1;j <= n;++ j)
                if (d[j] == i)
                {
                    int mx = 0;
                    for (int k = 1;k <= 3;++ k)
                        if (i != k)
                            mx = max(mx, a[j][k]);
                    val[++ cnt] = mx - a[j][i];  
                }
            sort(val + 1, val + 1 + cnt);
            for (int i = cnt;i > n / 2;-- i)
                ans += val[i];
        }
    printf("%d\n", ans);
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T --)
        solve();
    fclose(stdin);
    fclose(stdout);

    return 0;
}
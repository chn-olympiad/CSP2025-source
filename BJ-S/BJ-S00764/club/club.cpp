#include <bits/stdc++.h>
using namespace std;

int T, n, x, cnt[3], a[100005][3], b[100005], maxid[100005];
long long ans;

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    scanf("%d", &T);
    for(int tt = 1; tt <= T; tt++)
    {
        ans = cnt[0] = cnt[1] = cnt[2] = 0;
        x = -1;

        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
            maxid[i] = 0;
            for(int j = 0; j < 3; j++)
            {
                if(a[i][j] > a[i][maxid[i]])  maxid[i] = j;
            }
            cnt[maxid[i]]++;
            ans += a[i][maxid[i]];
        }
        for(int j = 0; j < 3; j++)
        {
            if(cnt[j] > (n + 1) / 2)  x = j;
        }
        if(x == -1)
        {
            printf("%lld\n", ans);
            continue;
        }
        for(int i = 1; i <= n; i++)
        {
            b[i] = 1e9;
            if(maxid[i] == x)
            {
                int num = a[i][maxid[i]];
                for(int j = 0; j < 3; j++)
                {
                    if(x != j && num - a[i][j] < b[i])  b[i] = num - a[i][j];
                }
            }
        }
        sort(b + 1, b + n + 1);
        for(int i = 1; i <= cnt[x] - (n + 1) / 2; i++)
        {
            ans -= b[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}

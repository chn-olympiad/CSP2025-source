#include <bits/stdc++.h>
using namespace std;

long long T, n, ans;
int score[100005][4], cnt[4];

void dfs(int now, long long sum)
{
    if (now == n + 1)
    {
        ans = max(ans, sum);
        return;
    }

    for (int i = 1; i <= 3; i++)
    {
        if ((cnt[i] + 1) * 2 <= n)
        {
            cnt[i]++;
            dfs(now + 1, sum + score[now][i]);
            cnt[i]--;
        }
    }
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    scanf("%lld", &T);
    while (T--)
    {
        scanf("%lld", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d%d%d", &score[i][1], &score[i][2], &score[i][3]);

        ans = 0;
        dfs(1, 0);
        printf("%lld\n", ans);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
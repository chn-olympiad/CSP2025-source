#include <cstdio>
#include <algorithm>
using namespace std;

#define N (100000 + 10)

struct node_t
{
    int a, b;

    inline bool operator<(node_t t) {
        return a < t.a;
    }
};

node_t t[N][3];
node_t cost[N];

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d%d", &t[i][0].a, &t[i][1].a, &t[i][2].a);
            t[i][0].b = 0, t[i][1].b = 1, t[i][2].b = 2;
        }

        int ans = 0, cnt[3] = {0, 0, 0};
        for (int i = 1; i <= n; i++)
        {
            sort(t[i], t[i] + 3);
            ans += t[i][2].a;
            cnt[t[i][2].b]++;
            cost[i] = {t[i][2].a - t[i][1].a, i};
        }
        
        int res = max(max(cnt[0], cnt[1]), cnt[2]);
        int flag = 0;
        if (res == cnt[1])
            flag = 1;
        if (res == cnt[2])
            flag = 2;
        sort(cost + 1, cost + n + 1);
        for (int i = 1; res > n / 2; i++)
            if (t[cost[i].b][2].b == flag)
                ans -= cost[i].a, res--;

        printf("%d\n", ans);
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
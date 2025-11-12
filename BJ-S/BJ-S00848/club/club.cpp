#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 100010
using namespace std;
int n;
int a[MAXN][6];
int total[4];

void solve()
{
    scanf("%d", &n);
    memset(total, 0 , sizeof(total));
    memset(a, 0, sizeof(a));
    int maxHas = n >> 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= 3; ++j)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j] > a[i][0])
            {
                a[i][0] = a[i][j];
                a[i][5] = j;
            }
        }
        for (int j = 1; j <= 3; ++j)
        {
            if (a[i][j] == a[i][0]) continue;
            a[i][4] = max(a[i][4], a[i][j]);
        }
        a[i][4] = a[i][4] - a[i][0];
        ++total[a[i][5]];
    }

    int notOk = -1;
    for (int j = 1; j <= 3; ++j)
        if (total[j] > maxHas)
    {
        notOk = j;
        break;
    }

    int res = 0;
    for (int i = 1; i <= n; ++i)
        res += a[i][0];
    if (notOk != -1)
    {
        int swipOutNum = total[notOk] - maxHas;
        priority_queue<int> all = {};
        for (int i = 1; i <= n; ++i)
            if (a[i][5] == notOk)
                all.emplace(a[i][4]);
        while (swipOutNum-- && !all.empty())
        {
            int k = all.top();
            all.pop();
            res += k;
        }
    }

    printf("%d\n", res);
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}

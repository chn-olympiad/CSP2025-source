#include <stdio.h>
#include <queue>

int i, n, sum, t, a[3];
std::priority_queue<int, std::vector<int>, std::greater<int>> queue[3];

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (i = 0; i < n; ++i)
        {
            scanf("%d%d%d", a, a + 1, a + 2);
            if (a[0] >= a[1] && a[1] >= a[2])
            {
                queue[0].push(a[0] - a[1]);
                sum += a[0];
            }
            else if (a[0] >= a[2] && a[2] >= a[1])
            {
                queue[0].push(a[0] - a[2]);
                sum += a[0];
            }
            else if (a[1] >= a[0] && a[0] >= a[2])
            {
                queue[1].push(a[1] - a[0]);
                sum += a[1];
            }
            else if (a[1] >= a[2] && a[2] >= a[0])
            {
                queue[1].push(a[1] - a[2]);
                sum += a[1];
            }
            else if (a[2] >= a[0] && a[0] >= a[1])
            {
                queue[2].push(a[2] - a[0]);
                sum += a[2];
            }
            else if (a[2] >= a[1] && a[1] >= a[0])
            {
                queue[2].push(a[2] - a[1]);
                sum += a[2];
            }
        }
        for (i = 0; i < 3; ++i)
            while (queue[i].size() << 1 > n)
            {
                sum -= queue[i].top();
                queue[i].pop();
            }
        printf("%d\n", sum);
        sum = 0;
        for (i = 0; i < 3; ++i)
            while (!queue[i].empty())
                queue[i].pop();
    }

    return 0;
}

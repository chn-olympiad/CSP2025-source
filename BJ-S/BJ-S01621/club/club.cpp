#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5;

int a[N][3];

pair <int, int> c1[N], c2[N], c3[N];

bool cmp(pair<int, int> x, pair<int, int> y)
{
    return x.second < y.second;
}

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
        int cur1 = 0, cur2 = 0, cur3 = 0, sum = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
            if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2])
            {
                sum += a[i][0];
                pair <int, int> t;
                t.first = a[i][0];
                t.second = a[i][0] - max(a[i][1], a[i][2]);
                c1[++cur1] = t;
            }
            else if (a[i][1] >= a[i][0] && a[i][1] >= a[i][2])
            {
                sum += a[i][1];
                pair<int, int> t;
                t.first = a[i][1];
                t.second = a[i][1] - max(a[i][0], a[i][2]);
                c2[++cur2] = t;
            }
            else
            {
                sum += a[i][2];
                pair <int, int> t;
                t.first = a[i][2];
                t.second = a[i][2] - max(a[i][0], a[i][1]);
                c3[++cur3] = t;
            }
        }
        if (cur1 > n / 2)
        {
            sort (c1 + 1, c1 + cur1 + 1, cmp);
            for (int i = 1; i <= cur1 - (n / 2); i++)
            {
                sum -= c1[i].second;
            }
        }
        if (cur2 > n / 2)
        {
            sort (c2 + 1, c2 + cur2 + 1, cmp);
            for (int i = 1; i <= cur2 - (n / 2); i++)
            {
                sum -= c2[i].second;
            }
        }
        if (cur3 > n / 2)
        {
            sort (c3 + 1, c3 + cur3 + 1, cmp);
            for (int i = 1; i <= cur3 - (n / 2); i++)
            {
                sum -= c3[i].second;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
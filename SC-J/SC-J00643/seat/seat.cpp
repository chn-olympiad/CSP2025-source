#include <bits/stdc++.h>
using namespace std;

struct node
{
    int v, id;
};

const int N = 105;
node a [N];
int h [N], l [N];

bool cmp (node x, node y)
{
    return x.v > y.v;
}

int main ()
{
    freopen ("seat.in", "r", stdin);
    freopen ("seat.out", "w", stdout);
    int n, m;
    scanf ("%d%d", &n, &m);
    int cur = 0;
    for (int i = 1; i <= m; i++)
    {
        if (i & 1)
        {
            for (int j = 1; j <= n; j++)
            {
                h [++cur] = j;
                l [cur] = i;
            }
        }
        else
        {
            for (int j = n; j >= 1; j--)
            {
                h [++cur] = j;
                l [cur] = i;
            }
        }
    }
    for (int i = 1; i <= n * m; i++)
    {
        scanf ("%d", &a [i].v);
        a [i].id  = i;
    }
    sort (a + 1, a + n * m + 1, cmp);
    for (int i = 1; i <= n * m; i++)
    {
        if (a [i].id == 1)
        {
            printf ("%d %d\n", l [i], h [i]);
            return 0;
        }
    }
    return 0;
}
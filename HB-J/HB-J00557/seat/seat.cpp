#include <bits/stdc++.h>
using namespace std;
struct Student
{
    int g, x, y;
} a[101], k;
bool cmp(Student a, Student b)
{
    return a.g > b.g;
}
int n, m, now;
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n * m; i++)
        scanf("%d", &a[i].g);
    k = a[1];
    sort(a + 1, a + n * m + 1, cmp);
    now = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 1)
        {
            for (int j = 1; j <= m; j++)
            {
                a[now].x = i;
                a[now++].y = j;
            }
        }
        else
        {
            for (int j = m; j >= 1; j--)
            {
                a[now].x = i;
                a[now++].y = j;
            }
        }
    }
    for (int i = 1; i <= n * m; i++)
    {
        if (a[i].g == k.g)
        {
            printf("%d %d", a[i].x, a[i].y);
            return 0;
        }
    }
    return 0;
}

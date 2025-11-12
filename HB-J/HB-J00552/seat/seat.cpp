#include <bits/stdc++.h>
using namespace std;
int n, m, cnt, c, r, a[110];
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d%d", &n, &m), scanf("%d", &a[1]);
    for (int i = 2; i <= n * m; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] > a[1])
            cnt++;
    }
    c = r = 1;
    while (cnt)
    {
        if (c % 2)
        {
            if (r + 1 <= n)
                r++;
            else
                c++;
        }
        else
        {
            if (r - 1 >= 1)
                r--;
            else
                c++;
        }
        cnt--;
    }
    printf("%d %d", c, r);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

const int N = 109;

int n, m, X, a[N];

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1;i <= n * m;++ i)
        scanf("%d", &a[i]);
    X = a[1];
    sort(a + 1, a + 1 + n * m);
    for (int i = n * m, x = 1, y = 1;i >= 1;-- i)
    {
        if (a[i] == X)
            printf("%d %d\n", x, y);
        if (x & 1)
            ++ y;
        else
            -- y;
        if (y > m)
            y = m, ++ x;
        if (!y)
            y = 1, ++ x;
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}
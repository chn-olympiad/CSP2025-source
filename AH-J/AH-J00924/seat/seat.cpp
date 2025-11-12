#include <bits/stdc++.h>

using namespace std;

const int N = 15;

int n, m;
int a[N * N];
int g[N * N];

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n * m; i ++ )
        scanf("%d", &a[i]);

    int tot = a[1];
    sort(a + 1, a + 1 + n * m, greater<int>());

    int pos;
    for (int i = 1; i <= n * m; i ++ )
        if (a[i] == tot)
        {
            pos = i;
            break;
        }

    int r = pos % n, c = pos / n;
    if (r) c ++ ;
    else r = n;
    if (!(c & 1)) r = n + 1 - r;

    printf("%d %d", c, r);

    return 0;
}

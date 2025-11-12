#include<bits/stdc++.h>
using namespace std;

const int N = 105;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, 1};
int n, m, rk;
int a[N];

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n * m; ++i)
        scanf("%d", a + i);
    rk = 1;
    for (int i = 2; i <= n * m; ++i)
        rk += (a[i] > a[1]);
    for (int cnt = 1, x = 1, y = 1, d = 0; cnt <= n * m; ++cnt)
    {
        if (cnt == rk)
            { printf("%d %d\n", y, x); break; }
        if (y & 1)
        {
            if (x == 1)
                d = 0;
            if (x == n)
                d = 1;
        }
        else
        {
            if (x == n)
                d = 2;
            if (x == 1)
                d = 3;
        }
        x += dx[d], y += dy[d];
    }
    return 0;
}

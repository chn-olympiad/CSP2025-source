#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[205];
int n, m, ai, c, r, d;

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n * m; i++) scanf("%d", &a[i]);
    ai = a[1];

    sort(a + 1, a + n * m + 1, greater<int>());

    for(int i = 1; i <= n * m; i++)
        if(a[i] == ai) d = i;

    for(int i = 1; i <= 11; i++)
        if(i * m >= d)
        {
            c = i;
            break;
        }

    if(c % 2 != 0)
    {
        for(int i = (c - 1) * n + 1; i <= c * n; i++)
            if(a[i] == ai) r = i % n;
    }
    else
    {
        for(int i = (c - 1) * n + 1; i <= c * n; i++)
            if(a[i] == ai) r = n - (i % n) + 1;
    }

    printf("%d %d", c, r);

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int N = 5010;

int n;
int a[N];
int t[N], cnt;
int res;

bool check()
{
    if (cnt < 3) return false;
    int s = 0, maxn = 0;
    for (int i = 1; i <= cnt; i ++ )
    {
        s += t[i];
        maxn = max(maxn, t[i]);
    }

    if (s > 2 * maxn) return true;
    return false;
}

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);

    int res = 0;
    for (int i = 0; i <= (1 << n) - 1; i ++ )
    {
        cnt = 0;
        for (int j = 0; j < n; j ++ )
            if ((i >> j) & 1)
                t[ ++ cnt] = a[j + 1];
        if (check()) res ++ ;
    }

    printf("%d", res);

    return 0;
}

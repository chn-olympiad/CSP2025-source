#include <bits/stdc++.h>

using namespace std;

const int N = 15, M = 110;

int grades[N * N];
int n, m;

int find(int x)
{
    int l = 0, r = n * m - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (grades[mid] > x) l = mid + 1;
        else r = mid;
    }
    return l;
}

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    scanf("%d%d", &n, &m);

    int own;
    for(int i = 0; i < n * m; i ++ )
        scanf("%d", &grades[i]);

    own = grades[0];
    sort(grades, grades + n * m, [](int a, int b) { return a > b; });

    int idx = find(own);

    int c = idx / n + 1;
    int r;
    if (c % 2 == 1)
        r = idx % n + 1;
    else
        r = n - (idx % n);

    printf("%d %d", c, r);

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int n, m;
int k, num;
int a[N];

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d", &n, &m);
    k = n * m;
    for (int i = 1; i <= k; i ++) {
        scanf("%d", &a[i]);
    }
    num = a[1];

    stable_sort(a + 1, a + k + 1);

    int res = k - (lower_bound(a + 1,a + k + 1, num) - a - 1);

    int x = res /(2 * n) * 2 + 1;
    int y = res % (2 * n);
    if (y == 0) y = 2 * n;
    
    if (y <= n) {
        printf("%d %d\n", x, y);
    }
    else {
        printf("%d %d\n", x + 1, 2 * n - y + 1);
    }
    return 0;
}
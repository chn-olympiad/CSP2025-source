#include <cstdio>
#define uint unsigned long long
#define sint long long
const int maxn = 1e6 + 5;
int a[maxn];
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n * m; i++) scanf("%d", &a[i]);
    int ord = 1;
    for(int i = 1; i <= n * m; i++) ord += a[i] > a[1];
    const int c = (ord + n - 1) / n, r = ord % n ? ord % n : n;
    if(c & 1) printf("%d %d\n", c, r);
    else printf("%d %d\n", c, n + 1 - r);
    return 0;
}
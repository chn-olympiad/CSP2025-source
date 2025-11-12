#include <cstdio>
#include <algorithm>

const int N = 1e2 + 10;
int a[N], s[N][N], A, tot, cnt;

bool cmp(int a, int b) {
    return a > b;
}

int main() {

    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            scanf("%d", &a[++ tot]);

    A = a[1];
    std :: sort(a + 1, a + tot + 1, cmp);

    for (int j = 1; j <= m; j ++) {
        if (j & 1) for (int i = 1; i <= n; i ++) s[i][j] = a[++ cnt];
        else for (int i = n; i >= 1; i --) s[i][j] = a[++ cnt];
    }

    int x, y;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            if (s[i][j] == A) {
                x = i, y = j;
                break ;
            }
    
    printf("%d %d\n", y, x);

    return 0;
}
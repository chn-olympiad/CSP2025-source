#include <bits/stdc++.h>

using namespace std;

const int N = 15;

int n, m;
struct Node {
    int val;
    int id;
} a[N * N];
int c[N][N];

bool cmp (const Node &x, const Node &y) {
    return x.val > y.val;
}

int main () {
    //printf("use : %.10f\n", (sizeof(n) + sizeof(m) + sizeof(a) + sizeof(c)) / 1024. / 1024.);
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n * m; i++) {
        scanf("%d", &a[i].val);
        a[i].id = i;
    }
    sort(a + 1, a + n * m + 1, cmp);
    memset(c, 0, sizeof(c));
    int x = 1, y = 1;
    for (int i = 1; i <= n * m; i++) {
        c[x][y] = a[i].id;
        if (y % 2 == 1) {
            if (x + 1 <= n) x++;
            else y++;
        } else {
            if (x - 1 >= 1) x--;
            else y++;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (c[i][j] == 1) {
                printf("%d %d\n", j, i);
                return 0;
            }
        }
    }
    return 0;
}

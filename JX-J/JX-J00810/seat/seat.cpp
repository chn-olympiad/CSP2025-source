//hui xie zheng jie bu hui xie bao li ru he dui pai ?
//by dog_emperor
#include <bits/stdc++.h>
using namespace std;

int n, m, a[110];

inline bool cmp(const int &x, const int &y) {
    return x > y;
}
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n * m; ++i)
        scanf("%d", &a[i]);
    int me = a[1], pos = 0;
    sort(a + 1, a + n * m + 1, cmp);
    for (int i = 1; i <= n * m; ++i)
        if (a[i] == me) {
            pos = i;
            break;
        }
    int ansi = 0, ansj = 0;
    if (pos % n == 0) {
        ansi = pos / n;
        if (ansi % 2 == 0) ansj = 1;
        else ansj = n;
    } else {
        ansi = pos / n + 1;
        if (ansi % 2 == 0) ansj = n - pos % n + 1;
        else ansj = pos % n;
    }
    printf("%d %d\n", ansi, ansj);
    return 0;
}

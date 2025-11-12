#include <cstdio>
int m, n, a, k;
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d%d%d", &m, &n, &a);
    int ans = 1;
    for (int i = 1; i < m*n; i++) {
        scanf("%d", &k);
        if (a < k) ans++;
    }
    int n1 = ans / n, n2 = ans % n;
    if (n1 % 2) {
        if (n2 == 0) printf("%d %d\n", n1, n);
        else printf("%d %d\n", n1+1, n-n2+1);
    } else {
        if (n2 == 0) printf("%d 1\n", n1);
        else printf("%d %d\n", n1+1, n2);
    }
    return 0;
}
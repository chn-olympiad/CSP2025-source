#include <bits/stdc++.h>
using namespace std;

int n, m, cnt = 1, R;

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    scanf("%d%d", &n, &m);
    scanf("%d", &R);
    for (int i = 2; i <= n * m; i++) {
        int x;  scanf("%d", &x);
        if (x > R) cnt++;
    }
    int c, r;
    int mod = cnt % n;
    c = cnt / n + (mod != 0);
    if (c % 2 == 1) {
        r = mod;
        if (!mod)
            r = n;
    }
    else {
        r = n - mod + 1;
        if (!mod)
            r = 1;
    }
    printf("%d %d\n", c, r);
    return 0;
}

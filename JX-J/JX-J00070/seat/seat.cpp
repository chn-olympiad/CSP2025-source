#include<bits/stdc++.h>

using namespace std;

const int N = 105;
int a[N];

bool cmp(int x, int y) {
    return x > y;
}

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    int tot = n * m;
    for (int i = 1; i <= tot; i++) {
        scanf("%d", &a[i]);
    }
    int R = a[1], c, r;
    sort(a+1, a+tot+1, cmp);
    for (int i = 1; i <= tot; i++) {
        if (a[i] == R) {
            c = (i - 1) / n + 1, r = (i - 1) % n + 1;
            if (c % 2 == 0) r = m - r + 1;
            break;
        }
    }
    printf("%d %d\n", c, r);
    return 0;
}

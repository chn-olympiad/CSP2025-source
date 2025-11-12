// freopen QU ZHU SHI!!!
#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}
int s[103];
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m, c, r, rscore, a, a1;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n * m; i++) {
        scanf("%d", &s[i]);
    }
    rscore = s[1];
    sort(s, s + n * m, cmp);
    for (int i = 1; i <= n * m; i++) {
        if (s[i] == rscore) {
            a = i + 1;
            break;
        }
    }
    c = (a - 1) / n + 1;
    a1 = (a - 1) % n;
    if (c % 2) {
        r = a1 + 1;
    }
    else {
        r = n - a1;
    }
    printf("%d %d", c, r);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

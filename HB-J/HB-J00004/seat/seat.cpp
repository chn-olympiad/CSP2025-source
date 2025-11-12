# include <bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N];
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n * m; i++) {
        scanf("%d", &a[i]);
    }
    int score = a[1];
    int id = -1;
    sort(a + 1, a + n * m + 1, greater<int>());
    for (int i = 1; i <= n * m; i++) {
        if (a[i] == score) {
            id = i;
            break;
        }
    }
    if ((id / n) % 2 == 0) {
        if (id % n == 0) {
            printf("%d %d", id / n, id % n);
        } else {
            printf("%d %d", id / n + 1, id % n);
        }
    } else {
        if (id % n == 0) {
            printf("%d %d", id / n, n - id % n);
        } else {
            printf("%d %d", id / n + 1, n - id % n + 1);
        }
    }
    return 0;
}

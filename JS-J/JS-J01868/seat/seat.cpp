#include <bits/stdc++.h>
using namespace std;

int n, m, idx;
struct node {
    int cj, id;
}a[110];

bool cmp(node x, node y) {
    return x.cj > y.cj;
}
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n * m; ++i) cin >> a[i].cj, a[i].id = i;
    sort(a + 1, a + n * m + 1, cmp);

    for (int i = 1; i <= n * m; ++i) {
        if (a[i].id == 1) {
            idx = i;
            break;
        }
    }
    int t = idx / n, s = idx % n;
    if (s == 0) {
        if (t % 2 == 1) cout << t << " " << n;
        else cout << t << " " << 1;
    }
    else {
        if (t % 2 == 1) cout << t + 1 << " " << n - s + 1;
        else cout << t + 1 << " " << s;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) {
    return a > b;
}
int a[114514];
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        cin >> a[i];
    }
    int tot = a[1];
    sort(a + 1, a + n * m + 1, cmp);
    int i;
    for (i = 1; i <= n * m; i++) {
        if (a[i] == tot) {
            break;
        }
    }
    int c = (i - 1) / n + 1;
    int r;
    if (c % 2 == 1) {
        r = i - (c - 1) * n;
    } else {
        r = c * n - i + 1 ;
    }
    cout << c << ' ' << r;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, m, a[110], c, r;
bool cmp(int x, int y) {
    return x > y;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        cin >> a[i];
    }
    int aa = a[1], cnt;
    sort(a + 1, a + n * m + 1, cmp);
    for (int i = 1; i <= n * m; i++) {
        if (a[i] == aa) {
            cnt = i;
        }
    }
    c = (cnt + n - 1) / n;
    if (c & 1) {
        r = cnt - (c - 1) * n;
    }
    else {
        r = n - (cnt - (c - 1) * n) + 1;
    }
    cout << c << " " << r;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x, int y) {
    return x > y;
}
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int t;
    for (int i = 1; i <= n * m; i++) {
        cin >> a[i];
        if (i == 1) t = a[i];
    }
    sort(a + 1, a + n * m + 1, cmp);
    int cnt;
    for (int i = 1; i <= n * m; i++)
        if (a[i] == t) cnt = i;
    int x = (cnt - 1) / n + 1;
    int y;
    if (x % 2 == 1) y = (cnt - 1) % n + 1;
    else y = n + 1 - ((cnt - 1) % n + 1);
    cout << x << " " << y << endl;
    return 0;
}

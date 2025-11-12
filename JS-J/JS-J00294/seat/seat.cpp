#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[105];
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n * m; i++) {
        cin >> a[i];
    }
    int R = a[0];
    sort(a, a + n * m, cmp);
    int c, r, w = 0;
    for (int i = 0; i < n * m; i++) {
        if (a[i] == R) {
            break;
        }
        w++;
    }
    c = w / n + 1;
    r = w % n;
    if (w % (2 * n) >= n) {
        r = n - 1 - r;
    }
    r = r + 1;
    cout << c << " " << r;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

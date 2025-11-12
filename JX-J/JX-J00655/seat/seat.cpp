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
    int rs = n * m;
    for (int i = 1;i <= rs;i ++) {
        cin >> a[i];
    }
    int r = a[1];
    int mc;
    sort(a + 1, a + rs + 1, cmp);
    for (int i = 1;i <= rs;i ++) {
        if (a[i] == r) {
            mc = i;
            break;
        }
    }
    int mm;
    if (mc % n == 0) {
        cout << mc / n << ' ';
        mm = mc / n;
    } else {
        cout << mc / n + 1 << ' ';
        mm = mc / n + 1;
    }
    if (mm % 2 == 0) {
        if (mc % n == 0) {
            cout << 1;
        } else {
            cout << n - (mc % n) + 1;
        }
    } else {
        if (mc % n == 0) {
            cout << n;
        } else {
            cout << mc % n;
        }
    }
    return 0;
}

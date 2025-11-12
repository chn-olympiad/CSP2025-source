#include<bits/stdc++.h>
using namespace std;
int a[105];
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m, s;
    cin >> n >> m;
    for (int i = 1; i <= m * n; i++) {
        cin >> a[i];
        if (i == 1) {
            s = a[i];
        }
    }
    int num;
    sort(a + 1, a + n * m + 1, greater<int>());
    for (int i = 1; i <= m * n; i++) {
        if (a[i] == s) num = i;
    }
    int x, y;
    x = (num - 1) / n + 1;
    if (x % 2 == 1) {
        y = num % (2 * n);
    } else {
        int b = (num-1) / n;
        int c = num - b * n;
        y = n - c + 1;
    }
    cout << x << ' ' << y;
}

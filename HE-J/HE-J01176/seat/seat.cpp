#include<bits/stdc++.h>
using namespace std;

int a[110];

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    int n, m, r, x;
    cin >> n >> m;
    x = n * m;
    for (int i = 1;i <= x;i++) {
        cin >> a[i];
    }
    r = a[1];
    sort(a + 1, a + x + 1);

    int pos = x;
    for (int i = 1;i <= m;i++) {
        if (i % 2) {
            for (int j = 1;j <= n;j++) {
                if (a[pos--] == r) {
                    cout << i << ' ' << j;
                    return 0;
                }
            }
        }
        else {
            for (int j = n;j >= 1;j--) {
                if (a[pos--] == r) {
                    cout << i << ' ' << j;
                    return 0;
                }
            }
        }
    }
}

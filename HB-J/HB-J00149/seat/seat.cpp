#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int n, m, a[1005], r, s, c;

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    s = n * m;
    for (int i = 0; i < s; i++) {
        cin >> a[i];
    }
    c = a[0];
    sort(a, a + s, cmp);
    for (int i = 1; i <= m; i++) {
        if (i % 2 == 1) {
            for (int j = 1; j <= n; j++) {
                if (a[r] == c) {
                    cout << i << " " << j;
                    return 0;
                }
                r++;
            }
        }
        else {
            for (int j = n; j >= 1; j--) {
                if (a[r] == c) {
                    cout << i << " " << j;
                    return 0;
                }
                r++;
            }
        }
    }
    return 0;
}

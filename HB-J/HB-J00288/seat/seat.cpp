#include <bits/stdc++.h>
using namespace std;

int n, m;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    int x = n * m;
    vector<int> a(x, 0);
    for (int i = 0; i < x; i++) {
        cin >> a[i];
    }
    int w = a[0];
    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < x; i++) {
        if (a[i] == w) {
            // r hang, c lie;
            int r, c;
            if (i + 1 <= n) {
                c = 1;
            }
            else {
                c = (i + 1) / n + 1;
            }
            if (c % 2 == 0) {
                r = n - (i % n);
            }
            else {
                r = (i % n) + 1;
            }
            cout << c << ' ' << r << '\n';
            return 0;
        }
    }
    return 0;
}

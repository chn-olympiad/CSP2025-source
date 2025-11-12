#include <bits/stdc++.h>
using namespace std;
int n, m, sc[105];
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        cin >> sc[i];
    }
    int x = sc[1], p = 0;
    sort(sc + 1, sc + 1 + n * m);
    for (int i = 1; i <= n * m; i++) {
        if (sc[i] == x) {
            p = n * m - i + 1;
            break;
        }
    }
    int C = p / n;
    if (p % n == 0) {
        if (C % 2) cout << C << " " << n;
        else cout << C << " " << 1;
    } else {
        C += 1;
        int R = p % n;
        if (C % 2 == 0) R = n + 1 - R;
        cout << C << " " << R;
    }
    return 0;
}

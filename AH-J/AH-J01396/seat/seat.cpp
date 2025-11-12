#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[1000009], b[1000009];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1;i <= n * m;i++)
        cin >> a[i], b[i] = a[i];
    sort(b + 1, b + 1 + (n * m));
    int pos = n * m;
    for (int i = 1;i <= m;i++) {
        if (i % 2) {
            for (int j = 1;j <= n;j++) {
                if (b[pos] == a[1]) cout << i << " " << j, exit(0);
                pos--;
            }
        } else {
            for (int j = n;j >= 1;j--) {
                if (b[pos] == a[1]) cout << i << " " << j, exit(0);
                pos--;
            }
        }
    }
    return 0;
}

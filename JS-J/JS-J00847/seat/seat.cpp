#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1005;
int n, m, sc, pos, a[maxn];
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n * m; i++) {
        cin >> a[i];
        if (i == 0) pos = 0;
        else {
            if (a[i] > a[0]) pos++;
        }
    }
    cout << pos << "\n";
    int row = pos % n, col = pos / n;
    if (col & 1) row = n - row - 1;
    cout << col + 1 << " " << row + 1;
    return 0;
}

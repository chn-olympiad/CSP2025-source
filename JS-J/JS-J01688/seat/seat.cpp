#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 1e2 + 10;
int n, m, R, a[N];
signed main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        cin >> a[i];
    }
    R = a[1];
    sort(a + 1, a + 1 + n * m, greater <int> ());
    int l = 1, h = 0;
    for (int i = 1; i <= n * m; i++) {
        if (l & 1) {
            if (h < n) h++;
            else l++;
        } else {
            if (h > 1) h--;
            else l++;
        }
        if (a[i] == R) {
            cout << l << " " << h << endl;
            return 0;
        }
    }
    return 0;
}
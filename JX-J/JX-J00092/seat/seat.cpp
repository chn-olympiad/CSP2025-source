#include <bits/stdc++.h>
using namespace std;

int main () {

    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n * m + 5);
    for (int i = 1; i <= n * m; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin() + 1, a.begin() + n * m + 1, greater<>());
    for (int i = 1, x = 1, y = 1; i <= n * m; i++) {
        if (a[i].second == 1) {
            cout << y << ' ' << x;
            return 0;
        }
        x += (y & 1 ? 1 : -1);
        if (x > n) {
            x = n;
            y++;
        } else if (x < 1) {
            x = 1;
            y++;
        }
    }
    return 0;
}

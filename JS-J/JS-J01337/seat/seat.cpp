#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
int s[N];
int main () {
    freopen ("r", "seat.in", stdin);
    freopen ("w", "seat.out", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        cin >> s[i];
        s[i] = -s[i];
    }
    int xx = s[1];
    int id;
    sort (s + 1, s + 1 + n * m);
    for (int i = 1; i <= n * m; i++) {
        if (s[i] == xx) {
            id = i;
            break;
        }
    }
    int x = (id + m - 1) / m;
    int y;
    int dir = x % 2;
    if (dir == 1) {
        y = id - (x - 1) * m;
    }
    else {
        y = 1 + m - (id - (x - 1) * m);
    }
    cout << x << ' ' << y << endl;
    return 0;
}

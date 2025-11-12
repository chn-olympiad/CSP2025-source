#include <bits/stdc++.h>
using namespace std;
const int NM = 10 * 10 + 10;

int n, m;
int a[NM];

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n * m; i++) cin >> a[i];

    int s = a[1];

    int tag = 1, x = 1, y = 1;
    sort(a + 1, a + n * m + 1, greater<int>());

    for(int i = 1; i <= n * m; i++) {
        if(a[i] == s) {
            cout << y << ' ' << x << '\n';
            return 0;
        }

        if((tag == 1 && x == n) || (tag == -1 && x == 1)) {
            tag = -tag, y++;
        } else {
            x += tag;
        }
    }
}
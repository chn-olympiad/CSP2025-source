#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1005;

int n, m;
int a[MAX_N];
bool flag = 0;
int c = 1, r = 0;

int main () {
    freopen ("seat.in", "r", stdin);
    freopen ("seat.out", "w", stdout);
    cin >> n >> m;
    cin >> a[1];
    int cnt = a[1];
    for (int i = 2; i <= n * m; i++) {
        cin >> a[i];
    }
    sort (a + 1, a + n * m + 1);
    for (int i = n * m; i >= 1; i--) {
        if (flag == 0) {
            r++;
            if (r == n + 1) {
                r--;
                c++;
                flag = 1;
            }
        } else {
            r--;
            if (r == 0) {
                r++;
                c++;
                flag = 0;
            }
        }
        if (a[i] == cnt) {
            cout << c << " " << r << endl;
            return 0;
        }
    }
    return 0;
}

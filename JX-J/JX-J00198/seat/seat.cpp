#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N];
int n, m;
int x, y, num;
bool cmp (int A, int B) {
    return A > B;
}
int main () {
    freopen ("seat.in", "r", stdin);
    freopen ("seat.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie (0), cout.tie (0);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        cin >> a[i];
    }
    num = a[1];
    sort (a + 1, a + 1 + (n * m), cmp);
    int A = 1, B = 1, l = 1;
    if (a[l] == num) {
        cout << A << ' ' << B << "\n";
        return 0;
    }
    ++ A, ++ l;
    while (true) {
        if (a[l] == num) {
            cout << B << ' ' << A << "\n";
            return 0;
        }
        ++ l;
        if (A == n || A == 1) {
            ++ B;
            if (a[l] == num) {
                cout << B << ' ' << A << "\n";
                return 0;
            }
            ++ l;
            if (B % 2) ++ A;
            else -- A;
        } else {
            if (B % 2) ++ A;
            else -- A;
        }
    }
    return 0;
}

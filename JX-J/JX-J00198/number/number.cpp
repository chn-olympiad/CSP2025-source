#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int a[N], l;
int main () {
    freopen ("number.in", "r", stdin);
    freopen ("number.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie (0), cout.tie (0);
    string s; cin >> s;
    int n = s.size ();
    s = " " + s;
    for (int i = 1; i <= n; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            ++ l;
            a[l] = s[i] - '0';
        }
    }
    sort (a + 1, a + 1 + l);
    if (a[l] == 0) {
        cout << "0\n";
        return 0;
    }
    for (int i = l; i >= 1; i--) {
        cout << a[i];
    }
    return 0;
}



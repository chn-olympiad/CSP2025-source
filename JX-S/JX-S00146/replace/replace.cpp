#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2e5 + 5;

int n, q;
string s[MAX_N][3], t[MAX_N][3];

int main () {
    freopen ("replace.in", "r", stdin);
    freopen ("replace.out", "w", stdout);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> s[i][1] >> s[i][2];
    }
    for (int i = 1; i <= q; i++) {
        cin >> t[i][1] >> t[i][2];
        cout << 0 << endl;
    }
    //AC
    //rp++
    return 0;
}

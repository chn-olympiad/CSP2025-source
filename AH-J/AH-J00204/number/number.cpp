#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int t;
int main () {
    freopen ("number.in", "r", stdin);
    freopen ("number.out", "w", stdout);
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            int x;
            x = s[i] - '0';
            a[t] = x;
            t++;
        }
    }
    sort (a, a + t);
    while (t--) cout << a[t];
    return 0;
}

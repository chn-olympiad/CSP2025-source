#include <bits/stdc++.h>
#define int long long
using namespace std;

string s;
char n[1000050];
int cnt = 0;

signed main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            n[++cnt] = s[i];
        }
    }
    sort (n + 1, n + cnt + 1);
    for (int i = cnt; i >= 1; i--) {
        cout << n[i];
    }
    return 0;
}

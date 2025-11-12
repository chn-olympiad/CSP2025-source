#include <bits/stdc++.h>
#define int long long
using namespace std;
string s;
int a[1000020], cnt;
void init() {
    for (int i = 0; i < s.size(); i++) {
        s[i] = s[i] - 48;
        if (s[i] >= 0 && s[i] <= 9) {
            a[cnt] = s[i];
            cnt++;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    init();
    sort(a, a + cnt);
    for (int i = cnt - 1; i >= 0; i--) {
        cout << a[i];
    }
    return 0;
}

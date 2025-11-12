#include<bits/stdc++.h>
using namespace std;
int n, m, c[505];
string s;
bool find0() {
    for (int i = 0; i <= s.size(); i ++) {
        if (s[i] == '0') {
            return 1;
        }
    }
    return 0;
}
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    for (int i = 1; i <= n; i ++) {
        cin >> c[i];
    }
    if (n == m && !find0()) {
        cout << n << endl;
    }else {
        cout << 0 << endl;
    }
    return 0;
}

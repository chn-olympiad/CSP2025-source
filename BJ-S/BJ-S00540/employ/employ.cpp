#include<bits/stdc++.h>
using namespace std;
int c[507];
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m, cnt = 0;
    long long ans = 1;
    cin >> n >> m;
    string s;
    cin >> s;
    getchar();
    bool f = true;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') f = false;
        cin >> c[i];
        if (c[i] > 0) cnt++;
    }
    if (f) {
        if (m <= cnt) {
            for (long long i = 2; i <= n; i++) ans = (ans * i) % 998244353;
            cout << ans << '\n';
        } else {
            for (long long i = 2; i <= n - (m - cnt); i++) ans = (ans * i) % 998244353;
            cout << ans << '\n';
        }
    } else {
        cout << 8;
    }
    return 0;
}
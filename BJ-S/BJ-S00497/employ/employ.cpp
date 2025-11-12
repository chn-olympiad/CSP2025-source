#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m, c[505], cnt0, cnt1;
string s;
bool flag;
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    cin >> s;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        if (c[i] == 0) cnt0++;
    }
    for (int i = 1; i <= n; i++) if (s[i] == '1') cnt1++;
    if (cnt1 < m) {cout << 0; return 0;}
    if (cnt1 == n) {
        if (n - cnt0 < m) {cout << 0; return 0;}
        int ans = 1;
        for (int i = n; i >= 1; i--) {
            ans = ans * i % mod;
        }
        cout << ans;
        return 0;
    }
    return 0;
}
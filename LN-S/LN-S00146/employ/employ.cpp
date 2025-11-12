#include <bits/stdc++.h>

using namespace std;

int a[505];

int main() {
    freopen("employ1.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    string s;
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a+1, a+1+n);
    int num = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1' && a[i+1] >= i) {
            num++;
        }
    }
    int ans = 1;
    for (int i = 1; i <= m; i++) {
        ans *= i;
        ans %= 998244353;
    }
    cout << ans;
    return 0;
}

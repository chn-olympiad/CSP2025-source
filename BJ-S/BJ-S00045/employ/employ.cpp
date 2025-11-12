#include<bits/stdc++.h>
using namespace std;
const int maxn = 500 + 10;
string s;
int a[maxn];
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    cin >> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (m == n) {
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                cout << 0 << '\n';
                return 0;
            }
        }
        long long ans = 1;
        for (int i = n; i >= 1; i--) {
            ans *= i;
            ans %= 998244353;
        }
        cout << ans << '\n';
    }
    else {
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (a[i] != 1) {
                flag = false;
            }
        }
        if (flag) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == 1) {
                    cnt++;
                }
                else {
                    if (cnt < m) {
                        cout << 0 << '\n';
                        return 0;
                    }
                    else {
                       long long ans = 1;
                        for (int j = n; j >= 1; j--) {
                            ans *= j;
                            ans %= 998244353;
                        }
                        cout << ans << '\n';
                    }
                }
            }
        }
    }
    return 0;
}

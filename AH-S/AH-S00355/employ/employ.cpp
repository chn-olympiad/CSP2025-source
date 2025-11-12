#include <bits/stdc++.h>
using namespace std;
const long long M = 998244353;
int n, m;
string s;
int c[505];
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    for (int i = 1; i <= n; i ++) cin >> c[i];
    bool flag = true;
    for (int i = 0; i < n; i ++)
        if (s[i] == 0) {
            flag = false;
            break;
        }
    if (flag == false) {
        cout << "0" << endl;
        return 0;
    }
    long long ans = 1;
    for (int i = 1; i <= n; i ++) {
        ans *= i;
        ans %= M;
    }
    cout << ans << endl;
    return 0;
}

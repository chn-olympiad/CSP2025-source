#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
typedef long long ll;
int main() {
    freopen ("employ.in", "r", stdin);
    freopen ("employ.out", "w", stdout);
    int n, m;string s;
    cin >> n >> m >> s;
    int pa[n];
    for (int i = 0; i < n; i++) {
        cin >> pa[i];
    }
    int j_0 = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == j_0) {
            j_0++;
            if (j_0 == 2) {
                if (i + 1 >= m) {
                    int ans = 1;
                    for (int i = 2; i <= i + 1; i++) {
                        ans = ans % mod * i;
                    }
                    cout << ans;
                    return 0;
                } else {
                    cout << 0;
                    return 0;
                }
            }
        }
    }
    return 0;
}

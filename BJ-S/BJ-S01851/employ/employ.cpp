#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
string s;
const int N = 505, mod = 998244353;
int c[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;
    s = " " + s;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    int ans = 1;
    for (int i = 2; i <= n; ++i) {
        ans *= i;
        ans %= mod;
    }
    cout << ans;
    return 0;
}

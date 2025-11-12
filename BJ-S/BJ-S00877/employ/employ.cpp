#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
char s[505];
ll a[505], b[505], t, ans, cnt;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m; cin >> n >> m;
    cin >> (s + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 0) cnt++;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') {
            t++;
            b[t] = i;
        }
    }
    if (n - t < m) {
        cout << 0;
        return 0;
    }
    if (t == 0) {
        while (n--) {
            ans = (ans * n) % mod;
        }
        return 0;
    }
    return 0;
}

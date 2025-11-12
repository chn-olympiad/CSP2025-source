#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define int long long
const int mod = 998244353;

int n, m, a[100005], pos[100005], ans;
char ch[100005];

signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> ch[i];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (m == n) {
        for (int i = 1; i <= n; i++)
            if (!a[i]) {
                cout << 0 << endl;
                return 0;
            }
        ans = 1;
        for (int i = 1; i <= n; i++)
            ans = (ans * i) % mod;
        cout << ans << endl;
        return 0;
    }
    if (n <= 10) {
        for (int i = 1; i <= n; i++)
            pos[i] = i;
        int k = 1;
        for (int i = 1; i <= n; i++)
            k *= i;
        for (int i = 1; i <= k; i++) {
            int cnt = 0, sum = 0;
            for (int j = 1; j <= n; j++) {
                if (cnt >= a[pos[j]]) {
                    cnt++;
                    continue;
                }
                if (ch[j] == '1')
                    sum++;
                else
                    cnt++;
            }
            if (sum >= m)
                ans++;
            ans %= mod;
            next_permutation(pos + 1, pos + n + 1);
        }
        cout << ans << endl;
    }
    return 0;
}

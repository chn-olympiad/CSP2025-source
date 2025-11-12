#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n, m, ans, c[505];
string s;

void check() {
    bool flag = 1;
    for (char c : s) flag &= (c == '1');
    if (flag) {
        int ans = 1;
        for (int i = n;i >= 1;i--) {
            ans = (ans * i) % mod;
        }
        cout << ans;
        exit(0);
    }
}

signed main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >>s;
    for (int i = 1;i <= n;i++) {
        cin >> c[i];
    }
    check();
    sort(c +1, c +n +1);
    do {
        int cnt = 0, res = n;
        for (int i = 1;i <= n;i++) {
            if (cnt >= c[i]) {
                cnt++;
                res--;
            }
            else if (s[i - 1] == '0') cnt++;
        }
        ans = (ans + (cnt == m)) % mod;
    }while (next_permutation(c + 1, c + n + 1));
    cout << ans;
    /*do {
        int cnt = 0, res = n;
        for (int i = 1;i <= n;i++) {
            if (cnt >= c[i]) {
                cnt++;
                res--;
            }
            else if (s[i - 1] == '0') {
                cnt++;
                res--;
            }
        }
        ans = (ans + (res >= m)) % mod;
    }while (next_permutation(c + 1, c + n + 1));
    cout << ans;*/
    return 0;
}

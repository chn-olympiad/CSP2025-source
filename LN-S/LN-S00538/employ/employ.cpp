#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;
const int N = 505, MOD = 998244353;
int a[N], sum, ans[N], q = 1, cnt = 0;
int main () {
    freopen ("employ.in", "r", stdin);
    freopen ("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    cin >> s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 1; j <= a[i]; j++) {
            ans[j]++;
        }
    }
    for (int i = 0; i < s.size (); i++) {
        if (s[i] == '1') {
            q *= (ans[i + 1] - cnt) % MOD;
            if (q < 0) q = 0;
            cnt++;
        }
    }
    if (q < 0) {
        q = 0;
    }
    cout << q ;
    return 0;
}
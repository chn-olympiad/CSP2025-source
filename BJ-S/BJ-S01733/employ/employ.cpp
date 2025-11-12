#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1000005];
int p[1000005];
string s;
int n, m, cnt;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    for (int i = 1; i <= n; i ++) cin >> a[i], p[i] = i;
    do {
        int cntt = 0, flag = 1, cnttt = 0;
        for (int i = 1; i <= n; i ++) {
            if (cnttt >= a[p[i]]) {cnttt ++;
             continue;}
            cntt += s[i - 1] - '0';
            cnttt += 1 - (bool)(s[i - 1] - '0');
            // cout << p[i] << " " << cnttt << " " << a[p[i]] << " " << s[i - 1] << "\n";
        }
        if (cntt >= m) {
            // cout << cntt << "\n";
            cnt ++;
            // for (int i = 1; i <= n; i ++) cout << p[i] << " "; cout << "\n";
        }
    } while (next_permutation(p + 1, p + n + 1));
    cout << cnt << "\n";
    return 0;
}
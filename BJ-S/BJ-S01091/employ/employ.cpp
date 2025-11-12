#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
const int mod = 998244353;

int n, m, c[510], id[20];
string s;
bool check() {
    int refuseCnt = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        int p = id[i];
        if (refuseCnt >= c[p]) {
            refuseCnt++;
            continue;
        }
        if (s[i] == '1') {
            cnt++;
        } else {
            refuseCnt++;
        }
    }
    return cnt >= m;
}
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;
    s = ' ' + s;
    bool specialA = 1, specialB = (n >= 100);
    for (int i = 1, cnt = 0; i <= n; i++) {
        cin >> c[i];
        if (s[i] == '0') {
            specialA = 0;
        } else {
            cnt++;
        }
        if (cnt > 18) {
            specialB = 0;
        }
    }
    int cnt1 = 0;
    for (int i = 1; i <= n; i++) {
        cnt1 += (s[i] == '1');
    }
    int real = 0;
    for (int i = 1; i <= n; i++) {
        real += (c[i] != 0);
    }
    if (real < m) {
        cout << 0 << '\n';
        return 0;
    }
    if (n <= 10) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            id[i] = i;
        }
        do {
            ans += check();
        } while (next_permutation(id + 1, id + n + 1));
        cout << ans % mod << '\n';
    } else if (specialA == 1) {
        ll ans = 1;
        for (int i = 1; i <= real; i++) {
            ans = ans * i % mod;
        }
        cout << ans << '\n';
    } else if (m == n) {
        cout << 0 << '\n';
    } else if (m == 1) {
        int first1 = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '1') {
                first1 = i;
                break;
            }
        }
        int minc = n;
        for (int i = 1; i <= n; i++) {
            if (c[i] == 0) {
                continue;
            }
            minc = min(minc, c[i]);
        }
        if (minc >= first1) {
            ll ans = real;
            for (int i = 1; i < n; i++) {
                ans = ans * i % mod;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
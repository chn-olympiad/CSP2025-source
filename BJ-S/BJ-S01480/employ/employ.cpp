#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int n, m, c[505], a[505];
string s;
bool ok() {
    int fail = 0, v = 0;
    for(int i = 1; i <= n; i++) {
        if(fail >= c[a[i]]) {
            continue;
        }
        if(s[i - 1] == '1') {
            v++;
        } else {
            fail++;
        }
    }
    return v >= m;
}
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
        a[i] = i;
    }
    sort(c, c + n);
    int cnt = 0;
    do {
        if(ok()) {
            cnt = (cnt + 1) % mod;
        }
    } while(next_permutation(a + 1, a + n + 1));
    cout << cnt << endl;
    return 0;
}
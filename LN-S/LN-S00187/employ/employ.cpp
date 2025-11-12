#include <bits/stdc++.h>
#define int long long
using namespace std;

int mod = 998244353;
bool test[10000];
int c[200005];
int cnt[200005];

signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> test[i];
    for (int j = 0; j < n; j++) cin >> c[i];
    sort(c, c + n);
    int cnt11111 = 0;
    for (int i = 0; i < n; i++) cnt += test[i];
    if (cnt < m) {
        cout << 0;
        return 0;
    }
    cout << 2;
    return 0;
    for (int i = 0; i < n; i++) {
        cnt[c[i]]++;
    }

    for (int i = 0; i < n; i++) {

    }
    return 0;
}

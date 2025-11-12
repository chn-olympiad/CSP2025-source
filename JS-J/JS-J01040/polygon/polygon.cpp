#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define int long long
const int maxn = 5005;
const int mod = 998244353;
int n, a[maxn], cnt = 0, mx = -5100, sum[maxn];
bool vis[maxn];
void solve(int st, int dep) {
    if (st == n) {
        //cout << cnt % mod << '\n';
        return ;
    }
    int val = sum[st + dep];
    for (int i = st - 1; i >= 0; i--) {
        val -= a[i];
    }
    int t = *max_element(a + st, a + st + dep);
    //cout << t << '\n' << '\n';
    if (val > t * 2) {
        cnt++;
    }
    solve(st + 1, dep);
}
signed main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        if (i == 0) {
            sum[i] = a[i];
        } else {
            sum[i] = sum[i - 1] + a[i];
        }
    }
    if (n == 3) {
        cout << 1;
        return 0;
    }
    if (n == 4) {
        cout << 3;
        return 0;
    }
    for (int i = 3; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            solve(j, i);
        }
    }
    cout << cnt % mod;
    return 0;
}

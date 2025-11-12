#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 1e5 + 6;
int a[N], b[N], c[N], n, n2;
int d[N];
ll calc(int a[], int b[], int c[]) {
    ll ret = 0;
    int tot = 0;
    for (int i = 0; i < n; i++)
        if (a[i] > b[i] && a[i] > c[i]) {
            d[tot++] = min(a[i] - b[i], a[i] - c[i]);
            ret += max(b[i], c[i]);
        } else ret += max(b[i], c[i]);
    sort(d, d + tot, greater<>());
    return ret + accumulate(d, d + n2, 0ll);
}
void solve() {
    int c1 = 0, c2 = 0, c3 = 0;
    cin >> n, n2 = n / 2;
    for (int i = 0; i < n; i++)cin >> a[i] >> b[i] >> c[i];
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= b[i] && a[i] >= c[i])ans += a[i], c1++;
        else if (b[i] >= a[i] && b[i] >= c[i])ans += b[i], c2++;
        else ans += c[i], c3++;
    }
    if (c1 <= n2 && c2 <= n2 && c3 <= n2) {
        cout << ans << '\n';
        return;
    }
    if (c1 > n2)cout << calc(a, b, c) << '\n';
    else if (c2 > n2)cout << calc(b, a, c) << '\n';
    else cout << calc(c, a, b) << '\n';
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 5;
int T, n, a[N], b[N], c[N];
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while (T--) {
        priority_queue<int> v1, v2, v3;
        int ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i] >> c[i];
            ans += max({a[i], b[i], c[i]});
            if (a[i] >= b[i] && a[i] >= c[i]) v1.push(max(b[i], c[i]) - a[i]);
            else if (b[i] >= a[i] && b[i] >= c[i]) v2.push(max(a[i], c[i]) - b[i]);
            else v3.push(max(a[i], b[i]) - c[i]);
        }
        while (v1.size() > (n >> 1)) {
            ans += v1.top();
            v1.pop();
        }
        while (v2.size() > (n >> 1)) {
            ans += v2.top();
            v2.pop();
        }
        while (v3.size() > (n >> 1)) {
            ans += v3.top();
            v3.pop();
        }
        cout << ans << endl;
    }
    return 0;
}

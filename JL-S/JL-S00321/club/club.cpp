#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N], b[N], c[N], d[N];

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        priority_queue<int> q1, q2, q3;
        int ans = 0;
        for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
        for (int i = 1; i <= n; i++) {
            if (a[i] >= b[i] && a[i] >= c[i]) q1.push(max(b[i], c[i])-a[i]);
            else if (b[i] >= a[i] && b[i] >= c[i]) q2.push(max(a[i], c[i])-b[i]);
            else q3.push(max({a[i], b[i]})-c[i]);
            ans += max({a[i], b[i], c[i]});
        }
        while (q1.size() > n/2) ans += q1.top(), q1.pop();
        while (q2.size() > n/2) ans += q2.top(), q2.pop();
        while (q3.size() > n/2) ans += q3.top(), q3.pop();
        cout << ans << '\n';
    }
    return 0;
}
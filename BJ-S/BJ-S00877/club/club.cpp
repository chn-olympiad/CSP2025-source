#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
priority_queue<int, vector<int>, greater<int> > q1, q2, q3;
int a, b, c;
ll ans;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        a = b = c = ans = 0;
        while (!q1.empty()) q1.pop(); while (!q2.empty()) q2.pop(); while (!q3.empty()) q3.pop();

        for (int i = 1; i <= n; i++) {
            int x, y, z; cin >> x >> y >> z;
            if (x >= y && x >= z) {
                if (a < n / 2) {
                    ans += x;
                    q1.push(x - max(y, z));
                    a++;
                } else {
                    if (x - max(y, z) <= q1.top()) ans += max(y, z);
                    else {
                        ans += x;
                        ans -= q1.top();
                        q1.pop();
                        q1.push(x - max(y, z));
                    }
                }
            } else if (y >= x && y >= z) {
                if (b < n / 2) {
                    ans += y;
                    q2.push(y - max(x, z));
                    b++;
                } else {
                    if (y - max(x, z) <= q2.top()) ans += max(x, z);
                    else {
                        ans += y;
                        ans -= q2.top();
                        q2.pop();
                        q2.push(y - max(x, z));
                    }
                }
            } else {
                if (c < n / 2) {
                    q3.push(z - max(x, y));
                    c++;
                    ans += z;
                } else {
                    if (z - max(x, y) <= q3.top()) ans += max(y, x);
                    else {
                        ans += z;
                        ans -= q3.top();
                        q3.pop();
                        q3.push(z - max(x, y));
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

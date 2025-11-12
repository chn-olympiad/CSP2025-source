#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n, ans;
struct node {
    int a, b, c, d;
}q[100009];
int cmp_10(node cs1, node cs2) {
    return cs1.a > cs2.a;
}
int cmp_25(node cs1, node cs2) {
    return cs1.d > cs2.d;
}
signed main () {
    freopen ("club.in", "r", stdin);
    freopen ("club.out", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        bool flag_a = true, flag_b = true;
        for (int i = 1; i <= n; i++) {
            cin >> q[i].a >> q[i].b >> q[i].c;
            q[i].d = abs(q[i].a - q[i].b);
            if (q[i].b != 0) {
                flag_a = 0;
            }
            if (q[i].c != 0) {
                flag_a = 0;
                flag_b = 0;
                break;
            }
        }
        if (n == 2) {
            int x01 = max(q[1].a, max(q[1].b, q[1].c)), x02 = max(q[2].a, max(q[2].b, q[2].c));
            int y01 = max(q[1].a, min(q[1].b, q[1].c)), y02 = max(q[2].a, max(q[2].b, q[2].c));
            int z01 = min(q[1].a, min(q[1].b, q[1].c)), z02 = min(q[1].a, min(q[1].b, q[1].c));
            if ((x01 == q[1].a && x02 == q[2].a) || (x01 == q[1].b && x02 == q[2].b) || (x01 == q[1].c && x02 == q[2].c)) {
                cout << max (x01 + y02, x02 + y01) << endl;
            }
        } else {
           if (flag_a) {
                sort (q + 1, q + 1 + n, cmp_10);
                ans = 0;
                for (int i = 1; i <= n / 2; i++) {
                    ans += q[i].a;
                }
           } else {
                ans = 0;
                int A = 0, B = 0;
                for (int i = 1; i <= n; i++) {
                    if (A == n / 2) {
                        ans += q[i].b;
                    } else if (B == n / 2) {
                        ans += q[i].a;
                    } else if (q[i].b > q[i].a) {
                        B++;
                        ans += q[i].b;
                    } else {
                        A++;
                        ans += q[i].a;
                    }
                }
           }
           cout << ans << endl;
        }
    }
    return 0;
}

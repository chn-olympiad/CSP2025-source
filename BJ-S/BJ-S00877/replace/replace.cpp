#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node {
    int l;
    string s1, s2;
} a[200005];
bool cmp(node x, node y) {
    return x.l < y.l;
}
char l1[5000005], l2[5000005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].s1 >> a[i].s2;
        a[i].l = a[i].s1.size();
    }
    sort(a + 1, a + n + 1, cmp);
    while (q--) {
        cin >> l1 >> l2;

        int m = strlen(l2), s = 1e9, t = -1e9;
        if (m != strlen(l1)) {
            cout << 0 << "\n";
            continue;
        }
        for (int i = 0; i < m; i++) {
            if (l2[i] != l1[i]) {
                if (s == 1e9) s = i;
                t = i;
            }
        }
        ll ans = 0;
        bool flag;
        for (int i = n; i >= 1; i--) {
            if (a[i].l < t - s + 1) break;
            for (int j = 0; j < m - a[i].l + 1; j++) {
                if (j + a[i].l - 1 < t) continue;
                if (j > s) break;
                flag = 1;
                for (int k = j; k <= j + a[i].l - 1; k++) {
                    if (a[i].s1[k - j] != l1[k] || a[i].s2[k - j] != l2[k]) {
                        flag = 0;
                        break;
                    }
                }
                ans += flag;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int t, a[100005][4], n, ans;
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    for (int i = 1; i <= t; i ++) {
        cin >> n;
        for (int j = 1; j <= n; j ++) {
            for (int u = 1; u <= 3; u ++) {
                cin >> a[j][u];
            }
        }
        if (n == 2) {
            int b[4], c[4];
            for (int j = 1; j <= 3; j ++) {
                b[i] = a[1][i];
                c[i] = a[2][i];
            }
            int bb = max(b[1], max(b[2], b[3])), cc = max(c[1], max(c[2], c[3]));
            int be, ce;
            for (int j = 1; j <= 3; j ++) {
                if (b[j] == bb) {
                    be = j;
                }else if (c[j] == cc) {
                    ce = j;
                }
            }
            sort(b + 1, b + 4, cmp);
            sort(c + 1, c + 4, cmp);
            if (be == ce) {
                if (bb > cc) {
                    ans += bb;
                    ans += max(c[2], c[3]);
                }else if (bb < cc) {
                    ans += cc;
                    ans += max(b[2], b[3]);
                }else if (bb == cc) {
                    if (b[2] > c[2]) {
                        ans += cc += b[2];
                    }else if (b[2] <= c[2]) {
                        ans += bb += c[2];
                    }
                }
            }

        }
        cout << ans << endl;
    }
    return 0;
}

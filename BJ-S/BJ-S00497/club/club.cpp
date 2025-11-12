#include <bits/stdc++.h>
using namespace std;
int T, n, a[100005][4], b[100005], c[4], d[100005], cnt;
long long ans;
bool cmp(int a, int b) {return a > b;}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--) {
        ans = 0;
        memset(c, 0, sizeof(c));
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            if (max(a[i][1], max(a[i][2], a[i][3])) == a[i][1]) c[1]++, b[i] = 1;
            else if (max(a[i][1], max(a[i][2], a[i][3])) == a[i][2]) c[2]++, b[i] = 2;
            else c[3]++, b[i] = 3;
            ans += max(a[i][1], max(a[i][2], a[i][3]));
        }
        if (c[1] * 2 <= n && c[2] * 2 <= n && c[3] * 2 <= n) {cout << ans << '\n'; continue;}
        cnt = 0;
        if (c[1] * 2 > n) {
            for (int i = 1; i <= n; i++) {
                if (b[i] == 1) {
                    sort(a[i] + 1, a[i] + 4, cmp);
                    d[++cnt] = a[i][1] - a[i][2];
                }
            }
            sort(d + 1, d + cnt + 1);
            for (int i = 1; i <= c[1] - n / 2; i++) ans -= d[i];
        }
        else if (c[2] * 2 > n) {
            for (int i = 1; i <= n; i++) {
                if (b[i] == 2) {
                    sort(a[i] + 1, a[i] + 4, cmp);
                    d[++cnt] = a[i][1] - a[i][2];
                }
            }
            sort(d + 1, d + cnt + 1);
            for (int i = 1; i <= c[2] - n / 2; i++) ans -= d[i];
        }
        else {
            for (int i = 1; i <= n; i++) {
                if (b[i] == 3) {
                    sort(a[i] + 1, a[i] + 4, cmp);
                    d[++cnt] = a[i][1] - a[i][2];
                }
            }
            sort(d + 1, d + cnt + 1);
            for (int i = 1; i <= c[3] - n / 2; i++) ans -= d[i];
        }
        cout << ans << '\n';
    }
    return 0;
}

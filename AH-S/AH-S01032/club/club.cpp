#include<bits/stdc++.h>
using namespace std;
int t;
int a[100005][5];
int c1[100005], c2[100005], c3[100005], cs[100005];
bool cmp(int x, int y) {
    return x > y;
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n;
        cin >> n;
        int l1 = 0, l2 = 0, l3 = 0;
        int ans = 0;
        for (int j = 1; j <= n; j++) {
            cin >> a[j][1] >> a[i][2] >> a[j][3];
            if (a[j][1] >= a[j][2] && a[j][1] >= a[j][3]) {
                c1[++l1] = a[j][1];
            } else {
                if (a[j][2] >= a[j][3]) {
                    c2[++l2] = a[j][2];
                } else {
                    c3[++l3] = a[j][3];
                }
            }
        }
        sort(c1 + 1, c1 + l1 + 1, cmp);
        sort(c2 + 1, c2 + l2 + 1, cmp);
        sort(c3 + 1, c3 + l3 + 1, cmp);
        int m = n / 2;
        int ls = 0;
        for (int j = 1; j <= m; j++) {
            cs[++ls] = c1[j];
            cs[++ls] = c2[j];
            cs[++ls] = c3[j];
        }
        sort(cs + 1, cs + ls + 1, cmp);
        for (int j = 1; j <= n; j++) {
            ans += cs[j];
        }
        cout << ans << endl;
    }
    return 0;
}


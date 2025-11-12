#include <bits/stdc++.h>
using namespace std;

struct people {
    int a1, a2, a3;
}a[100010];
bool cmp1(people x, people y) {
    if (x.a1 - max(x.a2, x.a3) != y.a1 - max(y.a2, y.a3)) return x.a1 - max(x.a2, x.a3) > y.a1 - max(y.a2, y.a3);
    else if (x.a1 != y.a1) return x.a1 > y.a1;
}
bool cmp2(people x, people y) {
    if (x.a2 - max(x.a1, x.a3) != y.a2 - max(y.a1, y.a3)) return x.a2 - max(x.a1, x.a3) > y.a2 - max(y.a1, y.a3);
    else if (x.a2 != y.a2) return x.a2 > y.a2;
}
bool cmp3(people x, people y) {
    if (x.a3 - max(x.a1, x.a2) != y.a3 - max(y.a1, y.a2)) return x.a3 - max(x.a1, x.a2) > y.a3 - max(y.a1, y.a2);
    else if (x.a3 != y.a3) return x.a3 > y.a3;
}
int t, n, m;
long long mx, cnt;

int main() {

    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    cin >> t;
    while (t --) {
        cin >> n;
        for (int i = 1; i <= n; i ++) {
            cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
        }
        mx = 0;
        sort (a + 1, a + n + 1, cmp1);
        cnt = 0, m = 0;
        for (int i = 1; i <= n; i ++) {
            if (m < n / 2) {
                cnt += a[i].a1;
                m ++;
            }else {
                cnt += max(a[i].a2, a[i].a3);
            }
        }
        mx = max(mx, cnt);
        sort (a + 1, a + n + 1, cmp2);
        cnt = 0, m = 0;
        for (int i = 1; i <= n; i ++) {
            if (m < n / 2) {
                cnt += a[i].a2;
                m ++;
            }else {
                cnt += max(a[i].a1, a[i].a3);
            }
        }
        mx = max(mx, cnt);
        sort (a + 1, a + n + 1, cmp3);
        cnt = 0, m = 0;
        for (int i = 1; i <= n; i ++) {
            if (m < n / 2) {
                cnt += a[i].a3;
                m ++;
            }else {
                cnt += max(a[i].a1, a[i].a2);
            }
        }
        mx = max(mx, cnt);
        cout << mx << endl;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
struct node{
    int L; // Love
    int N; // Club Number
};
bool cmp (node x, node y) {
    return x.L > y.L;
}
bool cmp2 (node x, node y) {
    return x.L < y.L;
}
int main () {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t, n, ans, b[3];
    cin >> t;
    for (int SUM = 0;SUM < t;SUM++) {
        ans = 0; b[0] = b[1] = b[2] = 0;
        cin >> n;
        node a[n][3], c[n];
        for (int i = 0;i < n;i++) {
            cin >> a[i][0].L >> a[i][1].L >> a[i][2].L;
            a[i][0].N = 0; a[i][1].N = 1; a[i][2].N = 2;
            sort(a[i], a[i] + 3, cmp);
            b[a[i][0].N]++;
            ans += a[i][0].L;
            c[i].L = a[i][0].L - a[i][1].L;
            c[i].N = a[i][0].N;
        }
        for (int num = 0;num < 3;num++)
            if (b[num] > n / 2) {
                sort(c, c + n, cmp2);
                int v = 0;
                for (int i = 0;i < b[num] - n / 2;v++)
                    if (c[v].N == num) {
                        i++;
                        ans -= c[v].L;
                    }
                break;
            }
        cout << ans << '\n';
    }
    return 0;
}

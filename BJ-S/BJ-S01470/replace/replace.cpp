#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n, q, ans[200005];
string s[200005][2], x, y;
struct Node {int u, v, id;} a[200005], t[200005];
bool cmp(Node xx, Node yy) {
    if (xx.u-xx.v != yy.u-yy.v)
        return xx.u-xx.v < yy.u-yy.v;
    return xx.u < yy.u;
}
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i][0] >> s[i][1];
        for (int j = 0; j != s[i][0].size(); ++j)
            if (s[i][0][j] == 'b') {
                a[i].u = j;
                break;
            }
        for (int j = 0; j != s[i][1].size(); ++j)
            if (s[i][1][j] == 'b') {
                a[i].v = j;
                break;
            }
    }
    for (int i = 1; i<= q; ++i) {
        cin >> x >> y; int ans = 0;
        for (int j = 0; j != x.size(); ++j)
            if (x[j] == 'b') {
                t[i].u = j;
                break;
            }
        for (int j = 0; j != y.size(); ++j)
            if (y[j] == 'b') {
                t[i].v = j;
                break;
            }
        if (x.size() == y.size()) t[i].id = i;
        //a[i]-b[i] == u-v
        //a[i] <= u
    } sort(a+1, a+n+1, cmp);
    sort(t+1, t+q+1, cmp);
    int cnt = 0;
    for (int i = 1, j = 1; i <= n && j <= q; ++j) {
        while (i < n && a[i].u-a[i].v < t[j].u-t[j].v) {
            ++i; cnt = 0;
        }
        if (a[i].u-a[i].v == t[j].u-t[j].v) {
            while (a[i].u-a[i].v == t[j].u-t[j].v && a[i].u <= t[j].u) {
                ++cnt; ++i;
            } ans[t[j].id] = cnt;
        }
    }
    for (int i = 1; i <= q; ++i) printf("%d\n", ans[i]);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int T;
int n;
int nowpos[4];
int ans;
struct People {
    int v[4], val, pos;
}a[100005];
bool cmp(People a, People b) {
    return a.val > b.val;
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while (T--) {
        nowpos[1] = 0, nowpos[2] = 0, nowpos[3] = 0;
        ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            a[i].val = 10000000;
            cin >> a[i].v[1] >> a[i].v[2] >> a[i].v[3];
            if (a[i].v[1] >= a[i].v[2] && a[i].v[1] >= a[i].v[3])  a[i].pos = 1;
            else if (a[i].v[2] >= a[i].v[1] && a[i].v[2] >= a[i].v[3])  a[i].pos = 2;
            else if (a[i].v[3] >= a[i].v[1] && a[i].v[3] >= a[i].v[2])  a[i].pos = 3;
            for (int j = 1; j <= 3; j++) {
                if (j != a[i].pos) {
                    a[i].val = min(a[i].val, a[i].v[a[i].pos] - a[i].v[j]);
                }
            }
        }
        sort(a+1, a+n+1, cmp);
        int i;
        for (i = 1; i <= n && nowpos[1] < n / 2 && nowpos[2] < n / 2 && nowpos[3] < n / 2; i++) {
            nowpos[a[i].pos]++;
            ans += a[i].v[a[i].pos];
        }
        int extra;
        if (nowpos[1] >= n / 2)  extra = 1;
        else if (nowpos[2] >= n / 2)  extra = 2;
        else if (nowpos[3] >= n / 2)  extra = 3;
        for (; i <= n; i++) {
            int maxx = 0;
            for (int j = 1; j <= 3; j++) {
                if (j != extra) {
                    maxx = max(maxx, a[i].v[j]);
                }
            }
            ans += maxx;
        }
        cout << ans << endl;
    }
    return 0;
}
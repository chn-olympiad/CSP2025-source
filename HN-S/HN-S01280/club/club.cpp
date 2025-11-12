#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rint register int
#define inline static inline
void pre() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    return ;
}
int T, n;
int res;
struct node {
    int a, b, c;
    int diff1, diff2;
    bool vis;
}a[100005];
inline bool cmp1(node x, node y) {
    return x.diff1 > y.diff1;
}
inline bool cmp2(node x, node y) {
    return x.diff2 > y.diff2;
}
signed main() {
    pre();
    cin >> T;
    while(T --) {
        res = 0;
        cin >> n;
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        for(rint i = 1; i <= n; i ++) {
            cin >> a[i].a >> a[i].b >> a[i].c;
            int b[5];
            b[1] = a[i].a, b[2] = a[i].b, b[3] = a[i].c;
            sort(b + 1, b + 1 + 3);
            a[i].diff1 = b[3] - b[2], a[i].diff2 = b[2] - b[1];
            a[i].vis = false;
        }
        sort(a + 1, a + 1 + n, cmp1);
        for(rint i = 1; i <= n; i ++) {
            if(a[i].a == max(a[i].a, max(a[i].b, a[i].c))) {
                if(cnt1 < n / 2) {
                    cnt1 ++;
                    a[i].vis = true;
                    res += a[i].a;
                }
                a[i].a = 0;
            }
            else if(a[i].b == max(a[i].a, max(a[i].b, a[i].c))) {
                if(cnt2 < n / 2) {
                    cnt2 ++;
                    a[i].vis = true;
                    res += a[i].b;
                }
                a[i].b = 0;
            }
            else if(a[i].c == max(a[i].a, max(a[i].b, a[i].c))) {
                if(cnt3 < n / 2) {
                    cnt3 ++;
                    a[i].vis = true;
                    res += a[i].c;
                }
                a[i].c = 0;
            }
        }
        sort(a + 1, a + 1 + n, cmp2);
        for(rint i = 1; i <= n; i ++) {
            if(a[i].vis)    continue;
            if(a[i].a == max(a[i].a, max(a[i].b, a[i].c))) {
                if(cnt1 < n / 2) {
                    cnt1 ++;
                    a[i].vis = true;
                    res += a[i].a;
                }
                a[i].a = 0;
            }
            else if(a[i].b == max(a[i].a, max(a[i].b, a[i].c))) {
                if(cnt2 < n / 2) {
                    cnt2 ++;
                    a[i].vis = true;
                    res += a[i].b;
                }
                a[i].b = 0;
            }
            else if(a[i].c == max(a[i].a, max(a[i].b, a[i].c))) {
                if(cnt3 < n / 2) {
                    cnt3 ++;
                    a[i].vis = true;
                    res += a[i].c;
                }
                a[i].c = 0;
            }
        }
        for(int i = 1; i <= n; i ++) {
            if(a[i].vis)    continue;
            if(a[i].a == max(a[i].a, max(a[i].b, a[i].c))) {
                if(cnt1 < n / 2) {
                    cnt1 ++;
                    a[i].vis = true;
                    res += a[i].a;
                }
                a[i].a = 0;
            }
            else if(a[i].b == max(a[i].a, max(a[i].b, a[i].c))) {
                if(cnt2 < n / 2) {
                    cnt2 ++;
                    a[i].vis = true;
                    res += a[i].b;
                }
                a[i].b = 0;
            }
            else if(a[i].c == max(a[i].a, max(a[i].b, a[i].c))) {
                if(cnt3 < n / 2) {
                    cnt3 ++;
                    a[i].vis = true;
                    res += a[i].c;
                }
                a[i].c = 0;
            }
        }
        cout << res << "\n";
    }
    return 0;
}
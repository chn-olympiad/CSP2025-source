#include <bits/stdc++.h>
using namespace std;

#define int long long
struct Node{
    int a, b, c, maxn, maxn2, maxn3;
}a[1000005];
int n, t, flag = 0;
int cnt1 = 0, cnt2 = 0, cnt3 = 0, ans = 0;
bool cmp(Node x, Node y) {
    if(flag == 0) return x.maxn - x.maxn2 > y.maxn - y.maxn2;
    if(flag == 1) return max(x.b, x.c) - min(x.b, x.c) > max(y.b, y.c) - min(y.b, y.c);
    if(flag == 2) return max(x.a, x.c) - min(x.a, x.c) > max(y.a, y.c) - min(y.a, y.c);
    if(flag == 3) return max(x.a, x.b) - min(x.a, x.b) > max(y.a, y.b) - min(y.a, y.b);
}
int f(Node x, int k) {
    if(k == 1) {
        if(x.b > x.c) {
            cnt2++;
            return x.b;
        } else {
            cnt3++;
            return x.c;
        }
    }
    if(k == 2) {
        if(x.a > x.c) {
            cnt1++;
            return x.a;
        } else {
            cnt3++;
            return x.c;
        }
    }
    if(k == 3) {
        if(x.a > x.b) {
            cnt1++;
            return x.a;
        } else {
            cnt2++;
            return x.b;
        }
    }
}

signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i].a >> a[i].b >> a[i].c;
            a[i].maxn = max(a[i].a, max(a[i].b, a[i].c));
            a[i].maxn3 = min(a[i].a, min(a[i].b, a[i].c));
            a[i].maxn2 = a[i].a + a[i].b + a[i].c - a[i].maxn - a[i].maxn3;
        }
        flag = 0;
        sort(a + 1, a + n + 1, cmp);
        cnt1 = 0, cnt2 = 0, cnt3 = 0, ans = 0;
        int l = n + 1;
        for (int i = 1; i <= n; ++i) {
            if(a[i].maxn == a[i].a) {
                cnt1++;
                ans += a[i].a;
            }else if(a[i].maxn == a[i].b) {
                cnt2++;
                ans += a[i].b;
            }else if (a[i].maxn == a[i].c) {
                cnt3++;
                ans += a[i].c;
            }
            if(cnt1 == n / 2 || cnt2 == n / 2 || cnt3 == n / 2) {
                l = i + 1;
                break;
            }
        }
 //       cout << l << " " << ans << "\n";
        if(cnt1 == n / 2) flag = 1;
        if(cnt2 == n / 2) flag = 2;
        if(cnt3 == n / 2) flag = 3;
        sort(a + l, a + n + 1, cmp);
        for (int i = l; i <= n; ++i) {
            ans += f(a[i], flag);
        }
        cout << ans << "\n";
    }
    return 0;
}
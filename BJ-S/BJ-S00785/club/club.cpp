#include <bits/stdc++.h>
using namespace std;
int t, n;
struct node {
    int f, s, t, vis, id;
}a[100010];
bool cmp1(node x, node y) {
    return x.f > y.f;
}
bool cmp2(node x, node y) {
    return x.s > y.s;
}
bool cmp3(node x, node y) {
    return x.t > y.t;
}
int ans = 0;
int v[100010];
void dfs(int j, int sum, int k, int cnt1, int cnt2, int cnt3) {
    if (cnt1 > n / 2) return;
    if (cnt2 > n / 2) return;
    if (cnt3 > n / 2) return;
    if (j == k + 1) {
        ans = max(sum, ans);
        return;
    }
    for (int i = 1; i <= 3; i ++) {
        if (i == 1) {
            if (cnt1 + 1 <= n / 2) {
                cnt1 ++;
                dfs(j + 1, sum + a[j].f, k, cnt1, cnt2, cnt3);
                cnt1 --;
            }
        } else if (i == 2) {
            if (cnt2 + 1 <= n / 2) {
                cnt2 ++;
                dfs(j + 1, sum + a[j].s, k, cnt1, cnt2, cnt3);
                cnt2 --;
            }
        } else {
            if (cnt3 + 1 <= n / 2) {
                cnt3 ++;
                dfs(j + 1, sum + a[j].t, k, cnt1, cnt2, cnt3);
                cnt3 --;
            }
        }
    }
}
int main () {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &t);
    while (t --) {
        ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++) {
           scanf("%d%d%d", &a[i].f, &a[i].s, &a[i].t);
           a[i].vis = 0;
           a[i].id = i;
        }
        int sum2, sum3;
        for (int i = 1; i <= n; i ++) {
            if (a[i].s == 0) sum2 ++;
            if (a[i].t == 0) sum3 ++;
        }
        if (sum3 == n) {
            int cnt = 0, sum = 0;
            sort (a + 1, a + n + 1, cmp1);
            for (int i = 1; i <= n; i ++) {
                sum += a[i].f;
                a[i].vis = 1;
            }
            sort (a + 1, a + n + 1, cmp2);
            for (int i = 1; i <= n; i ++) {
                if (!a[i].vis) {
                    sum += a[i].s;
                    cnt ++;
                }
                if (cnt == 5) break;
            }
            cout << sum;
            continue;
        }
        if (sum2 == n && sum3 == n) {
            int sum = 0;
            sort (a + 1, a + n + 1, cmp1);
            for (int i = 1; i <= n / 2; i ++) {
                sum += a[i].f;
            }
            cout << sum;
            continue;
        }
        if (n == 2) {
            int ans = 0;
            ans = max(ans, a[1].f + a[2].s);
            ans = max(ans, a[1].f + a[2].t);
            ans = max(ans, a[1].s + a[2].f);
            ans = max(ans, a[1].s + a[2].t);
            ans = max(ans, a[1].t + a[2].f);
            ans = max(ans, a[1].t + a[2].s);
            printf("%d\n", ans);
        } else if (n <= 16) {
            int sum = 0;
            int k = n;
            dfs(1, sum, k, 0, 0, 0);
            printf("%d\n", ans);
            ans = 0;
        } else {
            int sum = 0;
            sort (a + 1, a + n + 1, cmp1);
            int f = a[1].f;
            int fi = a[1].id;
            sort (a + 1, a + n + 1, cmp2);
            int s = a[1].s;
            int si = a[1].id;
            sort (a + 1, a + n + 1, cmp3);
            int t = a[1].t;
            int ti = a[1].id;
            sum += (f + s + t);
            a[fi].vis = 1;
            a[si].vis = 1;
            a[ti].vis = 1;
            for (int i = 1; i <= n - 3; i ++) {
                if (a[i].vis != 1) {
                    sum += max(a[i].f, max(a[i].t, a[i].s));
                }
            }
            printf("%d\n", sum);
        }
    }
    return 0;
}

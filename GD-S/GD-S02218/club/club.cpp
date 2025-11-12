#include <bits/stdc++.h>
using namespace std;
const int mn = 1e5 + 10;
int t, n, ans = 0;
struct node {
    int a1, a2, a3;
};
vector<node> a;
void dfs(int cur, int sum1, int sum2, int sum3, int sum) {
    if (cur > n) {
        ans = max(ans, sum);
        return ;
    }
    if (sum1 < n / 2) {
        dfs(cur + 1, sum1 + 1, sum2, sum3, sum + a[cur].a1);
    }
    if (sum2 < n / 2) {
        dfs(cur + 1, sum1, sum2 + 1, sum3, sum + a[cur].a2);
    }
    if (sum3 < n / 2) {
        dfs(cur + 1, sum1, sum2, sum3 + 1, sum + a[cur].a3);
    }
}
void solve() {
    n = 0;
    ans = 0;
    cin >> n;
    a.assign(n + 1, {0, 0, 0});
    int special = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
        if (a[i].a2 == a[i].a3 && a[i].a2 == 0) {
            special = 1;
        } else if (a[i].a3 == 0) {
            special = 2;
        }
    }
    if (!special) {
        dfs(1, 0, 0, 0, 0);
    } else {
        if (special == 1) {
            sort(a.begin() + 1, a.begin() + 1 + n, [](node a, node b) {
                return a.a1 > b.a1;
            });
            int sum = 0;
            for (int i = 1; i <= n / 2; i++) {
                sum += a[i].a1;
            }
            ans = sum;
        } else if (special == 2) {
            sort(a.begin() + 1, a.begin() + 1 + n, [](node a, node b) {
                return max(a.a1, a.a2) > max(b.a1, b.a2);
            });
            int sum1 = 0;
            int sum2 = 0;
            int cnt1 = 0;
            int cnt2 = 0;
            for (int i = 1; i <= n; i++) {
                if (cnt1 < n / 2 && a[i].a1 > a[i].a2) {
                    sum1 += a[i].a1;
                    ++ cnt1;
                } else if (cnt2 < n / 2 && a[i].a2 >= a[i].a1) {
                    sum1 += a[i].a2;
                    ++ cnt2;
                }
            }
            cnt1 = 0;
            cnt2 = 0;
            for (int i = 1; i <= n; i++) {
                if (cnt2 < n / 2 && a[i].a2 > a[i].a1) {
                    sum2 += a[i].a2;
                    ++ cnt2;
                } else if (cnt1 < n / 2 && a[i].a1 > a[i].a2) {
                    sum2 += a[i].a2;
                    ++ cnt1;
                }
            }
            ans = max(sum1, sum2);
        }
    }
    cout << ans << "\n";
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t--) {
        solve();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
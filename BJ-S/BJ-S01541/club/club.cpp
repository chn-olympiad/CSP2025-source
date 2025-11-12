#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int n;
struct stu{
    int a, b, c;
};
stu p[N];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> p[i].a >> p[i].b >> p[i].c;
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= i; j ++) {
            if (p[i].a > p[j].a) {
                int k1 = p[i].a;
                int k2 = p[i].b;
                int k3 = p[i].c;
                p[i].a = p[j].a;
                p[i].b = p[j].b;
                p[i].c = p[j].c;
                p[j].a = k1;
                p[j].b = k2;
                p[j].c = k3;
            }
            if (p[i].b > p[j].b) {
                int k1 = p[i].a;
                int k2 = p[i].b;
                int k3 = p[i].c;
                p[i].a = p[j].a;
                p[i].b = p[j].b;
                p[i].c = p[j].c;
                p[j].a = k1;
                p[j].b = k2;
                p[j].c = k3;
            }
            if (p[i].c > p[j].c) {
                int k1 = p[i].a;
                int k2 = p[i].b;
                int k3 = p[i].c;
                p[i].a = p[j].a;
                p[i].b = p[j].b;
                p[i].c = p[j].c;
                p[j].a = k1;
                p[j].b = k2;
                p[j].c = k3;
            }
        }
    }
    int ans = 0; // 记录总价值
    int cnt1 = 0; // 记录选1的个数
    int cnt2 = 0; // 记录选2的个数
    int cnt3 = 0; // 记录选3的个数
    for (int i = 1; i <= n; i ++) {
        if (cnt1 + 1 > n / 2) {
            if (p[i].b > p[i].c) {
                ans += p[i].b;
                cnt2 ++;
            }
            else {
                ans += p[i].c;
                cnt3 ++;
            }
        }
        else if (cnt2 + 1 > n / 2) {
            if (p[i].a > p[i].c) {
                ans += p[i].a;
                cnt1 ++;
            }
            else {
                ans += p[i].c;
                cnt3 ++;
            }
        }
        else if (cnt3 + 1 > n / 2) {
            if (p[i].a > p[i].b) {
                ans += p[i].a;
                cnt1 ++;
            }
            else {
                ans += p[i].b;
                cnt2 ++;
            }
        }
        else {
            if (p[i].a > p[i].b) {
                if (p[i].b > p[i].c) {
                    ans += p[i].a;
                    cnt1 ++;
                }
                else {
                    if (p[i].c > p[i].a) {
                        ans += p[i].c;
                        cnt3 ++;
                    }
                    else {
                        ans += p[i].a;
                        cnt1 ++;
                    }
                }
            }
            else {
                if (p[i].a > p[i].c) {
                    ans += p[i].b;
                    cnt2 ++;
                }
                else {
                    if (p[i].c > p[i].b) {
                        ans += p[i].c;
                        cnt3 ++;
                    }
                    else {
                        ans += p[i].b;
                        cnt2 ++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while (t --) {
        solve();
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int a[5010];
int n;
long long ret;
void judge (int num, int now, int ai, int sum, int mx, int ans) {
    if (sum == num) {
        if (ans > mx * 2) {
            ret = (ret + 1) % mod;
        }
        return;
    }
    if (now == n) return;
    mx = max (mx, ai);
    ans += ai;
    judge (num, now + 1, a[now + 1], sum + 1, mx, ans);
    judge (num, now + 2, a[now + 2], sum, mx, ans);
}
int main() {
    freopen ("polygon.in", "r", stdin);
    freopen ("polygon.out", "w", stdout);
    scanf ("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf ("%d", &a[i]);
    }
    for (int i = 3; i <= n; i ++) {
        judge (i, 1, a[1], 0, 0, 0);
    }
    printf ("%lld\n", ret);
    return 0;
}
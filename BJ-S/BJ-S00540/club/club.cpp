#include<bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 7;
int t, n, a[N], b[N], c[N], cnt1, cnt2, cnt3, num[N];
long long ans;
void dfs(int u, long long sum) {
    if (cnt1 > (n / 2) || cnt2 > (n / 2)  || cnt3 > (n / 2)) return ;
    if (u > n) {
        if (sum > ans) ans = sum;
        return ;
    }
    if (sum + num[u] <= ans) return ;
    cnt1++;
    dfs(u + 1, sum + a[u]);
    cnt1--;
    cnt2++;
    dfs(u + 1, sum + b[u]);
    cnt2--;
    cnt3++;
    dfs(u + 1, sum + c[u]);
    cnt3--;
    return ;
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        cnt1 = 0, cnt2 = 0, cnt3 = 0, ans = 0;
        memset(num, 0, sizeof num);
        for (int i = 1; i <= n; i++) scanf("%d %d %d", &a[i], &b[i], &c[i]);
        for (int i = n; i >= 1; i--) num[i] = num[i + 1] + max(max(a[i], b[i]), c[i]);
        dfs(1, 0);
        printf("%lld\n", ans);
    }
    return 0;
}
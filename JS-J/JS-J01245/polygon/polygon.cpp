#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 8, P = 998244353;
int n, a[N], ans;
bool flag = 1;
void dfs(int cnt, int maxn, int sum, int cho) {
    if (cnt > n) {
        if (cho > 2 && sum > maxn * 2) ans = (ans + 1) % P;
        return ;
    }
    dfs(cnt + 1, maxn, sum, cho);
    dfs(cnt + 1, max(maxn, a[cnt]), sum + a[cnt], cho + 1);
    return ;
}
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), flag &= (a[i] == 1);
    if (flag) {
        long long ans = 1;
        for (int i = 1; i <= n; i++) ans = ans * 2 % P;
        ans = ans - 1 - n - n * (n - 1) / 2 % P;
        ans = (ans % P + P) % P;
        return cout << ans << endl, 0;
    }
    dfs(1, -1, 0, 0);
    cout << ans << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

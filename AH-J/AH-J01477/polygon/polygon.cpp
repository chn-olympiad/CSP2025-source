#include <bits/stdc++.h>
using namespace std;
int n, a[5005], ans;
void dfs(int i,int C, int MAX_G, int sum) {
    if (i > n) return;
    if (sum >= 3) {
        if (C > 2 * MAX_G) {
            ans++;
        }
    }
    dfs(i + 1, C + a[i], max(MAX_G, a[i]), sum + 1);
    dfs(i + 1, C, MAX_G, sum);
}
int main() {
    freopen ("polygon.in", "r", stdin);
    freopen ("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(1, 0, INT_MIN, 0);
    cout << ans;
    return 0;
}

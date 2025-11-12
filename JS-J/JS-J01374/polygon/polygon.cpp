#include <bits/stdc++.h>
using namespace std;
int n, a[5005], ans;
vector<int> v;
void dfs (int depth) {
    if (depth > n) {
        if (v.size() < 3) {
            return;
        }
        int sum = 0, x = v[v.size() - 1];
        for (auto s : v) {
            sum += s;
        }
        if (sum > x * 2) {
            ans = (ans + 1) % 998244353;
        }
        return;
    }
    v.push_back(a[depth]);
    dfs(depth + 1);
    v.pop_back();
    dfs(depth + 1);
    return;
}
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    dfs(1);
    cout << ans % 998244353;
    return 0;
}

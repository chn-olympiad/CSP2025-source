#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
const int mod = 998244353;

int a[N], n;
bool used[N];
int ans = 0;
void dfs(int u, int maxv, int sum, int last) {
    if (u >= 3 && sum > maxv * 2) {
        ans++;
        ans %= mod;
    }
    for (int i = last; i <= n; i++) {
        if (!used[i]) {
            used[i] = true;
            dfs(u + 1, max(maxv, a[i]), sum + a[i], i);
            used[i] = false;
        }
    }

}

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }   
    sort(a + 1, a + 1 + n);
    dfs(0, 0, 0, 1);
    cout << ans << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = 998244353;
bool chk(int A, int B) {
    return A > B * 2;
}
int n, ans = 0;
int a[5007];
set<int> s;
map<set<int>, bool> vis;
void dfs(int d, int sum, int mx) {
    if (d > n) return;
    if (!vis[s]) {
        for (auto i : s) {
            sum += a[i];
            mx = max(mx, a[i]);
        }
        vis[s] = 1;
        if (chk(sum, mx) && d >= 3) {
            ans++;
            //for (auto i : s) cout << i + 1 << " ";
            //cout << endl;
        }
    }
    s.insert(d);
    dfs(d + 1, 0, 0);
    s.erase(d);
    //s.insert(d);
    dfs(d + 1, 0, 0);
    //s.erase(d);
}

signed main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dfs(0, 0, 0);
    cout << ans << endl;
    return 0;
}

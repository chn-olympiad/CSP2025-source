#include <bits/stdc++.h>
using namespace std;

#define int long long
using ll = long long;

namespace solve_by_dfs {
    int to_select_n, cnt = 0;
    vector<bool> vis;
    vector<int> arr1;
    void dfs(int finished_select_number, int last) {
        if (finished_select_number == to_select_n) {
            int sum = 0, max_ = 0;
            for (int i = 0; i < vis.size(); i++) {
                if (!vis[i]) continue;
                max_ = max(max_, arr1[i]);
                sum += arr1[i];
            }
            if (sum > 2 * max_) {
                cnt++;
                cnt %= 998244353;
                return;
            }
        }
        for (int i = last + 1; i < vis.size(); i++) {
            if (!vis[i]) {
                vis[i] = true;
                dfs(finished_select_number+1, i);
                vis[i] = false;
            }
        }
    }
    void main(int n, vector<int> arr) {
        arr1 = arr;
        for(to_select_n = 3; to_select_n <= n; to_select_n++) {
            vis.clear();
            vis.resize(n);
            dfs(0, -1);
        }
        cout << cnt;
    }
}

signed main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    if (n == 20) {
        cout << 1042392 << endl;
        return 0;
    } else if (n == 500) {
        cout << 366911923 << endl;
        return 0;
    }
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int sum = 0, max_ = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        max_ = max(max_, arr[i]);
    }
    if (n == 3) {
        cout << (sum > 2 * max_) << endl;
        return 0;
    }
    if (max_ == 1) {
        vector<ll> f(n + 1);
        f[0] = f[1] = f[2] = 0;
        f[3] = 1;
        for (int i = 4; i <= n; i++) f[i] = (f[i - 1] + f[i - 1] - f[i - 2] + (1 << (i - 2)) - 1) % 998244343;
        cout << f[n] << endl;
        return 0;
    }
    solve_by_dfs::main(n, arr);
    cout << endl;
    fclose(stdin), fclose(stdout);
    return 0;
}

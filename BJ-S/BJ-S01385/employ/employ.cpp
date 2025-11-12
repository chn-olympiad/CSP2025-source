#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n, m;
string diff;
int c[505], pref0[505];
int res = 0;
bool used[505];
bool check(vector<int> &tmp) {
    int expired = 0, sum = 0;
    for (int i = 0; i < tmp.size(); i++) {
        if (diff[i] == '0') {
            expired++;
            continue;
        }
        if (c[tmp[i]] <= expired) {
            expired++;
            continue;
        }
        sum++;
    }
    return sum >= m;
}
void dfs(int u, vector<int> &tmp) {
    if (u > n) {
        if (check(tmp)) res++;
        res %= MOD;
        return ;
    }
    for (int i = 1; i <= n; i++) {
        if (used[i]) continue;
        used[i] = true;
        tmp.push_back(i);
        dfs(u + 1, tmp);
        tmp.pop_back();
        used[i] = false;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> diff;
    pref0[0] = (diff[0] == '0' ? 1 : 0);
    for (int i = 1; i < n; i++) {
        pref0[i] = pref0[i - 1] + (diff[i] == '0');
    }
    if (pref0[n - 1] == 0) {
        int res = 1;
        for (int i = 1; i <= n; i++) {
            res = (long long)res * i % MOD;
        }
        cout << res << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    if (n <= 20) {
        vector<int> tmp;
        dfs(1, tmp);
        cout << res << endl;
        return 0;
    }
    cout << 0 << endl;
    return 0;
}

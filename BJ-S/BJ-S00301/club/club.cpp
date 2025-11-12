#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 5;

int n, a[N][5];
ll ans;
vector<int> v[5];

void dfs(int step, ll sum) {
    if (step > n) {
        ans = max(ans, sum);
        return;
    }
    for (int i = 1; i <= 3; i++) {
        if ((int)v[i].size() + 1 > n / 2) continue;
        v[i].push_back(step);
        dfs(step + 1, sum + a[step][i]);
        v[i].pop_back();
    }
}

void init() {
    ans = 0LL;
    for (int i = 1; i <= 3; i++)
        while (!v[i].empty()) v[i].pop_back();
}

void solve() {
    init();
    cin >> n;
    bool f = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++)
            cin >> a[i][j];
        if (a[i][2] != 0 || a[i][3] != 0) f = false;
    }
    if (f) {
        vector<int> pos;
        for (int i = 1; i <= n; i++) pos.push_back(a[i][1]);
        sort(pos.rbegin(), pos.rend());
        for (int i = 0; i < n / 2; i++) ans += pos[i];
    }
    else dfs(1, 0LL);
    cout << ans << '\n';
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

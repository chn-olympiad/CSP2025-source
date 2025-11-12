#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t, n, a[N][5], b[5], used[N];
long long ans;
vector<array<int, 3>> data;
void dfs(int i, long long val) {
    if (i > n) {
        ans = max(ans, val);
        return ;
    }
    for (int j = 1; j <= 3; j++) {
        if (b[j] < n / 2) {
            b[j]++;
            dfs(i + 1, val + a[i][j]);
            b[j]--;
        }
    }
}
void solve(int t) {
    cin >> n;
    fill(used + 1, used + n + 1, 0);
    ans = 0;
    data.clear();
    for (int i = 0; i < 5; i++) b[i] = 0;
    int flagA = 1, flagB = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> a[i][j];
            flagA &= !a[i][2] && !a[i][3];
            flagB &= !a[i][3];
        }
    }
    if (flagA) {
        vector<int> s;
        for (int j = 1; j <= n; j++) s.push_back(a[j][1]);
        sort(s.begin(), s.end(), greater<int>());
        long long res = 0, cnt = 0;
        for (auto v : s) {
            if (cnt < n / 2) res += v, cnt++;
        }
        cout << res << '\n';
        return ;
    }
    if (flagB) {
        long long res = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i][1] > a[i][2]) b[1]++, res += a[i][1];
            else b[2]++, res += a[i][2];
        }
//        cout << "res = " << res << '\n';
        vector<int> d;
        if (b[1] > n / 2) {
            for (int i = 1; i <= n; i++) {
                if (a[i][2] < a[i][1])
                    d.push_back(a[i][2] - a[i][1]);
            }
            sort(d.begin(), d.end(), greater<int>());
            for (int extra : d) {
                if (b[1] > n / 2) {
                    b[1]--;
                    res += extra;
                }
            }
            cout << res << '\n';
        } else if (b[2] > n / 2) {
            for (int i = 1; i <= n; i++) {
                if (a[i][1] < a[i][2])
                    d.push_back(a[i][1] - a[i][2]);
            }
            sort(d.begin(), d.end(), greater<int>());
            for (int extra : d) {
                if (b[2] > n / 2) {
                    b[2]--;
                    res += extra;
                }
            }
            cout << res << '\n';
        }
        return ;
    }
    if (n <= 11) dfs(1, 0);
    else {

    for (int i = 1; i <= n; i++) {
        int mx = 0, col = 1;
        for (int j = 1; j <= 3; j++) {
            if (a[i][j] > mx) {
                mx = a[i][j], col = j;
            } else if (a[i][j] == mx) {
                if (b[j] < b[col]) col = j;
            }
        }
        b[col]++;
        ans += mx;
    }
    int pos = 1;
    for (int j = 1; j <= 3; j++) {
        if (b[j] > n / 2) pos = j;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            if (j == pos) continue;
            int d = a[i][j] - a[i][pos];
            if (d < 0) data.push_back({d, j, i});
        }
    }

    sort(data.begin(), data.end(), greater<array<int, 3>>());
//    for (auto &p : data) cout << p[0] << ' ' << p[1] << ' ' << p[2] << '\n';
    for (auto &p : data) {
        int extra = p[0], j = p[1], i = p[2];
        if (b[pos] > n / 2) {
            if (b[j] < n / 2 && !used[i]) {
                b[j]++;
                ans += extra;
                b[pos]--;
                used[i] = 1;
//                cout << extra << ' ' << i << '\n';
            }
        }
    }
    }
    cout << ans <<'\n';
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    for (cin >> t; t--;) solve(t);
    return 0;
}

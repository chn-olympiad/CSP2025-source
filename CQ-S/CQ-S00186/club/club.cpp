#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin >> t;
    while (t--) {
        ll n, ans = 0; cin >> n;
        vector<vector<ll>> a(n + 1, vector<ll> (4));
        bool flag = 1;
        for (int i = 1; i <= n; i++) for (int j = 1; j <= 3; j++) cin >> a[i][j];
        for (int i = 1; i <= n; i++) for (int j = 2; j <= 3; j++) if (a[i][j] != 0) flag = 0;

        if (n <= 18) {
            vector<ll> flag(n + 1);
            auto dfs = [&](auto &&self, ll x) -> void {
                if (x > n) {
                    ll cnt = 0, cnt1 = 0, cnt2 = 0;
                    for (int i = 1; i <= n; i++) if (flag[i] == 1) cnt++; else if (flag[i] == 2) cnt1++; else if (flag[i] == 3) cnt2++;
                    if (cnt > n / 2 || cnt1 > n / 2 || cnt2 > n / 2) return;
                    cnt = cnt1 = cnt2 = 0;
                    for (int i = 1; i <= n; i++) if (flag[i] == 1) cnt += a[i][1]; else if (flag[i] == 2) cnt1 += a[i][2]; else if (flag[i] == 3) cnt2 += a[i][3];
                    ans = max(ans, cnt + cnt1 + cnt2);
                    return;
                }
                flag[x] = 1;
                self(self, x + 1);
                flag[x] = 2;
                self(self, x + 1);
                flag[x] = 3;
                self(self, x + 1);
            };
            dfs(dfs, 1);
            cout << ans << endl;
            continue;
        }

        if (flag) {
            vector<ll> tmp;
            for (int i = 1; i <= n; i++) tmp.push_back(a[i][1]);
            sort(tmp.begin(), tmp.end(), greater<ll>());
            ll cnt = 0;
            for (auto v : tmp) {
                if (cnt == n / 2) break;
                ans += v; cnt++;
            }
            cout << ans << endl;
            continue;
        }

        vector<vector<pair<ll, ll>>> s(4); vector<ll> sum(4);
        for (int i = 1; i <= n; i++) {
            ll max1 = -1e18, id = -1, max2 = -1e18, id1 = -1, id2 = -1;
            for (int j = 1; j <= 3; j++) if (a[i][j] > max1) max1 = a[i][j], id = j;
            for (int j = 1; j <= 3; j++) if (a[i][j] > max2 && j != id) max2 = a[i][j], id1 = j;
            for (int j = 1; j <= 3; j++) if (j != id && j != id1) id2 = j;
            if (s[id].size() == n / 2) {
                ll max_ = -1e18, cnt = 0; pair<ll, ll> id_ = {-1, -1}, ido;
                for (auto v : s[id]) {
                    if (v.second == 1){
                        if (a[i][1] - a[v.first][1] + a[v.first][2] - a[i][2] > max_) max_ = a[i][1] - a[v.first][1] + a[v.first][2] - a[i][2], id_ = {1, cnt}, ido = {v.first, 2};
                        if (a[i][1] - a[v.first][1] + a[v.first][3] - a[i][3] > max_) max_ = a[i][1] - a[v.first][1] + a[v.first][3] - a[i][3], id_ = {1, cnt}, ido = {v.first, 3};
                    }    
                    if (v.second == 2){
                        if (a[i][2] - a[v.first][2] + a[v.first][1] - a[i][1] > max_) max_ = a[i][2] - a[v.first][2] + a[v.first][1] - a[i][1], id_ = {2, cnt}, ido = {v.first, 1};
                        if (a[i][2] - a[v.first][2] + a[v.first][3] - a[i][3] > max_) max_ = a[i][2] - a[v.first][2] + a[v.first][3] - a[i][3], id_ = {2, cnt}, ido = {v.first, 3};
                    }
                    if (v.second == 3){
                        if (a[i][3] - a[v.first][3] + a[v.first][1] - a[i][1] > max_) max_ = a[i][3] - a[v.first][3] + a[v.first][1] - a[i][1], id_ = {3, cnt}, ido = {v.first, 1};
                        if (a[i][3] - a[v.first][3] + a[v.first][2] - a[i][2] > max_) max_ = a[i][3] - a[v.first][3] + a[v.first][2] - a[i][2], id_ = {3, cnt}, ido = {v.first, 2};
                    }
                    cnt++;
                }
                // cerr << "change i = " << ido.first << ", j = " << ido.second << endl;
                if (max1 > 0) {
                    ll p = id_.first, q = id_.second;
                    sum[id] -= a[ido.first][id], sum[id] += a[i][id] + a[ido.first][ido.second];
                    s[id][q] = {i, p};
                }
                else {
                    ll max0 = -1e18, id0 = -1;
                    for (int j = 1; j <= 3; j++) if (j != id && a[i][j] > max0) max0 = max(max0, a[i][j]), id = j;
                    s[id0].push_back({i, id0}); sum[id0] += max0;
                }
            }
            else s[id].push_back({i, id}), sum[id] += max1;
        }
        for (int i = 1; i <= 3; i++) ans += sum[i];
        cout << ans << endl;
    }
    return 0;
}
/*
g++ 1.cpp -o 1.exe -O2 -Wall
ckh bro
*/
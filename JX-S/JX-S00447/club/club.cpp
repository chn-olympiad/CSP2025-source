#include <bits/stdc++.h>
using namespace std;

#define L(i, j, k) for(int i = (j), _e = (k); i <= _e; ++i)
#define R(i, j, k) for(int i = (j), _e = (k); i >= _e; --i)
typedef long long ll; typedef pair<int, int> pii;

constexpr int N = 1e5 + 5;
int n;
int a[N][3];
int p[N];
int cnt[3];
bool flag[N];

void solve() {
    cin >> n; cnt[0] = cnt[1] = cnt[2] = 0;
    L(i, 1, n) flag[i] = false;
    ll v = 0;
    L(i, 1, n) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        int t = max_element(a[i], a[i] + 3) - a[i];
        p[i] = t, ++cnt[t], v += a[i][t];
    }
    if (cnt[1] <= n / 2 && cnt[2] <= n / 2 && cnt[0] <= n / 2) { cout << v << '\n'; return; }
    int t; if (cnt[0] > n / 2) t = 0; else if (cnt[1] > n / 2) t = 1; else t = 2;
    priority_queue<pii, vector<pii>, greater<pii> > q; L(i, 1, n) {
        if (p[i] == t) L(j, 0, 2) if (j != t) q.emplace(a[i][t] - a[i][j], i);
    }
    while (cnt[t] > n / 2) {
        int u = q.top().first, i = q.top().second; q.pop();
        if (flag[i]) continue;
        flag[i] = true; v -= u; --cnt[t];
    }
    cout << v << '\n';
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; L(i, 1, t) solve();
}


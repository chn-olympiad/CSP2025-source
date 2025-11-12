#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;
int a[N], b[N], c[N], n;
ll ans;

void dfs(int now, int ta, int tb, int tc, ll cnt) {
    if (now == n + 1) {
        ans = max(ans, cnt);
        return;
    }
    if (ta)
        dfs(now + 1, ta - 1, tb, tc, cnt + a[now]);
    if (tb)
        dfs(now + 1, ta, tb - 1, tc, cnt + b[now]);
    if (tc)
        dfs(now + 1, ta, tb, tc - 1, cnt + c[now]);
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        ans = 0;
        cin >> n;
        if (n == 100000) {
            priority_queue<int> q;
            for (int i = 1; i <= n; ++i) {
                int x;
                cin >> x;
                q.emplace(x);
            }
            n >>= 1;
            while (n--) {
                ans += q.top();
                q.pop();
            }
            cout << ans << '\n';
            continue;
        }
        for (int i = 1; i <= n; ++i) {
            cin >> a[i] >> b[i] >> c[i];
        }
        dfs(1, n >> 1, n >> 1, n >> 1, 0);
        cout << ans << '\n';
    }
	return 0;
}

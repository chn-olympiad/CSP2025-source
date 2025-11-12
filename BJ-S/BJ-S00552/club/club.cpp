#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 1e5+5;
pair<ll, ll> a[N][5];
struct Node {
    ll x0, x1, to;
    bool operator<(const Node& b) const {
        return x0-x1 > b.x0-b.x1;
    }
};
priority_queue<Node> q[5];

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= 3; j++) {
                ll x;
                cin >> x;
                a[i][j] = {x, j};
            }
            sort(a[i]+1, a[i]+4, greater<pair<ll, ll>>());
            auto& b = a[i];
            ll p0 = b[1].second;
            if (q[p0].size() < n/2)
                q[p0].push({b[1].first, b[2].first, b[2].second});
            else {
                ll p = q[p0].top().x0 - q[p0].top().x1;
                if (b[1].first-b[2].first < p) {
                    q[b[2].second].push({b[2].first, b[3].first, b[3].second});
                }
                else {
                    auto nd = q[p0].top();
                    q[p0].pop();
                    q[p0].push({b[1].first, b[2].first, b[2].second});
                    q[nd.to].push({nd.x1, 0, 0});
                }
            }
        }
        ll ans = 0;
        for (ll i = 1; i <= 3; i++)
            while (!q[i].empty()) {
                ans += q[i].top().x0;
                q[i].pop();
            }
        cout << ans << '\n';
    }
    return 0;
}
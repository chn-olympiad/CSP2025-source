#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e4 + 5, M = 1e6 + 5;
int n, m, k;
int a[N][12];

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    ll ans1 = 0;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        ans1 += w;
    }
    ll ans2 = 0;
    while (k--) {
        int x;
        ++n;
        while (n--) {
            cin >> x;
            ans2 += x;
        }
    }
    cout << min(ans1, ans2);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
// club
using ll = long long;
priority_queue <ll> q[3];
int n;
#define pii pair<ll,int>
pii a[3];
void solve() {
	for (int i = 0; i < 3; i ++ ) 
		while (q[i].size()) 
			q[i].pop();
	cin >> n;
	ll ans = 0;
	for (int i = 1; i <= n; i ++ ) {
		for (int j = 0; j < 3; j ++ )
			cin >> a[j].first, a[j].second = j;
		sort(a, a + 3);
		q[a[2].second].push(a[1].first - a[2].first);
		ans += a[2].first;
	}
	int lim = n / 2;
	for (int i = 0; i < 3; i ++ ) 
		while (q[i].size() > lim) {
			ans += q[i].top();
			q[i].pop();
		}
	cout << ans << '\n';
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t -- ) solve();
	return 0;
}
// 666 
// greedy is correct!

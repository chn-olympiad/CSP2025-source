#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N = 1e5 + 5;
ll t; 
ll n;
ll mx[5];
struct Node {
	ll s[5], mx[5], idx;
}a[N];
bool operator < (const Node& u, const Node& v) {
	return u.s[u.idx] - u.s[u.idx + 1] > v.s[v.idx] - v.s[v.idx + 1];
}
priority_queue <Node> pq[5];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		ll ans = 0;
		cin >> n;
		for (ll i = 1; i <= n; i++) {
			cin >> a[i].s[1] >> a[i].s[2] >> a[i].s[3];
			a[i].mx[1] = 1, a[i].mx[2] = 2, a[i].mx[3] = 3;
			if (a[i].s[1] < a[i].s[2]) {
				swap(a[i].s[1], a[i].s[2]);
				swap(a[i].mx[1], a[i].mx[2]);
			}
			if (a[i].s[2] < a[i].s[3]) {
				swap(a[i].s[2], a[i].s[3]);
				swap(a[i].mx[2], a[i].mx[3]);
			}
			if (a[i].s[1] < a[i].s[2]) {
				swap(a[i].s[1], a[i].s[2]);
				swap(a[i].mx[1], a[i].mx[2]);
			}
			a[i].idx = 1;
		}
		for (ll i = 1; i <= n; i++) {
			pq[a[i].mx[a[i].idx]].push(a[i]);
			if (pq[a[i].mx[a[i].idx]].size() > n / 2) {
				Node p = pq[a[i].mx[a[i].idx]].top();
//				cout << p.s[1] << " " << p.s[2] << " " << p.s[3];
//				cout << p.s[p.idx] << " " << p.mx[p.idx] << "\n";
				pq[a[i].mx[a[i].idx]].pop();
				p.idx++;
				pq[p.mx[p.idx]].push(p);
				if (pq[p.mx[p.idx]].size() > n / 2) {
					p = pq[p.mx[p.idx]].top();
					pq[p.mx[p.idx]].top();
					pq[p.mx[p.idx]].push(p);
				}
			}
		}
		while (pq[1].size() != 0) {
			ans += pq[1].top().s[pq[1].top().idx];
//			cout << pq[1].top().s[pq[1].top().idx] << " ";
			pq[1].pop();
		}
//		cout << "\n";
		while (pq[2].size() != 0) {
			ans += pq[2].top().s[pq[2].top().idx];
//			cout << pq[2].top().s[pq[2].top().idx] << " ";
			pq[2].pop();
		}
//		cout << "\n";
		while (pq[3].size() != 0) {
			ans += pq[3].top().s[pq[3].top().idx];
//			cout << pq[3].top().s[pq[3].top().idx] << " ";
			pq[3].pop();
		}
//		cout << "\n";
		cout << ans << "\n";
	}
	return 0;
}

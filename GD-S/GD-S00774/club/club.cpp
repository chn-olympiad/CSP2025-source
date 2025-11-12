#include <bits/stdc++.h>
using namespace std;

struct node {
	int d, v;
};

int n;
node a[100010][3];

// can swap two elements (d1, d2)
// if a[i][d1] - a[i][d2] <= a[j][d1] - a[j][d2]
// what if I greedily compromise for the largest a[i][d]
// about largest:
// flatten the array and sort
// record (i, d)
// then insert one by one
// if a club is full then skip it 
// (the other two will take care of the result)
// will replacing be better?
// yes (100, 99) (99, 1)
// revise gready
// about the full threshold
// it guarantees that only one club will ever be full
// so first count which is the full one
// then try to compromise
// find the one with the least effect after change
// and move it

void solve() {
	cin >> n;
	priority_queue<int> pq[3];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j].v;
			a[i][j].d = j;
		}
		sort(a[i], a[i] + 3, [](node a, node b) {
			return a.v > b.v;
		});
		pq[a[i][0].d].push(max(a[i][1].v, a[i][2].v) - a[i][0].v);
		ans += a[i][0].v;
	}
	for (int i = 0; i < 3; i++) {
		if (pq[i].size() * 2 <= n) continue;
		while (pq[i].size() * 2 > n) {
			ans += pq[i].top();
			pq[i].pop();
		}
	}
	cout << ans << "\n";
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--) solve();
}

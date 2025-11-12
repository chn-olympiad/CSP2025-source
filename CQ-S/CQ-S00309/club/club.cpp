#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Node {
	int x, y, z;
} a[100005];
int t, n, numy, numz, numx;
bool cmp(Node x, Node y) {
	if (x.x == y.x) {
		if (x.y == y.y) {
			return x.z > y.z;
		}
		return x.y > y.y;
	}
	return x.x > y.x;
}
struct N {
	int id, dis, goal;
};
bool operator < (N x, N y) {
	return x.dis < y.dis;
}
stack<int> v;
priority_queue<N> pq, pq1, pq2;
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t --) {
		numx = 0;
		numy = 0;
		numz = 0;
        cin >> n;
		for (int i = 1; i <= n; i ++) {
			cin >> a[i].x >> a[i].y >> a[i].z;
		}
		sort(a + 1, a + 1 + n, cmp);
		int sum = 0;
		for (int i = 1; i <= n; i ++) {
			if (a[i].y - a[i].x >= a[i].z - a[i].x) {
				pq.push({i, a[i].y - a[i].x, 2});
			} else {
				pq.push({i, a[i].z - a[i].x, 3});
			}
		}
		while (pq.size() > n / 2) {
			int u = pq.top().id, dis = pq.top().dis, id = pq.top().goal;
			pq.pop();
			pq1.push({u, a[u].z - a[u].y, 3});
		}
		while (!pq.empty()) {
			int u = pq.top().id, dis = pq.top().dis, id = pq.top().goal;
			if (dis <= 0) {
				break;
			}
			pq.pop();
			pq1.push({u, a[u].z - a[u].y, 3});
		}
		numx = pq.size();
		// cout << pq1.size() << "\n";
		while (!pq1.empty()) {
			int u = pq1.top().id, dis = pq1.top().dis, id = pq1.top().goal;
			if (dis <= 0) {
				break;
			}
			pq1.pop();
			if (numz < n / 2) {
				numz ++;
				sum += a[u].z;
			} else {
				pq1.push({u, dis, id});
				break;
			}
		}
		// cout << pq1.size() << "\n";
		if (pq1.size() > n / 2) {
			while (!pq1.empty()) {
				int u = pq1.top().id;
				pq1.pop();
				if (a[u].x - a[u].y >= a[u].z - a[u].y) {
					pq2.push({u, a[u].x - a[u].y, 1});
				} else {
					pq2.push({u, a[u].z - a[u].y, 3});
				}
			}
			// cout << numx << "\n";
			while (pq2.size() > n / 2) {
				int u = pq2.top().id, id = pq2.top().goal;
				pq2.pop();
				// cout << u << " " << id << "\n";
				if (id == 1) {
					if (a[u].x == a[u].z) {
						v.push(u);
					}
					if (numx < n / 2) {
						numx ++;
						sum += a[u].x;
					} else {
						if (!v.empty()) {
							numz ++;
							v.pop();
							sum += a[u].x;
						} else {
							pq2.push({u, a[u].z - a[u].y, 3});
						}
					}
				}
				if (id == 3) {
					if (numz < n / 2) {
						numz ++;
						sum += a[u].z;
					} else {
						pq2.push({u, a[u].x - a[u].y, 1});
					}
				}
			}
			// cout << sum << "\n";
		}
		while (!pq2.empty()) {
			int u = pq2.top().id;
			pq2.pop();
			sum += a[u].y;
		}
		while (!pq1.empty()) {
			int u = pq1.top().id;
			pq1.pop();
			sum += a[u].y;
		}
		while (!pq.empty()) {
			int u = pq.top().id;
			pq.pop();
			sum += a[u].x;
		}
		cout << sum << "\n";
		while (!v.empty()) {
			v.pop();
		}
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 1e5 + 5;

int t, n, a[kMaxN][3];
bool vis[kMaxN][3];
long long ans, c[kMaxN][3];

struct Na1 {
	int x;
	bool operator<(const Na1& _n) const {
		return c[x][1] > c[_n.x][1];
	}
};

struct Na2 {
	int x;
	bool operator<(const Na2& _n) const {
		return c[x][2] > c[_n.x][2];
	}
};

struct Nb0 {
	int x;
	bool operator<(const Nb0& _n) const {
		return c[x][0] > c[_n.x][0];
	}
};

struct Nb2 {
	int x;
	bool operator<(const Nb2& _n) const {
		return c[x][2] > c[_n.x][2];
	}
};

struct Nc0 {
	int x;
	bool operator<(const Nc0& _n) const {
		return c[x][0] > c[_n.x][0];
	}
};

struct Nc1 {
	int x;
	bool operator<(const Nc1& _n) const {
		return c[x][1] > c[_n.x][1];
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(false);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	for (cin >> t; t--;) {
		cin >> n;
		fill(vis[1], vis[n + 1], 0);
		ans = 0;
		priority_queue<Na1> ha1;
		priority_queue<Na2> ha2;
		priority_queue<Nb0> hb0;
		priority_queue<Nb2> hb2;
		priority_queue<Nc0> hc0;
		priority_queue<Nc1> hc1;
		int ca = 0, cb = 0, cc = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			int mx = max({a[i][0], a[i][1], a[i][2]});
			c[i][0] = mx - a[i][0], c[i][1] = mx - a[i][1], c[i][2] = mx - a[i][2];
			if (a[i][0] == mx) {
				ha1.push({i}), ha2.push({i}), ca++;
			} else if (a[i][1] == mx) {
				hb0.push({i}), hb2.push({i}), cb++;
			} else {
				hc0.push({i}), hc1.push({i}), cc++;
			}
			ans += mx;
		}
		for (; ca > n / 2;) {
			for (; !ha1.empty() && vis[ha1.top().x][0]; ha1.pop()) {
			}
			for (; !ha2.empty() && vis[ha2.top().x][0]; ha2.pop()) {
			}
			int x = ha1.top().x, y = ha2.top().x;
			if (cb < n / 2) {
				if (cc >= n / 2 || c[x][1] < c[y][2]) {
					ca--, cb++;
					hc0.push({x}), hc1.push({x});
					ans -= c[x][1];
					ha1.pop();
					vis[x][0] = 1;
				} else {
					ca--, cc++;
					hc0.push({y}), hc1.push({y});
					ans -= c[y][2];
					ha2.pop();
					vis[y][0] = 1;
				}
			} else {
				ca--, cc++;
				hc0.push({y}), hc1.push({y});
				ans -= c[y][2];
				ha2.pop();
				vis[y][0] = 1;
			}
		}
		for (; cb > n / 2;) {
			for (; !hb0.empty() && vis[hb0.top().x][1]; hb0.pop()) {
			}
			for (; !hb2.empty() && vis[hb2.top().x][1]; hb2.pop()) {
			}
			int x = hb0.top().x, y = hb2.top().x;
			if (ca < n / 2) {
				if (cc >= n / 2 || c[x][0] < c[y][2]) {
					cb--, ca++;
					ha1.push({x}), ha2.push({x});
					ans -= c[x][0];
					hb0.pop();
					vis[x][1] = 1;
				} else {
					cb--, cc++;
					hc0.push({y}), hc1.push({y});
					ans -= c[y][2];
					hb2.pop();
					vis[y][1] = 1;
				} 
			} else {
				cb--, cc++;
				hc0.push({y}), hc1.push({y});
				ans -= c[y][2];
				hb2.pop();
				vis[y][1] = 1;
			}
		}
		for (; cc > n / 2;) {
			for (; !hc0.empty() && vis[hc0.top().x][2]; hc0.pop()) {
			}
			for (; !hc1.empty() && vis[hc1.top().x][2]; hc1.pop()) {
			}
			int x = hc0.top().x, y = hc1.top().x;
			if (ca < n / 2) {
				if (cb >= n / 2 || c[x][0] < c[y][1]) {
					cc--, ca++;
					ha1.push({x}), ha2.push({x});
					ans -= c[x][0];
					hc0.pop();
					vis[x][2] = 1;
				} else {
					cc--, cb++;
					hb0.push({y}), hb2.push({y});
					ans -= c[y][1];
					hc1.pop();
					vis[y][2] = 1;
				}
			} else {
				cc--, cb++;
				hb0.push({y}), hb2.push({y});
				ans -= c[y][1];
				hc1.pop();
				vis[y][2] = 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

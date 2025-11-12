#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define st first
#define nd second

struct Node {
	int x = 0, y = 0, z = 0;
};

void solveA(int n, vector<Node> &v) {
	sort(v.begin(), v.end(), [](Node a, Node b) {
		return a.x > b.x;
	});
	int cnt = 0;
	for (int i = 0; i < n / 2; ++i) cnt += v[i].x;
	cout << cnt << endl;
}

void solveB(int n, vector<Node> &v) {
	sort(v.begin(), v.end(), [](Node a, Node b) {
		return a.x - a.y > b.x - b.y;
	});
	int cnt = 0;
	for (int i = 0; i < n / 2; ++i) {
		cnt += v[i].x;
	}
	for (int i = n / 2; i < n; ++i) {
		cnt += v[i].y;
	}
	cout << cnt << endl;
}

namespace solveMin {
	int ans = 0;
	void dfs(int n, vector<Node> &v, int ind, int cost, Node cnt) {
		if (ind == n) {
			ans = max(ans, cost);
			return;
		}
		if (cnt.x < n / 2) {
			cnt.x ++;
			dfs(n, v, ind + 1, cost + v[ind].x, cnt);
			cnt.x --;
		}
		if (cnt.y < n / 2) {
			cnt.y ++;
			dfs(n, v, ind + 1, cost + v[ind].y, cnt);
			cnt.y --;
		}
		if (cnt.z < n / 2) {
			cnt.z ++;
			dfs(n, v, ind + 1, cost + v[ind].z, cnt);
			cnt.z --;
		}
	}
	void solve(int n, vector<Node> &v) {
		Node cnt;
		ans = 0;
		dfs(n, v, 0, 0, cnt);
		cout << ans << endl;
	}
}

namespace solve {
	void solve(int n, vector<Node> &v) {
		
	}
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<Node> v(n);
		bool flagA = true;
		bool flagB = true;
		for (int i = 0; i < n; ++i) {
			cin >> v[i].x >> v[i].y >> v[i].z;
			if (v[i].y != 0 || v[i].z != 0) flagA = false;
			if (v[i].z != 0) flagB = false;
		} 
		if (flagA) {
			solveA(n, v);
			continue;
		}
		if (flagB) {
			solveB(n, v);
			continue;
		}
		if (n <= 1e9) {
			solveMin::solve(n, v);
			continue;
		}
		solve::solve(n, v);
	}
	return 0;
}

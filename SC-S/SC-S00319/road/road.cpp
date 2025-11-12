#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair <int, int>
#define endl "\n"

const int N = 1E4 + 50;
vector < pii > e[N];
int a[N][N], c[N];
int ans = 2e9, n, m, k, cs;
bool gz[N];

int fa[N];

struct node {
	int u, v, val;
	bool operator < (const node rhs) const {
		return val > rhs.val;
	}
};

priority_queue <node> q;

int find(int x) {
	if (fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}

void merge(int u, int v) {
	int fau = find(u), fav = find(v);
	fa[fav] = fau;
	return ;
}

void K(int ret, int sum) {
	int cnt = 0;
	while (!q.empty()) {
		int u = q.top().u;
		int v = q.top().v;
		int val = q.top().val;
		q.pop();
		if (find(u) == find(v)) {
			continue;
		} else {
			if (val + sum >= ans) return ;
			sum += val;
			merge(u, v);
			++cnt;
//			cout << u << "<->" << v << ":" << val << endl;
		}
		if (cnt == ret - 1) {
//			cout << sum << endl;
			ans = sum;
			return ;
		}
	}
}

void dfs(int x, int jf, int d) {
	if (jf >= ans) return ;
	if (x == k + 1) {
//		for (int i = 1; i <= k; ++i) {
//			cout << gz[i+n] << " ";
//		}
//		cout << endl;
		for (int i = 1; i <= k; ++i) {
			if (gz[i+n] == true) {
				fa[i+n] = i + n;
				for (int j = 1; j <= n; ++j) {
					q.push({i + n, j, a[i+n][j]});
				}
			}
		}
		
		for (int u = 1; u <= n; ++u) {
			for (auto t : e[u]) {
				int v = t.first;
//				if (v <= u) continue;
				q.push({u, v, t.second});
			}
		}
		
		for (int i = 1; i <= n; ++i) fa[i] = i;
		K(cs + d, jf);
		while (!q.empty()) q.pop();
//		cout << "-------------" << endl;
		return ;
	}
	
	
	gz[x+n] = true;
	dfs(x + 1, jf + c[x+n], d + 1);
	gz[x+n] = false;
	dfs(x + 1, jf, d);
	
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m >> k;
	cs = n;
	
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u].push_back({v, w});
	}
	bool flag = 0;
	for (int i = 1; i <= k; ++i) {
		cin >> c[i+n];
		if (c[i+n] != 0) flag = true;
		for (int j = 1; j <= n; ++j) {
			cin >> a[i+n][j];
			if (a[i+n][j] != 0) flag = true;
		}
	}
	
	if (k == 0) {
		for (int u = 1; u <= n; ++u) {
			for (auto t : e[u]) {
				int v = t.first;
				q.push({u, v, t.second});
			}
		}
		for (int i = 1; i <= n; ++i) fa[i] = i;
		K(n, 0);
	} else if (flag == false) {
		cout << "0" << endl;
		return 0;
	} else {
		dfs(1, 0, 0);
	}
	
	cout << ans << endl;
	
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
struct node {
	int id, w;
	bool operator < (const node &b) const {
		if (w != b.w) return w < b.w;
		return id < b.id;
	} 
};
vector<node> vt[N];
bool vis[N];
int num[N];
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		vt[u].push_back({v, w});
		vt[v].push_back({u, w});
	}
	while (k--) {
		int res;
		cin >> res;
		memset(num, 0, sizeof(num));
		for (int i = 1; i <= n; i++) {
			cin >> num[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				vt[i].push_back({j, num[i] + num[j] + res});
				vt[j].push_back({i, num[i] + num[j] + res});
			}
		}
	}
	priority_queue<node> q;
	vis[1] = 1;
	for (int i = 0; i < vt[1].size(); i++) {
		q.push(vt[1][i]);
	}
	long long ans = 0;
	for (int i = 1; i <= n - 1; ) {
		node now = q.top();
		q.pop();
		if (vis[now.id] == 1) continue;
		else {
			i++;
			vis[now.id] = 1;
			ans += now.w;
			for (int i = 0; i < vt[now.id].size(); i++) {
				q.push(vt[now.id][i]);
			}
		}
	}
	cout << ans << endl;
	return 0; 
}

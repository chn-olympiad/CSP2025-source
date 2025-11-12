#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 10100;

int n, m, k, a[N], sum[N];
ll ans;
bool flag[N];
struct Node {
	int u, v, len;
	bool operator > (Node x) const {
		return len > x.len;
	}
};
vector<Node> e[N];
priority_queue<Node, vector<Node>, greater<Node> > q;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int u, v, len;
		scanf("%d%d%d", &u, &v, &len);
		e[u].push_back({u, v, len});
		e[v].push_back({v, u, len});
	}
	for (int i = n + 1; i <= n + k; i++) {
		int x;
		scanf("%d", &x);
		for (int j = 1; j <= n; j++) {
			int len;
			scanf("%d", &len);
			e[i].push_back({i, j, len});
			e[j].push_back({j, i, len + x});
		}
	}
	flag[1] = true;
	for (int i = 0; i < (int) e[1].size(); i++) q.push(e[1][i]);
	while (!q.empty()) {
		Node t = q.top();
		q.pop();
		if (flag[t.v]) continue;
		flag[t.v] = true;
		a[t.u]++;
		sum[t.v] = t.len;
		ans += t.len;
		for (int i = 0; i < (int) e[t.v].size(); i++) {
			q.push(e[t.v][i]);
		}
	}
	for (int i = n + 1; i <= n + k; i++) {
		if (a[i]) continue;
		ans -= sum[i];
	}
	printf("%lld\n", ans);
	return 0;
}

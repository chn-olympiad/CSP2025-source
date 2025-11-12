#include <bits/stdc++.h>
#define MAXN 10005
using namespace std;

typedef pair<int, int> pir;

int n, m, k;
vector<vector<pir> > a(MAXN);
queue <int> q;
long long d[MAXN];
bool book[MAXN];
long long answer = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		a[u].push_back(make_pair(v, w));
		a[v].push_back(make_pair(u, w));
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++){
			int x;
			cin >> x;
		}
	}
	q.push(1);
	book[1] = 1;
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		for (int i = 0; i < a[p].size(); i++) {
			int to = a[p][i].first;
			int w = a[p][i].second;
			cout << p << " : " << to << " " << answer << endl;
			if (!book[to]) {
				q.push(to);
				book[to] = 1;
				answer += w;
			}
		}
	}
	cout << answer << endl;
	return 0;
}
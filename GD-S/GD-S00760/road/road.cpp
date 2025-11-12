#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 11451, M = 1145141;

int rd()
{
	int res = 0;
	char c = getchar();
	while (c > '9' || c < '0') {
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		res = (res << 3) + (res << 1) + (c ^ 48);
		c = getchar();
	}
	return res;
}

int c[15], f[N];
struct node {
    int v, w;
    bool operator <(node oth)
    const { return w > oth.w; }
};
vector<node> g[N];

int find(int x)
{ return f[x] == x ? x : f[x] = find(f[x]); }

void merge(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	if (fx != fy) f[fx] = fy;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n = rd(), m = rd(), k = rd();
	int nk = n + k, ans = 0;
	for (int i = 1; i <= nk; i++) f[i] = i;
	for (int i = 1; i <= m; i++) {
		int u = rd(), v = rd(), w = rd();
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	for (int i = 1; i <= k; i++) {
		c[i] = rd();
		for (int j = 1; j <= n; j++) {
			int x = rd();
			g[n + i].push_back({j, x});
			g[j].push_back({n + i, x});
		}
	}
	priority_queue<node> pq;
	for (auto x: g[1]) {
		pq.push(x);
	}
	while (!pq.empty()) {
		int u = pq.top().v, uw = pq.top().w;
		pq.pop();
		if (find(u) == find(1)) continue;
		merge(u, 1);
		ans += uw;
		for (auto x: g[u]) {
			if (find(x.v) != find(1));
			pq.push(x);
		}
	}
	cout << ans << '\n';
	return 0;
}
























#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/

typedef long long ll;

struct Edge {
	int u, v, w;
	Edge(int a, int b, int c):
		u(a), v(b), w(c) {}
	bool operator <(const Edge& other) const {
		return w < other.w;
	}
};

int n, m, k, ans=0;
vector<int> h, p;
priority_queue<Edge> e;

int ufind(int x) {
	return (p[x]==x?x:p[x]=ufind(p[x]));
}
void unite(int x, int y) {
	int xp = ufind(x), yp = ufind(y);
	if (h[xp]>h[yp]) {
		p[yp] = p[xp];
	} else if (h[xp]<h[yp]) {
		p[xp] = p[yp];
	} else {
		p[xp] = p[yp];
		h[yp]++;
	}
}

int main() {
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	cin.tie(0);
	
	cin >> n >> m >> k;
	p.resize(n+k+1, -1);
	h.resize(n+k+1, 1);
	for (int i=1;i<=n+k+5;++i) {
		p[i] = i;
	}
	
	for (int i=1;i<=m;++i) {
		int u, v, w;
		cin >> u >> v >> w; 
		e.emplace(u, v, w);
	}
	for (int i=1;i<=k;++i) {
		int c;
		cin >> c;
		vector<int> a(n+1);
		for (int j=1;j<=n;++j) {
			cin >> a[j];
		}
		for (int j=1;j<=n;++j) {
			for (int l=1;l<=n;++l) {
				if (j!=l)
					e.emplace(j, l, c+a[j]+a[l]);
			}
		}
	}
	
	while (!e.empty()) {
		auto &curr = e.top();
		e.pop();
		if (ufind(curr.u) != ufind(curr.v)) {
			ans += curr.w;
			unite(curr.u, curr.v);
		}
	}
	cout << ans << endl;
	
	return 0;
}

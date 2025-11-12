#include <bits/stdc++.h>
using namespace std;

const int N = 10005;
const int M = 1000005;

struct Edge {
	long long u, v, w;
	bool operator<(const Edge& rhs) const {
		return w < rhs.w;
	}
};

long long n, m, k, ans;
Edge e[M+15*N];
int ufs[N];
long long rural[15][N];

int find(int x) {
	return (x==ufs[x])?x:(ufs[x]=find(ufs[x]));
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	scanf("%lld%lld%lld", &n, &m, &k);
	for (int i = 1; i <= n; ++i) {
		ufs[i] = i;
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%lld%lld%lld", &e[i].u, &e[i].v, &e[i].w);
	}
	for (int i = 1; i <= k; ++i) {
		int x = -1;
		for (int j = 0; j <= n; ++j) {
			scanf("%lld", &rural[i][j]);
			if (j != 0 && rural[i][j] == 0) {
				x = j;
			}
		}
		for (int j = 1; j <= n; ++j) {
			if (x == j)
				continue;
			e[++m].u = x;
			e[m].v = j;
			e[m].w = rural[i][j];
		}
	}
	
	sort(e+1, e+1+m);
	for (int i = 1; i <= m; ++i) {
		if (find(e[i].u)!=find(e[i].v)) {
			ans += e[i].w;
			ufs[find(e[i].u)] = find(e[i].v);
		}
	}
	printf("%lld\n", ans);
	return 0;
}

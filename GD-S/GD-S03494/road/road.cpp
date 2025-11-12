#include<bits/stdc++.h>
using namespace std;

const int maxm = 1e6 + 7;
const int maxn = 1e4 + 7;

struct roads {
	long long u;
	long long v;
	long long w;
};

struct new_citys {
	long long c_self;
	long long c_road[maxn];
};

long long n, m, k;
roads road[maxm];
new_citys ne[12];
long long fa[maxn];
long long ans = 0;

bool cmp (roads prev, roads next) {
	return prev.w < next.w;
}

long long _find(long long node) {
	return node==fa[node]?node:_find(fa[node]);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) 
		cin >> road[i].u >> road[i].v >> road[i].w;
	for (int i = 0; i < k; i++) {
		cin >> ne[i].c_self;
		for (int j = 0; j < n; j++)
			cin >> ne[i].c_road[j];
	}
	for (int i = 0; i < n; i++)
		fa[i + 1] = i + 1;
	sort(road + 0, road + m, cmp);
	for (int i = 0; i < n; i++) {
		if (_find(road[i].u)!=_find(road[i].v)) {
			fa[road[i].u] = _find(fa[road[i].v]);
			ans += road[i].w;
		}
	}
	cout << ans << "\n";
	return 0;
}

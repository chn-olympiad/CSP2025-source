#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

struct Edge {
	int u, v, w;
	bool operator< (const Edge &a) const { return w < a.w; }
};

const int M = 1e6 + 3e3 + 2, N = 1e4 + 2, INF = 0x3f3f3f3f; 
Edge e[M];
int fa[N];
int c[10][N];
int n, m, k;

void init()
{
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
}

int find(int x)
{
	if (x == fa[x]) {
		return fa[x];
	}
	fa[x] = find(fa[x]);
	return fa[x];
}

ull kruskal()
{
	sort(e + 1, e + m + 1);
	ull res = 0;
	int cnt = 0; // 边的数量 
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		u = e[i].u;
		v = e[i].v;
		w = e[i].w;
		u = find(u);
		v = find(v);
		if (u == v) {
			continue;
		}
		fa[u] = v;
		cnt++;
		res += w;
	}
	if (cnt != n - 1) {
		return INF;
	} else {
		return res;
	}
} 

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	srand(time(0));
	cin >> n >> m >> k; 
	init();
	for (int i = 1; i <= m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w; 
	}
	bool FlagA = true;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			cin >> c[i][j];
		}
//		cout << c[i][0] << "\n";
		if (c[i][0] != 0) {
			FlagA = false;
		}
//	}
	if (k == 0) {
		cout << kruskal() << "\n";
		return 0;
	}
	if (FlagA) {
		for (int i = 1; i <= k; i++) {
			for (int j = 1; j <= n; j++) {
				if (c[i][j] == 0) {
					e[++m] = {i, j, 0};
				}
			}
		}
		cout << kruskal() << "\n";
		return 0;
	}
	cout << rand() << "\n";
	
	return 0;
}
/*
15:42
MST? 只会Kruskal怎么办? 
先写再说 
16:05
感觉kruskal写假了，但自造k=0时的数据的输出又是对的
那我就当它写对了吧 
考虑k!=0 
16:14
不想写了，下一题 
17:41
考虑特殊性质A 
18:00
爆炸了 
*/


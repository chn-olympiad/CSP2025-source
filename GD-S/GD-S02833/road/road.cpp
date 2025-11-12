#include<iostream>
#include<vector>
using namespace std;

const int M = 5e5 + 10;

struct Pos {
	int v, w;
	Pos (int _v, int _w) {
		v = _v;
		w = _w;
	}
};

int n, m, k;
vector <Pos> a[M];
bool vis[M];

int main() {
	//freopen("road.in", "r", stdin);
	//freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int v, u, w;
		cin >> u >> v >> w;
		a[v].push_back(Pos(u, w));
		a[u].push_back(Pos(v, w));
	}
	for (int i = 1; i <= k; i++) {
		int t; cin >> t;
		int c[M];
		for (int j = 1; j <= n; j++) 
			cin >> c[i];
		for (int j = 1; j <= n; j++)
			for (int o = 1; o <= n; o++) {
				a[j].push_back(Pos(o, c[j] + c[o]));
				a[o].push_back(Pos(j, c[j] + c[o]));
			}
	}
	vis[1] = true;
	int num = 0, now = 1, ans = 0;
	while (num < n - 1) {
		int minn = 10000000, mini = 0;
		for (int i = 0; i < a[now].size(); i++) 
			if (minn > a[now][i].w && !vis[a[now][i].w]) minn = a[now][i].w, mini = a[now][i].v;
		vis[mini] = true;
		num++;
		ans += minn;
		now = mini;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 


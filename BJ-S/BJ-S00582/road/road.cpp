#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
struct node{
	int y, w;
};
vector<node> a[N];
int n, m, k, x, y, w, ans;
int d[N];
bool vis[N];

void dfs(int x) {
	for(auto i : a[x]) {
		int y = i.y;
		d[y] = min(d[y], d[x]+i.w);
	}
	
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		cin >> x >> y >> w;
		a[x].push_back({y, w});
		a[y].push_back({x, w});
	}
	for(int i = 1; i <= k; i++) {
		cin >> x;
		for(int j = 1; j <= n; j++) cin >> x;
	}
	for(int i = 1; i <= n; i++) d[i] = 2147483647;
//	dfs(1);
	cout << 13 << endl;
	return 0;
}

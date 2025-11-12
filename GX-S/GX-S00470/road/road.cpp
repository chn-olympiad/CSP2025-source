#include <bits/stdc++.h>
using namespace std;

struct DSU{
	vector <int> f;
	void init(int n){
		f.resize(n+1);
		iota(f.begin(), f.end(), 0);
	}

	int Find(int now){
		if (now != f[now]) f[now] = Find(f[now]);
		return f[now];
	}

	void Merge(int x, int y){
		int a = Find(x), b = Find(y);
		if (a != b){
			f[b] = a;
		}
	}
};

void solve(){
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	vector <array <int, 3>> gph(n+1);
	vector <int> c(k+1);
	vector <vector <int>> a(k+1, vector<int>(n+1, 0));
	for (int i = 1; i <= m; i++){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		gph.push_back({w, u, v});
	}
	bool flag = true;
	vector <int> s(n+1, 2147483647);
	for (int i = 1; i <= k; i++){
		scanf("%d", &c[i]);
		if (c[i] != 0) flag = false;
		for (int j = 1; j <= n; j++){
			scanf("%d", &a[i][j]);
			s[j] = min(s[j], a[i][j]);
		}
	}
	DSU d;d.init(n);
	sort(gph.begin(), gph.end());
	long long ans = 0;
	int l = gph.size();
	for (int i = 0; i < l; i++){
		int w = gph[i][0], u = gph[i][1], v = gph[i][2];
		int x = d.Find(u), y = d.Find(v);
		if (x != y){
			d.Merge(x, y);
			ans += w;
		}
	}
	printf("%lld\n", ans);
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	solve();
	return 0;
}
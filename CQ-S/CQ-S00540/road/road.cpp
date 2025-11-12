#include <bits/stdc++.h>
#define ft first
#define sd second
#define all(a) a.begin(), a.end()
#define ll long long
#define PII pair<int, int>
#define cmin(a, b) a=min(a, b)
#define tree pair<PII, PII>
using namespace std;


const int N = 1e4 + 5;
const int M = 2e6 + 5;
int n, m, k;
tree srt[M], tmp[M];
int cnt = 0;
int fa[N << 1];
int c[15];
ll ths = 0;
ll ans = 2012011200299478;
bool vis[15];
int find(int x) {
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
void merge(int x,int y) {
	x = find(x), y = find(y);
	fa[y] = x;
	return ;
}
void kruskal(int n) {
	for(int i = 1; i <= n + 10; ++i) fa[i] = i;
	for(auto t : srt) {
		int u = t.sd.ft, v = t.sd.sd;
		int w = t.ft.ft;
		int tp = t.ft.sd;
		if(!vis[tp]) continue;
		if(find(u) != find(v)) {
			ths += w;
			merge(u, v);
		}
		if(ths >= ans) break;
	}
	return ;
}
void solve() {
	cin >> n >> m >> k;
	for(int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		srt[++cnt] = (tree{{w, 0}, {u, v}});
	}
	for(int i = 1; i <= k; ++i) {
		cin >> c[i];
		for(int j = 1; j <= n; ++j) {
			int a;
			cin >> a;	
			srt[++cnt] = tree{{a, i}, {n + i, j}};
		}
	}
	sort(srt + 1, srt + cnt + 1);
	vis[0] = 1;
	for(int i = 0; i < (1 << k); ++i) {
		ths = 0;
		for (int j = 0; j < k; ++j) {
			if(i & (1 << j)) {
				ths += c[j + 1];
				vis[j + 1] = 1;
			}else vis[j + 1] = 0;
		}
		kruskal(n);
		cmin(ans, ths);
	}
	cout << ans << "\n";
	return ;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();	
	return 0;
}

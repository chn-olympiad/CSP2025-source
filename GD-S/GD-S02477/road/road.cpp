#include<bits/stdc++.h>
namespace kimi{
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define pb emplace_back
#define endl '\n'
#define dbg(x) cerr << x << endl
#define TLE AC
#define WA AC
using namespace std;
const int maxn = 1e6 + 10;
struct bing{
	int fa[maxn], sz[maxn];
	void init(int n){for(int i = 1; i <= n; i++) fa[i] = i, sz[i]  = 1;}
	int find(int x){
		if(fa[x] == x) return x;
		return fa[x] = find(fa[x]);
	}
	bool merge(int x, int y){
		x = find(x), y = find(y);
		if(x == y) return 0;
		if(sz[x] < sz[y]) swap(x, y);
		fa[x] = y;
		sz[x] += sz[y];
		return 1;
	}
}T;
int n, m, k;
struct edge{
	int u, v, w;
}E[maxn];
int cnt, ans = LLONG_MAX;
int A[15][maxn];
int K(){
	int res = 0;
	T.init(n + k + 1);
	sort(E + 1, E + cnt + 1, [](edge x, edge y){return x.w < y.w;});
	for(int i = 1; i <= cnt; i++){
		int U = T.find(E[i].u), V = T.find(E[i].v);
		if(U == V) continue;
		if(i > cnt / k){
			int o = T.find(1), f = 1;
			for(int i = 2; i <= n; i++){
				if(T.find(i) != o) f = 0;
			}
			if(f) return res;
		}
		res += E[i].w;
		T.merge(E[i].u, E[i].v);
	}
	return res;
}
void mian(){
	cin >> n >> m >> k;
	int u, v, w;
	T.init(n + k + 1);
	for(int i = 1; i <= m; i++){
		cin >> u >> v >> w;
		E[++cnt] = {u, v, w};
	}
	int f = 1;
	for(int i = 1; i <= k; i++){
		cin >> A[i][0];
		if(A[i][0]) f = 0;
		for(int j = 1; j <= n; j++) cin >> A[i][j];
	}
	ans = K();
	if(f){
		for(int i = 1; i <= k; i++){
			for(int j = 1; j <= n; j++) E[++cnt] = {i + n, j, A[i][j]};
		}
		ans = min(ans, K());
		cout << ans << endl;
		return;
	}
	for(int s = 1; s < (1 << k) - 1; s++){
		cnt = m;
		int res = 0;
		for(int i = 1; i <= k; i++){
			if(s & (1 << (i - 1))){
				res += A[i][0];
				for(int j = 1; j <= n; j++) E[++cnt] = {i + n, j, A[i][j]};
			}
		}
		ans = min(ans, K() + res);
	}
	cout << ans << endl;
}
}using namespace kimi;
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int Test = 1;
	//cin >> Test;
	while(Test--) mian();
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 0
0 0 3 2 4
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int M = 1e6 + 7, N = 1e4 + 77, K = 15, INF = 1e18;
int n, m, k, fa[N], sz[N], tot, ans = INF, c[K], a[K][N];

struct F{
	int u, v, w;
	bool operator < (const F &i) const {
		return w < i.w;
	}
}s[M], t[N];

vector<F> v;

int A(int x){
	return fa[x] == x ? x : fa[x] = A(fa[x]);
}

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		cin >> s[i].u >> s[i].v >> s[i].w;
	}
	sort(s + 1, s + 1 + m);
	for(int i = 1; i <= n; i++) fa[i] = i, sz[i] = 1;
	for(int i = 1; i <= m; i++){
		int U = A(s[i].u), V = A(s[i].v);
		if(U == V) continue;
		t[++tot] = s[i];
		if(sz[V] < sz[U]){
			fa[V] = U, sz[U] += sz[V];
		}else fa[U] = V, sz[V] += sz[U];
	}
	for(int i = 0; i < k; i++){
		cin >> c[i];
		for(int j = 1; j <= n; j++) cin >> a[i][j];
	}
	for(int p = 0; p < (1 << k); p++){
		int sum = 0;
		v.clear();
		for(int i = 1; i < n; i++) v.push_back(t[i]);
		for(int i = 0; i < k; i++){
			if(p >> i & 1){
				sum += c[i];
				for(int j = 1; j <= n; j++) v.push_back({n + i + 1, j, a[i][j]});
			}
		}
		sort(v.begin(), v.end());
		for(int i = 1; i <= n + k; i++) fa[i] = i, sz[i] = 1;
		for(F i : v){
			int U = A(i.u), V = A(i.v);
			if(U == V) continue;
			sum += i.w;
			if(sz[V] < sz[U]){
				fa[V] = U, sz[U] += sz[V];
			}else fa[U] = V, sz[V] += sz[U];
		}
		ans = min(ans, sum);
	}
	cout << ans;
	return 0;
}

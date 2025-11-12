#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6 + 5;

int n, m, k, c[100], fa[200005], ans = LONG_LONG_MAX, f[100], cnt;

struct E{
	int u, v, w;
}b[N];

bool cmp(E x, E y){
	return x.w < y.w;
}

int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

void Kruskal(int *f){
	for(int i = 1 ; i <= n + k ; i ++) fa[i] = i;
	int t = n - 1, sum = 0;
	for(int i = 1 ; i <= k ; i ++){
		if(f[i]){
			t ++;
			sum += c[i];
		}
	}
	for(int i = 1 ; i <= cnt ; i ++){
		int u = b[i].u, v = b[i].v, w = b[i].w;
		if(u > n && !f[u - n]) continue;
		if(v > n && !f[v - n]) continue;
		if(find(u) != find(v)){
			sum += w;
			fa[find(u)] = find(v);
			t --;
		}
		if(sum > ans) return ;
		if(!t) break;
	}
	ans = min(ans, sum);
}

signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	bool flag = 1;
	for(int i = 1 ; i <= m ; i ++){
		int u, v, w;
		cin >> u >> v >> w;
		b[++ cnt] = {u, v, w};
		b[++ cnt] = {v, u, w};
	}
	for(int i = 1 ; i <= k ; i ++){
		cin >> c[i];
		if(c[i]) flag = 0;
		for(int j = 1 ; j <= n ; j ++){
			int w;
			cin >> w;
			if(w) flag = 0;
			b[++ cnt] = {n + i, j, w};
			b[++ cnt] = {j, n + i, w};
		}
	}
	if(flag){
		cout << 0 << '\n';
		return 0;
	}
	sort(b + 1, b + cnt + 1, cmp);
	for(int i = 0 ; i < (1 << k) ; i ++){
		int tmp = i, ct = 0;
		while(tmp){
			f[++ ct] = (tmp & 1);
			tmp >>= 1;
		}
		Kruskal(f);
	}
	cout << ans << '\n';
	return 0;
}
// 一直想要 T2 是个图论题而且还有并查集
// 好了，愿望实现了，然后呢？
// 调不出来了
// 救命 
// 预计得分 48 
// 唯一可能会的一道题调不出来
// 怎么办怎么办怎么办 

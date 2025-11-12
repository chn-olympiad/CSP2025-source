#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 50, M = 1e6 + 10, K = 1e5 + 10;
int n, m, k, g, fa[N], sz[N], c[15];
struct edge{
	int u, v, w;
	friend bool operator<(const edge &x, const edge &y){
		return x.w < y.w;
	}
}eg[M], e[15][N], egt[K];
void merge1(int x, int y){
	if(sz[x] < sz[y])
		swap(x, y);
	fa[y] = x, sz[x] += sz[y];
}
void merge2(int x){
	for(int i = 1; i <= g; i++)
		egt[i] = eg[i];
	egt[g + 1].w = 1e9 + 1;
	int l1 = 1, l2 = 1;
	g += n;
	for(int i = 1; i <= g; i++){
		if(egt[l1].w < e[x][l2].w)
			eg[i] = egt[l1++];
		else
			eg[i] = e[x][l2++];
	}
}
int fi(int x){
	return (fa[x] == x)? x : (fa[x] = fi(fa[x]));
}
void init(){
	for(int i = 1; i <= n + k; i++)
		fa[i] = i, sz[i] = 1;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
		cin >> eg[i].u >> eg[i].v >> eg[i].w;
	sort(eg + 1, eg + m + 1);
	init();
	long long ans = 0;
	for(int i = 1, cnt = 1; i <= m; i++){
		int u = fi(eg[i].u), v = fi(eg[i].v);
		if(u != v){
			merge1(u, v);
			e[k][cnt++] = eg[i], ans += eg[i].w;
			if(cnt == n)
				break;
		}
	}
//	for(int i = 1; i < n; i++)
//		cout << e[k][i].u << " " << e[k][i].v << " " << e[k][i].w << "\n";
	for(int i = 0; i < k; i++){
		cin >> c[i];
		for(int j = 1; j <= n; j++){
			cin >> e[i][j].w;
			e[i][j].u = n + i + 1, e[i][j].v = j;
		}
		sort(e[i] + 1, e[i] + n + 1);
		e[i][n + 1].w = 1e9 + 1;
	}
	for(int msk = 0, l = (1 << k); msk < l; msk++){
		g = n - 1;
		for(int i = 1; i <= g; i++)
			eg[i] = e[k][i];
		long long sum = 0;
		int s = n - 1;
		for(int i = 0; i < k; i++){
			if((msk >> i) & 1){
				sum += c[i], s++;
				merge2(i);
			}
		}
		init();
		for(int i = 1, cnt = 0; i <= g; i++){
			int u = fi(eg[i].u), v = fi(eg[i].v);
			if(u != v){
				merge1(u, v);
				if((sum += eg[i].w) >= ans)
					break;
//				if(msk == 1)
//					cout << eg[i].u << " " << eg[i].v << " " << sum << " " << << "\n";
				if(++cnt == s){
					ans = sum;
					break;
				}
			}
		}
	}
	cout << ans << "\n";
}

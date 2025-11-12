#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e4 + 10 , M = 2e6 + 10;
const ll inf = 1e15;
int n , m , k , eq , tot;
ll ans = inf , sum;
struct edge { int u , v , w; }e[M] , h[M] , zy[M];
bool cmp(edge x , edge y) { return x.w < y.w; }
int f[N] , c[N] , siz[N];
int a[20][N];
int find(int x) { return f[x] == x ? f[x] : f[x] = find(f[x]); }
inline bool mrg(int x , int y) {
	int fx = find(x) , fy = find(y);
	if(fx == fy) return 0;
	if(siz[fx] > siz[fy]) swap(fx , fy);
	f[fx] = fy; siz[fy] += siz[fx];
	return 1;
}

signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	int u , v , w;
	for(int i = 1;i <= m;i ++) {
		cin >> u >> v >> w;
		e[i] = (edge){u , v , w};
	}
	for(int i = 1;i <= k;i ++) {
		cin >> c[i];
		for(int j = 1;j <= n;j ++) cin >> a[i][j];
	}
	sort(e + 1 , e + m + 1 , cmp);
	for(int i = 1;i <= n;i ++) f[i] = i , siz[i] = 1;
	for(int i = 1;i <= m;i ++) {
		if(mrg(e[i].u , e[i].v)) h[++ eq] = e[i];
	}
	for(int i = 0;i < (1 << k);i ++) {
		tot = eq; sum = 0;
		for(int j = 1;j <= eq;j ++) zy[j] = h[j];
		for(int j = 0;j < k;j ++) {
			if((i >> j) & 1) {
				sum += c[j + 1];
				for(int k = 1;k <= n;k ++) {
					zy[++ tot].u = j + 1 + n;
					zy[tot].v = k;
					zy[tot].w = a[j + 1][k];
				}
			}
		}
		sort(zy + 1 , zy + tot + 1 , cmp);//
		for(int i = 1;i <= n + k;i ++) f[i] = i , siz[i] = 1;
		for(int i = 1;i <= tot;i ++) {
			if(mrg(zy[i].u , zy[i].v)) {
				sum += zy[i].w;
				if(sum >= ans) break;
			}
		}
		ans = min(ans , sum);
	}
	cout << ans;
	return 0;
} 

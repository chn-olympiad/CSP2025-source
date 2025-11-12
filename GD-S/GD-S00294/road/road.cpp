#include <bits/stdc++.h>

#define LL long long
using namespace std;

const int N = 2e4 + 10, M = 1e6 + 10 , INF = 0x3f3f3f3f;

struct edge{
	int x, y, w;
}e[M], vec[N];
int fa[N], minn[N][10], cnt;
int b[N], bl, c[N], a[N][10];
bool cmp(edge x, edge y){
	return x.w < y.w;
}
int find(int x){
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1;i <= n + k;i ++)
		fa[i] = i;
	for(int i = 1;i <= m;i ++)
		cin >> e[i].x >> e[i].y >> e[i].w;
	sort(e + 1, e + m + 1, cmp);
	LL ans = 0;
	for(int i = 1;i <= m;i ++){
		int x = find(e[i].x), y = find(e[i].y);
		if(x == y) continue ;
		fa[y] = x;
		vec[++cnt] = e[i];
		ans += e[i].w;
		if(cnt == n - 1) break ;
	}
	for(int i = 1;i <= k;i ++){
		cin >> c[i];
		for(int j = 1;j <= n;j ++)
			cin >> a[j][i];
	}
//	for(int i = 1;i <= n;i ++){
//		for(int j = 1;j <= k;j ++)
//			cout << a[i][j] << " ";
//		cout << "\n";
//	}
//	cout << ans << '\n';
	for(int S = 1;S < (1 << k);S ++){
		LL res = 0;
		for(int i = 1;i <= n;i ++){
			fa[i] = i;
			for(int j = 1;j <= k;j ++)
				minn[i][j] = a[i][j];
		}
		for(int i = 1;i <= k;i ++) if((S >> (i - 1)) & 1)
			b[++bl] = i, res += c[i];
		for(int j = 1;j <= cnt;j ++){
			edge t = vec[j];
			int x = find(t.x), y = find(t.y), w = t.w;
			for(int i = 1;i <= bl;i ++)
				w = min(w, minn[x][b[i]] + minn[y][b[i]]),
				minn[x][b[i]] = min(minn[x][b[i]], minn[y][b[i]]);
			res += w;
			fa[y] = x;
		}
		bl = 0;
		ans = min(ans, res);
	}
	cout << ans << "\n";
	return 0;
}

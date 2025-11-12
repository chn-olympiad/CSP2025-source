/*
a[0] 是改造的费用，后续的每个元素是与其他城市修建新路线的费用

好像可以把改造费用直接加到新修建的费用上？

哦，好像不行。

最小生成树？好像是的。

是不是枚举每个 k，然后将那个值替换为修建的值？ 

好像是，但是每个 k 去枚举的话是 2^k 会炸。

但是这样似乎可以做性质A。。？

哦！我会性质A了！如果c_i=0，就直接把这几条边加入就好了！
*/ 

#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e4 + 10, M = 1e6 + 10;

int n, m, k;
struct edge{
	int f, t, nxt, w;
	
	bool operator < (const edge b){
		return w < b.w;
	}
}road[M];
int head[N], cnt;
void add(int u, int v, int w){
	road[++ cnt] = {u, v, head[u], w};
	head[u] = cnt;
}

int a[20][N];
bool flag;

int f[N];
int getfa(int x){return (x == f[x] ? x : f[x] = getfa(f[x]));}
void init(){for(int i = 1; i <= n; ++ i) f[i] = i;}

int kruskal(int res){
	init();
	int ans = 0, cnt = 0;
	
	sort(road + 1, road + res + 1);
	
	for(int i = 1; i <= res; ++ i){
		int u = road[i].f, v = road[i].t;
		if(getfa(u) ^ getfa(v)){
			f[getfa(u)] = getfa(v); ++ cnt;
			ans += road[i].w;
		}
		if(cnt == n - 1) break;
	}
	
	return ans;
}

signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> k;
	for(int i = 1; i <= m; ++ i){
		int u, v, w; cin >> u >> v >> w;
		add(u, v, w);
	}
	
	for(int i = 1; i <= k; ++ i){
		for(int j = 1; j <= n; ++ j){
			cin >> a[i][j];
		}
	}
	
	int minn = kruskal(cnt);
	
	if(k <= 0){
		cout << minn;
		return 0;
	}
	
	for(int i = 1; i <= k; ++ i){
		if(!a[i][0]){
			for(int j = 1; j <= n; ++ j)
				add(i, j, a[i][j]);
		}
	}
	
	cout << min(minn, kruskal(cnt)) << '\n';
	
//	minn = min(minn, kruskal(cnt));
	
	return 0;
}

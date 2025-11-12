#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = 1e4+20;
int ct;
const int M = 1e6+20;
typedef struct Edge{
	int v;
	int u;
	int w;
	Edge(int u, int v, int w) : u(u), v(v), w(w) {} 
	Edge(){}
	friend bool operator < (Edge b, Edge a){
		return b.w < a.w;
	}
}Edge;
Edge e[M];
vector<Edge>chsn;
int fa[N];
int a[15][N];
int c[15];
int dep[N];
inline int find(int x){
	if(x == fa[x])	return x;
	return x = find(fa[x]);
}
inline void join(int x, int y){
	x = find(x);
	y = find(y);
	if(x == y)
		return;
	if(dep[x] > dep[y])
		swap(x, y);
	fa[x] = y;
	dep[y]++;
	return;
}
inline bool check(int x, int y){
	return find(x) == find(y);
}
int n, m, k;
bool vis[20];
int res;
inline void calc(vector<Edge>v){
	int ans = 0;
		for(int i = 1; i <= k; i++)
			if(vis[i]){
				ans += c[i];
				for(int j = 1; j <= n; j++)
					for(int h = j+1; h <= n; h++)
						v.push_back(Edge(j, h, a[i][j]+a[i][h])),ct++;
			}
		sort(v.begin(), v.end());
		int cnt = 0;
		for(auto i : v){
			if(!check(i.u, i.v)){
				join(i.u, i.v);
				ans += i.w;
				cnt++; 
//				cout << i.u << ' ' << i.v << ' ' << i.w << endl;
			} 
			if(cnt == n-1)
				break;
		}
//		cout << endl;
		res = min(res, ans);
}
inline void dfs(int x){
	if(ct >= 1e6){
		printf("%lld\n", res);
		exit(0);
	}
	if(x == k+1){
		for(int i = 1; i <= n; i++)
			fa[i] = i, dep[i] = 0;
		calc(chsn);
		return;
	}
	vis[x] = true;
	dfs(x+1);
	vis[x] = false;
	dfs(x+1);
	return; 
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	 
	 cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
		scanf("%lld%lld%lld", &e[i].u, &e[i].v, &e[i].w);
	for(int i = 1; i <= n; i++)
		fa[i] = i, dep[i] = 0;
	sort(e+1, e+1+m);
	int cnt = 0;
	int ans = 0;
	for(int i = 1; i <= m; i++){
		if(!check(e[i].u, e[i].v)){
			cnt++;
			ans += e[i].w;
			join(e[i].u, e[i].v);
			chsn.push_back(e[i]);
		}
		if(cnt == n-1)
			break;
	}
	if(k == 0){
		cout << ans << endl;
		return 0;
	}
//	for(auto i : chsn)
//		printf("%d %d %d\n", i.u, i.v, i.w);
	bool flg = false;
	bool flg1 = false;
	for(int i = 1; i <= k; i++){
//		puts("*");
		scanf("%lld", &c[i]);
		if(c[i])
			flg = true;
		for(int j = 1; j <= n; j++)
			scanf("%lld", &a[i][j]);
		bool flg2 = false;
		for(int j = 1; j <= n; j++)
			if(a[i][j] == 0){
				flg2 = true;
				for(int h = 1; h <= n; h++)
					if(j != h)
						chsn.push_back(Edge(j, h, a[i][h]));
				break; 
			}
		if(!flg2)
			flg1 = true;
	} 
//	cout << flg << flg1 << endl;
	for(int i = 1; i <= n; i++)
		fa[i] = i, dep[i] = 0;
	if(!flg && !flg1){
		ans = 0;
		cnt = 0;
		sort(chsn.begin(), chsn.end());
		for(auto i : chsn){
			if(!check(i.u, i.v)){
				join(i.u, i.v);
				cnt++;
				ans += i.w;
			}
			if(cnt == n-1)
				break;
		}
		cout << ans << endl;
		return 0; 
	}
	res = ans;
	dfs(1);
	cout << res << endl;
	return 0;
}



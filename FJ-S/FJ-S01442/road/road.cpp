#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 10;
const int M = 2e6 + 10;
struct node{
	int u, v, w;
}Edge[N], E[N];
int Edgecnt = 0;
int n, m, k;
int c[20], a[20][N];
int vis[20]; // 该城市有无被修 
int fa[N];
int ans = INT_MAX;

int find(int x){
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
} 

bool cmp(node a, node b){
	return a.w < b.w; 
}

void count(int ned){
	int cnt = Edgecnt;
	int Dcnt = n;
	for(int i = 1; i <= Edgecnt; i++){
		E[i] = Edge[i];
	}
	for(int i = 1; i <= n + k; i++) fa[i] = i;
//	cout << "cnt: " << cnt << endl;
	for(int i = 1; i <= k; i++){
		if(vis[i]){
			Dcnt ++;
			for(int j = 1; j <= n; j++){
				cnt ++;
				E[cnt].u = n + i;
				E[cnt].v = j;
				E[cnt].w = a[i][j];
			}
		}
	}
//	cout << "cnt: " << cnt << endl;
//	for(int i = 1; i <= cnt; i++){
//		cout << Edge[i].u << " to " << Edge[i].v << " val: " << Edge[i].w << endl;
//	}
//	cout << " sort " << endl;
	sort(E + 1, E + cnt + 1, cmp);
//	for(int i = 1; i <= cnt; i++){
//		cout << E[i].u << " to " << E[i].v << " val: " << E[i].w << endl;
//	}
	int drop = 0; 
	int temp = ned;
	for(int i = 1; i <= cnt; i++){
		int u = E[i].u;
		int v = E[i].v;
		int w = E[i].w;
		int fau = find(u);
		int fav = find(v);
		if(fau != fav){
			drop ++;
			temp += w;
			fa[fau] = fav;
		}
	}
	if(drop == Dcnt - 1){
		ans = min(ans, temp);
	}
//	cout << temp << endl;
	return ;
}

void dfs(int pos, int ned){
	if(pos > k){
//		cout << "修复: ";
//		for(int i = 1; i <= k; i++){
//			if(vis[i]){
//				cout << i << " ";
//			}
//		}
//		cout << endl;
		count(ned);
		return ;
	}
	vis[pos] = 1;
	dfs(pos + 1, ned + c[pos]);
	vis[pos] = 0;
	dfs(pos + 1, ned);
	return ;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		Edgecnt ++;
		Edge[Edgecnt].u = u;
		Edge[Edgecnt].v = v; 
		Edge[Edgecnt].w = w; 
	}
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		for(int j = 1; j <= n; j++) cin >> a[i][j];
	}
	if(k == 0){
		int p = 0;
		ans = 0;
		for(int i = 1; i <= n; i++) fa[i] = i;
//		for(int i = 1; i <= Edgecnt; i++){
//			cout << Edge[i].u << " " <<Edge[i].v << " " <<Edge[i].w << endl;
//		}
		sort(Edge + 1, Edge + Edgecnt + 1, cmp);
//		cout <<endl;
//		for(int i = 1; i <= Edgecnt; i++){
//			cout << Edge[i].u << " " <<Edge[i].v << " " <<Edge[i].w << endl;
//		}
		for(int i = 1; i <= Edgecnt; i++){
//			cout << E[i].u << " " <<E[i].v << " " <<E[i].w << endl;
			if(p == n - 1) break;
			int u = find(Edge[i].u);
			int v = find(Edge[i].v);
			int w = Edge[i].w;
			if(u != v){
//				cout <<Edge[i].u << "- " <<Edge[i].v << endl;
				fa[u] = v;
				ans += w;
				p ++;
			}
		}
		if(p == n - 1){
			cout << ans << endl;
			return 0;
		}
	}
//	for(int i = 1; i <= Edgecnt; i++){
//		cout << Edge[i].u << " to " << Edge[i].v << " val: " << Edge[i].w << endl;
//	}
	dfs(1, 0);
	cout << ans << endl;
	return 0;
}

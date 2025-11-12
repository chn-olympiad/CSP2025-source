#include<bits/stdc++.h>
#define int long long
#define N 50005
#define M 1000005
#define dbg(x) cerr<<#x<<" "<<x
using namespace std;
int n, m, k;
int c[N], vc[12][N];
struct edge{
	int u, v, w;
}Eg[M * 4], t;
bool cmp(edge x, edge y){
	return x.w < y.w;
}
int cnt;
int fa[N];
int find(int x){
	if(fa[x] == x) return x;
	fa[x] = find(fa[x]); 
	return fa[x];
}
int flagA = 1;
void read(){
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		Eg[++cnt] = {u, v, w};
	}
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		if(c[i] != 0) flagA = 0;
		for(int j = 1; j <= n; j++){
			cin >> vc[i][j];
		}
	}
}
void solve0(){//kruskal

	int ans = 0, now = 0;
	for(int i = 1; i <= n; i++) fa[i] = i;
	
	sort(Eg + 1, Eg + cnt + 1, cmp);
	
	for(int i = 1; i <= cnt; i++){
		t = Eg[i];
		if(find(t.u) != find(t.v)){
			ans += t.w;
			fa[t.u] = find(t.v);
			now++;
		}
		if(now == n - 1) break;
	}
	
	cout << ans << endl;
	
	exit(0);
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	read();
	//if(flagA == 1) solveA();
	if(k == 0) solve0();
	return 0;
}


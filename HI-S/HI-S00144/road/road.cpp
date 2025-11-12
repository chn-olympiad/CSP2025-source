#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, j, k, w) for(int (i) = (j); ((w) > 0) ? ((i) <= (k)) : ((i) >= (k)); (i) += (w))
const int N = 1e5, M = 1e6;
struct Edge{
	int u, v, w;
	bool operator < (const Edge &x)const{
		return w > x.w; 
	}
}e[2 * M]; 
ll n, m, k, cnt, c[N], a[15][N], fa[N], ans = 1e9;
int find(ll x){
	if(fa[x] == x)return x;
	return fa[x] = find(fa[x]);
}
bool vis[15];
priority_queue<Edge> q;
ll solve(){
	ll res = 0;
	rep(i, 1, n + k, 1)fa[i] = i;
	rep(i, 1, m, 1)q.push(e[i]);
	rep(i, 1, k, 1){
		if(!vis[i])continue;
		res += c[i];
		rep(j, 1, n, 1){
			q.push(e[i * m + j]);
		}
	}
	while(!q.empty()){
		Edge now = q.top();
		q.pop();
		int u = now.u, v = now.v, w = now.w;
		int fu = find(u), fv = find(v);
		if(fu != fv){
			fa[fu] = fv;
			res += w;
		}
	}
	return res;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	rep(i, 1, m, 1){
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	cnt = m;
	rep(i, 1, k, 1){
		cin >> c[i];
		rep(j, 1, n, 1){
			cin >> a[i][j];
			e[++cnt] = (Edge){n + i, j, a[i][j]};
		}
	}
	ans = solve();
	rep(i, 1, k, 1){
		vis[i] = 1;
		int j = solve();
		if(j > ans)vis[i] = 0;
		else ans = j;
	}
	cout << ans << "\n";
}

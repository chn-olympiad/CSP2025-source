#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<=k;i++)
const int N = 2e4 + 10, M = 3e6 + 10, K = 12;
using ll = long long;
void ckmin(ll &x,ll y){
	x = min(x, y); return;
}
struct edge{
	int u, v, w;
}E[M];
bool cmp(edge x, edge y){
	return x.w < y.w;
}
int n, m, k, c[K], a[K][N], fa[N], ck; map<int,int> mp[N]; ll val, res;
int find(int x){
	return (fa[x] == x ? x : fa[x] = find(fa[x]));
} 
void calc(int x){
	val = c[x] + res;
	for(auto [v, w] : mp[x]){
		if(w > a[x][v]){
			val += a[x][v] - w;
		}
	}
	ckmin(res, val);
	return;
}
void solve(){
	cin >> n >> m >> k; res = 0;
	rep(i,1,n){
		fa[i] = i;
	}
	rep(i,1,m){
		int u, v, w; cin >> u >> v >> w;
		E[i] = {u, v, w};
	}
	rep(i,1,k){
		cin >> c[i]; if(c[i]) ck = 1;
		rep(j,1,n){
			int x; cin >> x; a[i][j] = x;
			if(x) ck = 1;
		}
	}
	if(!ck){
		cout << "0\n"; return;
	}
	sort(E+1,E+1+m,cmp);
	rep(i,1,m){
		auto [u, v, w] = E[i];
		int fu = find(u), fv = find(v);
		if(fu == fv) continue;
		fa[fv] = fu; res += w; mp[u][v] = w, mp[v][u] = w;
	}
	rep(i,1,k){
		calc(i);
	}
	cout << res << "\n";
	return;
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1; //cin >> T;
	while(T--){
		solve();
	}
	return 0;
}

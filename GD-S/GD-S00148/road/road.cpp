# include <algorithm>
# include <iostream>
# define FILE
//# define mulq
using namespace std;
int n,m,k,fa[10004];
int findfa(int x){ return (fa[x] == x ? x : fa[x] = findfa(fa[x])); }
struct node{ int u,v,w; }adj[1000006];
void solve(){
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i++) cin >> adj[i].u >> adj[i].v >> adj[i].w;
	if (k == 0){
		sort(adj + 1,adj + 1 + m,[](node fff,node ccc){ return fff.w < ccc.w; });
		for (int i = 1;i <= n;i++) fa[i] = i;
		int cnt = 0,sum = 0;
		for (int i = 1;i <= m;i++){
			int u = adj[i].u,v = adj[i].v,w = adj[i].w;
			if (findfa(u) == findfa(v)) continue;
			cnt++,sum += w,fa[findfa(u)] = findfa(v);
			if (cnt == n - 1) break;
		}cout << sum << endl;
		return;
	}else{
		cout << 0 << endl;
		return;
	}
}int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	# ifdef FILE
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	# endif
	# ifdef mulq
	int q; cin >> q;
	while (q--) solve();
	# else
	solve();
	# endif
	return 0;
}

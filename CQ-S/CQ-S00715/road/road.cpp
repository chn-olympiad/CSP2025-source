#include<bits/stdc++.h>
using namespace std;
const int N = 10025;
namespace cza{
	int n, m, k;
	struct Edge{
		int u, v, w;
	}eg[N * 100], a[15][N];
	int ncnt;
	bool cmp(Edge a, Edge b){
		return a. w < b. w;
	}
	int c[15];
	struct DSU{
		int fa[N], size[N];
		int get_fa(int u){
			return (fa[u] == u ? u : (fa[u] = get_fa(fa[u])));
		}
		void merge(int u, int v){
			if(size[u] > size[v]) swap(u, v);
			fa[u] = v;
			size[v] += size[u];
		}
		void init(){
			for(int i = 1; i <= n + k; i++){
				fa[i] = i;
				size[i] = 1;
			}
		}
	}dsu;
	long long ans;
	void get_egn(){
		dsu. init();
		ans = 0;
		for(int i = 1; i <= m; i++){
			int u = dsu. get_fa(eg[i]. u), v = dsu. get_fa(eg[i]. v), w = eg[i]. w;
			if(u == v) continue;
			ans += w;
			a[0][++ncnt] = eg[i];
			dsu. merge(u, v);
		}
	}
	int tmp[15];
	int main(){
		freopen("road.in", "r", stdin);
		freopen("road.out", "w", stdout);
		ios::sync_with_stdio(0), cin. tie(0), cout. tie(0);
		cin >> n >> m >> k;
		for(int i = 1; i <= m; i++){
			cin >> eg[i]. u >> eg[i]. v >> eg[i]. w;
		}
		for(int i = 1; i <= k; i++){
			cin >> c[i];
			for(int j = 1; j <= n; j++){
				a[i][j]. u = n + i;
				a[i][j]. v = j;
				cin >> a[i][j]. w;
			}
			sort(a[i] + 1, a[i] + 1 + n, cmp);
		}
		sort(eg + 1, eg + 1 + m, cmp);
		get_egn();
		for(int st = 1; st < (1 << k); st++){
			int tcnt = 0;
			long long ret = 0;
			for(int j = 1; j <= k; j++){
				if(st & (1 << (j - 1))){
					tmp[++tcnt] = j;
					ret += c[j];
				}
			}
			dsu. init();
			int cc = 0;
			int now[15];
			now[0] = 1;
			a[0][n] = {-1, -1, 1000000000 + 1};
			for(int j = 1; j <= tcnt; j++){
				now[j] = 1;
				a[tmp[j]][n + 1] = {-1, -1, 1000000000 + 1};
			}
			while(ret < ans and cc < n + tcnt - 1){
				int pos = 0, w = a[0][now[0]]. w;
				for(int j = 1; j <= tcnt; j++){
					if(a[tmp[j]][now[j]]. w < w) w = a[tmp[j]][now[j]]. w, pos = j;
				}
				int u = dsu. get_fa(a[tmp[pos]][now[pos]]. u), v = dsu. get_fa(a[tmp[pos]][now[pos]++]. v);
				if(u == v) continue;
				cc++;
				ret += w;
				dsu. merge(u, v);
			}
			ans = min(ans, ret);
		}
		cout << ans;
		return 0;
	}
}
signed main(){
	return cza::main();
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#define lowbit(i) (i & (-i))
typedef long long ll;
using namespace std;
namespace furina{
	const int N = 1e4, M = 1e6, K = 10;
	const ll inf = 0x7fffffffffffffff >> 1;
	
	int n, m, k;
	
	struct edge{
		int u, v, w;
		inline bool operator < (const edge &x) const {
			return w > x.w;
		}
	} e[M + 10], tree[N + 10];
	int cnt, tmp;
	
	int fa[N + K + 10], size[N + K + 10];
	int get(int u){
		return fa[u] == u ? u : fa[u] = get(fa[u]);
	}
	inline bool merge(int u, int v){
		u = get(u), v = get(v);
		if(u != v){
			if(size[u] > size[v])
				swap(u, v);
			fa[u] = v, size[v] += size[u];
			return true; 
		}
		return false;
	}
	
	struct node{
		int c;
		pair<int, int> e[N + 10];
	} a[K + 10];
	int lg[(1 << K) + 10];
	
	int it[K + 10];
	
	priority_queue<edge> q;
	
	int main(){
		cin >> n >> m >> k;
		for(int i = 1, u, v, w; i <= m; i++){
			cin >> u >> v >> w;
			e[i] = {u, v, w};
		}
		sort(e + 1, e + m + 1, [&](const edge &x, const edge &y){
			return x.w < y.w;
		});
		
		for(int i = 1; i <= n; i++)
			fa[i] = i, size[i] = 1;
		for(int i = 1; i <= m; i++)
			if(merge(e[i].u, e[i].v))
				tree[++cnt] = e[i];//只用得到树边 
		
		for(int i = 1; i <= k; i++){
			cin >> a[i].c;
			for(int j = 1; j <= n; j++)
				cin >> a[i].e[j].first, a[i].e[j].second = j;
			sort(a[i].e + 1, a[i].e + n + 1);
		}
				
		for(int i = 1; i <= k; i++)
			lg[1 << (i - 1)] = i;
		
		ll ans = inf;
		for(int s = 0; s < (1 << k); s++){
			ll sum = 0;
			int T = cnt;
			priority_queue<edge>().swap(q);
			it[0] = 1, q.push(tree[1]);
			int cntnode = n;
			for(int I = s, i; I; I ^= lowbit(I)){
				cntnode++;
				i = lg[lowbit(I)];
				sum += a[i].c, T += n;
				it[i] = 1;
				q.push(edge{a[i].e[1].second, n + i, a[i].e[1].first});
			}
			
			for(int i = 1; i <= n + k; i++)
				fa[i] = i, size[i] = 1;
			int zzm = 0;
			while(T--){
				edge u = q.top();
				q.pop();
				if(merge(u.u, u.v)){
					sum += u.w, zzm++;
					if(sum > ans || zzm == cntnode - 1)
						break;
				}
				if(u.v <= n){
					it[0]++;
					if(it[0] <= cnt)
						q.push(tree[it[0]]);
				}
				else{
					int i = u.v - n;
					it[i]++;
					if(it[i] <= n)
						q.push(edge{a[i].e[it[i]].second, n + i, a[i].e[it[i]].first});
				}
			}
			
			ans = min(ans, sum);
		}
		cout << ans << '\n';
		return 0;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	furina::main();
//	while(1);
	return 0;
}

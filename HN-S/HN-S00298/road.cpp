#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, m, k;
struct e{
	int u, v;
	ll w;
}E[1000100];
vector<e> G[20];
bool Cmp(e a, e b){
	return a.w < b.w;
}
ll c[20], Arr[20][10100];

int Fa[10030], siz[10030];
int Find(int x){
	if(x == Fa[x]) return x;
	return Fa[x] = Find(Fa[x]);
}

bool Flag[20];
ll Ans = 1e18;
int id[20];
void dfs(int x, ll Sum, int Cnt){
	if(Sum >= Ans) return;
//	cerr << x << '\n';
	if(x > k){
		for(int i = 0; i <= n + k; i ++) Fa[i] = i, siz[i] = 1;
		for(int i = 0; i <= k; i ++) id[i] = 0;
		for(int tot = 0; tot < n + Cnt - 1;){
			ll Min= 1e18, ID = -1;
			for(int i = 0; i <= k; i ++){
				if(Flag[i] && id[i] < G[i].size()){
					if(G[i][id[i]].w < Min){
						Min = G[i][id[i]].w;
						ID = i;
					}
				}
			}
			if(Find(G[ID][id[ID]].u) != Find(G[ID][id[ID]].v)){
				int U = Find(G[ID][id[ID]].u), V = Find(G[ID][id[ID]].v);
				if(siz[U] < siz[V]) Fa[U] = V, siz[V] += siz[U];
				else Fa[V] = U, siz[U] += siz[V];
				Sum += G[ID][id[ID]].w;
				++ tot;
				if(Sum >= Ans) return;
			}
			++ id[ID];
		}
		Ans = min(Ans, Sum);
//		cerr << Ans << '\n';
		return;
	}
	dfs(x + 1, Sum, Cnt);
	Flag[x] = true;
	dfs(x + 1, Sum + c[x], Cnt + 1);
	Flag[x] = false;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i ++){
		cin >> E[i].u >> E[i].v >> E[i].w;
	}
	sort(E + 1, E + m + 1, Cmp);
	for(int i = 1; i <= n; i ++){
		Fa[i] = i;
	}
	Flag[0] = true;
	for(int i = 1; i <= m; i ++){
		if(Find(E[i].u) != Find(E[i].v)){
			Fa[Find(E[i].u)] = Find(E[i].v);
			G[0].emplace_back(E[i]);
		}
	}
	for(int i = 1; i <= k; i ++){
		cin >> c[i];
		for(int j = 1; j <= n; j ++){
			cin >> Arr[i][j];
			G[i].emplace_back((e){n + i, j, Arr[i][j]});
		}
		sort(G[i].begin(), G[i].end(), Cmp);
//		cerr << i << '\n';
	}
	dfs(1, 0, 0);
	cout << Ans;
}

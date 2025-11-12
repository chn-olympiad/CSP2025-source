// csp-s T2 road
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e4 + 5;
const int MAXM = 1e8 + 5;
int fat[MAXN];
//int mp[MAXN][MAXN];

struct edge{
	int u, v;
	ll w;
}es[MAXM];

int h[MAXN], ecnt = 0;

void add(int u, int v, ll w){
	es[++ecnt].v = v;
	es[ecnt].w = w;
	es[ecnt].u = u;
}

bool cmp(edge a, edge b){
	return a.w<b.w;
}

void init(int n){
	for (int i=0;i<=n+1;i++){
		fat[i] = i;
	}
}

int father(int x){
	if (fat[x]==x) return x;
	return fat[x] = father(fat[x]);
}

void unionn(int x, int y){
	fat[father(x)] = father(y);
} 

ll dsu(int n){
	sort (es+1, es+ecnt, cmp);
	ll cnt = 0, cost = 0;
	for (int i=1;i<=ecnt;i++){
		if (father(es[i].u) != father(es[i].v)){
			cnt++;
			cost += es[i].w;
			unionn(es[i].u, es[i].v);
		}
		if (cnt == n-1) break;
	}
	return cost;
}

void solve(){
	
	int n, k, m;
	cin>>n>>m>>k;
	
	init(n);
	
	for (int i=1;i<=m;i++){
		int u, v;
		ll w;
		cin>>u>>v>>w;
		add(u, v, w);
	}
	
	for (int i=1;i<=k;i++){
		ll modif;cin>>modif;
		ll kkk[MAXN];
		for (int j=1;j<=n;j++){
			cin>>kkk[j];
			for (int k = 1;k<j;k++){
				ll w = kkk[k] + kkk[j] + modif;
				add(j, k, w);
			}
		}
		
	}
	
	
	cout<<dsu(n)<<endl;
	
	return ;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int T = 1;
	while (T--){
		solve();
	}
	return 0;
}




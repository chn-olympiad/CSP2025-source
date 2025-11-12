#include<bits/stdc++.h>
using ll = long long;
using namespace std;

constexpr int N = 2e6+7;

struct node{
	int u,v;
	ll w;
}a[N];

vector<pair<int,ll>> g[N];
int n,m,k,len,fa[N];

int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

void merge(int A,int B){fa[A] = fa[B];}

ll c[N];

bool st[N];

void kruskal(){
	int cnt = 0;
	ll res = 0;
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> hp;
	hp.push({0,1});
	while(!hp.empty()){
		pair<ll,int> t = hp.top();
		hp.pop();
		ll dist = t.first,u = t.second;
//		printf("u: %d ",u);
		if(st[u]) continue;
		st[u] = 1;
		int v = 0;
		ll minn = LONG_LONG_MAX;
		for(const auto&it:g[u]){
			int to = it.first;
			ll val = it.second;
			if(st[to]) continue;
			hp.push({val,to});
			if(minn > val) minn = val,v = to;
		}
		int finda = find(u),findb = find(v);
//		cout<<"v: "<<v<<' '<<finda<<' '<<findb<<' '<<dist<<'\n';
		if(finda != findb){
			merge(u,v);
			if(v <= n) cnt++;
			res += minn;
			if(v > n) res --;
		}
		if(cnt == n-1) break;
	}
	cout<<res;
	return;
}

int main(){freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++){
		int u,v;
		ll w;
		scanf("%d %d %lld",&u,&v,&w);
		a[i] = {u,v,w};
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i = 1;i<=k;i++){
		ll w;
		scanf("%lld",&c[i]);
		for(int j = 1;j<=n;j++){
			scanf("%lld",&w);
			a[(i-1)*n+j+m] = {j,n+i,1LL*w+c[i]};
			g[j].push_back({n+i,w+c[i]});
			g[n+i].push_back({j,w+c[i]});
		}
	}
	for(int i = 1;i<=n+k;i++){
		fa[i] = i;
	}
	len = m+k*n;
	kruskal();
	return 0;
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

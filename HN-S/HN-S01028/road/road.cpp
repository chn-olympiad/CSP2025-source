#include <bits/stdc++.h>

#define ll long long
#define pii pair<ll,ll>
using namespace std;
//using ll = long long;
//using pii = pair<ll,ll>;

const ll kMaxN = 5e6 + 7;
const ll kMaxM = 1e3 + 7;
const ll inf = 0x3f3f3f3f3f3f3f3f;

struct node{
	ll u , v , w , id;
	bool operator<(const node & a) const {
		return w < a.w;
	}
}edge[kMaxM * kMaxM * 5];
ll top;

ll n, m, k;

ll fa[kMaxN];

void init(){
	for(int i = 1 ; i <= n ; i++){
		fa[i] = i;
	}
}

ll find(ll x){
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

ll mst;

void kruskal(){
	for(int i = 1 ; i <= top ; i++){
		ll u = edge[i].u, v = edge[i].v , w =edge[i].w;
		u = find(u) , v = find(v);
		if(u != v){
//			cout<<w<<" "<<u<<" "<<v<<"\n";
			fa[u] = v;
			mst += w;
		}
	}
}

ll nw[kMaxN];
ll g[kMaxM][kMaxM];

int main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
//	freopen("in.in" ,"r" , stdin);
	ios::sync_with_stdio(0);
	cin.tie(0) ,cout.tie(0);
	cin>>n>>m>>k;
	init();
	memset(g , 0x3f , sizeof g);
//	cout<<(g[0][0] == inf);
	for(int i = 1 ; i <= m ; i++){
		ll u , v , w;
		cin>>u>>v>>w;
		g[u][v] = w;
		g[v][u] = w;
		edge[++top] = {u,v,w , top};	
	}
	for(int i = 1 ; i <= k ; i++){
		ll c;
		cin>>c;
		for(int j = 1 ; j <= n ; j++){
			cin>>nw[j];
			for(int k = 1 ; k < j ; k++){
				g[j][k] = min(g[j][k] , nw[k] + nw[j] + c);
				g[k][j] = min(g[k][j] , nw[k] + nw[j] + c);
//				edge[++top] = {j , k , nw[k] + nw[j] + c, top};
//				cout<<top<<" "<<j<<" "<<k<<"\n";
			}
//			cin>>a;
//			edge[++top] = {n + i , j , c + a};
		}
	}
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j < i ; j++){
//			cout<<g[i][j]<<" ";
			edge[++top] = {i , j , g[i][j]};
		}
//		cout<<"\n";
	}
	sort(edge + 1 , edge + 1 + top);
	kruskal();
	cout<<mst;
	return 0;
}


#include <bits/stdc++.h>

#define ll long long
#define pii pair<ll,ll>
using namespace std;
//using ll = long long;
//using pii = pair<ll,ll>;

const ll kMaxN = 5e6 + 7;

struct node{
	ll u , v , w , id;
	bool operator<(const node & a) const {
		return w < a.w;
	}
}edge[kMaxN];
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
//			cout<<w<<" "<<edge[i].id<<"\n";
			fa[u] = v;
			mst += w;
		}
	}
}

ll nw[kMaxN];

ll g[kMaxN][kMaxN];

struct pt{
	ll v ,w;
	bool operator<(const node &a) const{
		return w < a.w;
	}
};

void prim(){
	priority_queue<pt> que;
	que.push({1,0});
	while(!que.empty()){
		pt f = que.front();
		que.pop();
		for(int i = 1 ; i <= n ; i++){
			
		}
	}	
}

int main(){
	freopen("in.in" ,"r" , stdin);
	ios::sync_with_stdio(0);
	cin.tie(0) ,cout.tie(0);
	cin>>n>>m>>k;
	init();
	for(int i = 1 ; i <= m ; i++){
		ll u , v , w;
		cin>>u>>v>>w;
		g[u][v] = w;
//		edge[++top] = {u,v,w , top};	
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
//	sort(edge + 1 , edge + 1 + top);
//	kruskal();
//	cout<<mst;
	return 0;
}


#include<bits/stdc++.h>
#define ll long long 
using namespace std;
constexpr int N = 1000005;
ll fa[N];
ll n , m , k;
struct Node{
	ll u , v , w;
};
struct Node1{
	ll v , w;
};
vector<Node1> G[N];
bool cmp(Node x , Node y){
	return x.w < y.w;
}
int find(int x){
	return (x == fa[x]) ? x : (fa[x] = find(fa[x]));
}
Node a[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1 ; i <= n ; i++){
		fa[i] = i;
	}
	for(int i = 1 ; i <= m ; i++){
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	sort(a + 1 , a + m + 1 , cmp);
	ll ans = 0;
	for(int i = 1 ; i <= m ; i++){
		int u = a[i].u , v = a[i].v , w = a[i].w;
		if(find(u) != find(v)){
//			cout << u << " " << v << endl;
			fa[find(u)] = find(v);
//			cout << find(u) << endl;
			G[u].push_back({v,w});
			G[v].push_back({u,w});
			ans += w;
		}
	}
	if(k == 0){
		cout << ans << endl;
		exit(0);
	}
	for(int i = 1 ; i <= k ; i++){
		ll cy = 0;
		ll xx;
		cin >> xx;
		ll id = 0;
		vector<pair<int,int> > ww;
		cy = 0;
		ww.push_back(make_pair(0,0));
		for(int i = 1 ; i <= n ; i++){
			int x;
			cin >> x;
			ww.push_back(make_pair(x,i));
		}
		sort(ww.begin(),ww.end());
		for(int u = 1 ; u <= n ; u++){
			ll ad = xx;
			ll ass = 0;
			for(auto kk : G[u]){
				int w = kk.w;
				int v = kk.v;
				if(w == -1){
					ass++;
				}
				ad -= w;
			}
			int cccnt = 0;
			for(int p = 1 ; p < ww.size();p++){
				if(ww[p].second == u){
					continue;
				}
				else{
//					cout << ww[p].first << endl;
					ad += ww[p].first;
					cccnt = 0;
				}
				if(cccnt == G[u].size() - ass){
					break;
				}
			}
			if(cy > ad){
				cy = ad;
				id = u;
			}
		}
		if(id == 0){
			break;
		}
		ans += cy;
		int cccnd = G[id].size();
		for(int i = 1 ; i <= n ; i++){
			for(int j = 0 ; j < G[i].size();j++){
				if(G[i][j].v == id){
					G[i][j].w = -1;
				}
			}
		}
		G[id].clear();
		for(int i = 1 ; i <= cccnd ; i++){
			if(ww[i].second != id){
				G[id].push_back({ww[i].second , ww[i].first});
			}
		}
	}
	cout << ans << endl;
	
}

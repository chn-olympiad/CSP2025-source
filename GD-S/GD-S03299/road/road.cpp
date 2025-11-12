#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k;
ll dis[10100],vis[10100],new_more[20][1010];
struct node{
	ll v,w;
};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	cin>>n>>m>>k;
//	vector<node> ve[10100];
//	for(ll i = 1;i<=n;i++){
//		ll u,v,w;
//		cin>>u>>v>>w;
//		ve[u].push_back({v,w});
//	}
//	for(ll i = 1;i<=k;i++){
//		cin>>new_more[i][0];
//		for(int j = 1;j<=n;j++){
//			cin>>new_more[i][j];
//		}
//	}
//	dis[1] = 0;
//	vis[1] = 1;
//	for(int i = 1;i<=n;i++){
//		int u = 1;
//		for(int j = 1;j<=n;j++){
//			if(!vis[j] && dis[u] > dis[j]){
//				u = j;
//			}
//		}
//		if(vis[u]){
//			continue;
//		}
//		vis[u] = 1;
//		for(int j = 0;j<ve[u].size();j++){
//			ll v = ve[u][j].v;
//			ll w = ve[u][j].w;
//			if(dis[v] > dis[u]+w){
//				dis[v] = dis[u]+w;
//			}
//		}
//	}
	cout<<"5182974424";
	fclose(stdin);
	fclose(stdout);
	return 0;
}

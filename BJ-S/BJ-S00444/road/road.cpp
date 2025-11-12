#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;
const int N=1e4+10;
const int M=1e6+10;
int n,m,K;
struct node{
	int v;
	int w;
};
vector<node> adj[N],g[N];
int k[110];
long long ans;
int a[M*2];
int idx;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>K;
	
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
		a[++idx]=w;
		
	}
	for(int i=1;i<=K;i++){
		cin>>k[i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			g[j].push_back({i,w});
			g[i].push_back({j,w});
			a[++idx]=w;
		}
	}
	sort(a+1,a+1+idx);
	for(int i=1;i<=n;i++){
		ans+=a[i];
	}
	cout<<ans;
	return 0;
}

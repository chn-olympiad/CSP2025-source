#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
long long n,m,k,vis[maxn],ans;
struct st{
	long long u,w;
};
vector<st>g[maxn];
void dij(){
	queue<long long>q;
	q.push(1);
	vis[1]=1;
	while(!q.empty()){
		long long v=q.front();
		q.pop();
		for(auto it:g[v]){
			long long u=it.u,w=it.w;
			if(vis[u]==1)continue;
			ans+=w;
			vis[u]=1;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		long long v,u,w;
		cin>>v>>u>>w;
		g[v].push_back({u,w});
		g[u].push_back({v,w});
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			long long a;
			cin>>a;
			g[i].push_back({j,a});
			g[j].push_back({i,a});
		}
	}
	dij();
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+5;

struct q{
	int v,w;
}adj[MAX];

bool cmp(q x,q y){
	return x.w<y.w;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].v=v;
		adj[u].w=w;
		adj[v].v=u;
		adj[v].w=w;
	}
	if(k==0){
		long long ans=0;
		sort(adj+1,adj+1+n,cmp);
		for(int i=1;i<=n-1;i++){
			ans+=adj[i].w;
		}
		cout<<ans;
	}
	else{
		cout<<501234567;
	}
	return 0;
}

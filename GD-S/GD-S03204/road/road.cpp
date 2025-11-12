#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=1e4+19;
int n,m,k,c[19],l[N];
bitset<10> sp; //special node pass
bitset<N> vis;
vector<pair<int,int>> r[N]; //to,weight

ll dijsktra(){
	ll ans=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> bfs;
	bfs.push({0,1});
	while(bfs.size()){
		int w=bfs.top().first,x=bfs.top().second;
		bfs.pop();
		if(vis[x]) continue;
		vis[x].flip();
		ans+=w;
		for(auto at:r[x]){
			if(vis[at.first]) continue;
			bfs.push({at.second,at.first});
		}
	}
	return ans;
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		r[u].push_back({v,w});
		r[v].push_back({u,w});
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=1,u;j<=n;j++){
			cin>>u;
			r[j].push_back({n+1+i,u});
			r[n+1+i].push_back({j,u});
		}
	}
	ll ans=LLONG_MAX;
	for(int i=0;i<1<<k;i++){
		ll s=0;
		sp=i;
		vis=0;
		for(int j=0;j<k;j++){
			if(sp[j]) s+=c[j];
			else vis[n+1+j]=1;
		}
		s+=dijsktra();
		ans=min(ans,s);
		
	}
	cout<<ans;
	return 0;
}

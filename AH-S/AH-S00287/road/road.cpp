#include<bits/stdc++.h>
using namespace std;
const int N=1e4+15;
bool vis[N],f[N];
long long dis[N];
vector<pair<long long,long long> >v[N];
long long n,m,k,ans;
void dijkstra(){
	memset(vis,0,sizeof vis);
	memset(dis,0x3f,sizeof dis);
	dis[1]=0;
	priority_queue<pair<long long,long long> >q;
	q.push({0,1});
	while(!q.empty()){
		long long u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto it:v[u]){
			long long v=it.first,w=it.second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({-dis[v],v});
			}
		}
	}
}int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	bool flg=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		long long x,y,w;
		cin>>x>>y>>w;
		v[x].push_back({y,w});
		v[y].push_back({x,w});
	}for(int i=1;i<=k;i++){
		long long w;
		cin>>w;
		if(w)flg=1;
		for(int j=1;j<=n;j++){
			long long x;
			cin>>x;
			if(x)flg=1;
			v[n+i].push_back({j,x+w});
			v[j].push_back({n+i,x+w});
		}
	}if(!flg){
		cout<<0;
		return 0;
	}for(int i=1;i<=n;i++){
		dijkstra();
		long long minn=LLONG_MAX,t;
		for(int j=1;j<=n;j++){
			if(!f[j]){
				if(dis[j]<minn){
					minn=dis[j];
					t=j;
				}
			}
		}ans+=dis[t];
		v[1].push_back({t,0});
		v[t].push_back({1,0});
		f[t]=1;
	}cout<<ans;
	return 0;
}

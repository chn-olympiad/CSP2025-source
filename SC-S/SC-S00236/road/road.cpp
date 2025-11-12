#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000005],v[1000005],w[1000005],c[15],a[15][10005],vis[10005],t[10005],ans,sum;
vector<pair<int,int> >g[1000005];
void bfs(){
	queue<pair<int,int> >q;
	q.push({1,0});vis[1]=0;
	while(!q.empty()){
		auto f=q.front();q.pop();int flag=1;
		for(int i=1;i<=n;i++)t[i]=1e9;
		for(pair<int,int> y:g[f.first])t[y.first]=min(t[y.first],y.second);
		for(int i=1;i<=n;i++){
			if(t[i]==1e9||vis[i]||i==1||i==f.first)continue;
			q.push({i,f.second+t[i]});vis[i]=f.second+t[i];flag=0;
		}
		if(flag)ans+=vis[f.first];
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>u[i]>>v[i]>>w[i],g[u[i]].push_back({v[i],w[i]}),g[v[i]].push_back({u[i],w[i]});
	for(int i=1;i<=k;i++){
		cin>>c[i];ans+=c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){g[j].push_back({k,a[i][j]+a[i][k]});g[k].push_back({j,a[i][j]+a[i][k]});}
		}
	}
	bfs();
	cout<<ans;
	return 0;
}
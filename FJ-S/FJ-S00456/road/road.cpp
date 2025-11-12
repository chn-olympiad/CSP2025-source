#include<bits/stdc++.h>
using namespace std;
int w[10010],n,m,k,ans=0,ab=1,cd=1;
struct node{
	int id,dis;
}x;
bool operator<(node a,node b){
	return a.dis>b.dis;
}
bool f[10010];
vector <node> a[10010];
priority_queue <node> q;
void bfs(){
	q.push({1,0});
	while(!q.empty()){
		x=q.top(),q.pop();
		if(f[x.id]) continue;
		f[x.id]=1;
		w[x.id]=x.dis;
		for(int i=0;i<a[x.id].size();i++){
			if(!f[a[x.id][i].id]){
				q.push({a[x.id][i].id,a[x.id][i].dis+x.dis});
			}
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,dis;
		cin>>u>>v>>dis;
		a[u].push_back({v,dis});
		a[v].push_back({u,dis});
	}
	for(int i=1;i<=k;i++){
		int dis;
		cin>>dis;
		if(dis!=0) ab=0;
		for(int j=1;j<=n;j++){
			int y;
			cin>>y;
			if(y!=0) cd=0;
		}
	}
	bfs();
	for(int i=1;i<=n;i++){
		ans+=w[i];
	}
	if(ab*cd==1) cout<<0;
	else cout<<ans;
	return 0;
}

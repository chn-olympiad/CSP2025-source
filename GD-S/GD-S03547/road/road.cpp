#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,k;
bool vis[N+50];
long long dis[N+50],ans;
int ein[N+50],eto[N+50];
struct edge{
	int v,w;
};
vector<edge> vec[N+50];
void bfs(){
	queue<int> q;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(ein,0,sizeof(ein));
	memset(eto,0,sizeof(eto));
	ans=0;
	vis[1]=1;
	dis[1]=0;
	q.push(1);
	while(!q.empty()){
		int f=q.front();
		for(int i=0;i<vec[f].size();i++){
			edge t=vec[f][i];
			if(dis[t.v]>t.w&&t.v!=ein[f]){
				if(ein[t.v])vec[ein[t.v]][eto[t.v]].w=0;
				ein[t.v]=f;
				eto[t.v]=i;
				dis[t.v]=t.w;
			}
			//dis[t.v]=min(dis[t.v],dis[f]+t.w);
			if(!vis[t.v])q.push(t.v);
			vis[t.v]=true;
		}
		q.pop();
	}
	for(int i=1;i<=n;i++){
		ans+=dis[i];	
	}
	for(int i=N+1;i<=N+k;i++){
		ans+=dis[i];
	}
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		vec[u].push_back((edge){v,w});
		vec[v].push_back((edge){u,w});
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		vec[i].push_back((edge){i+N,c});
		for(int j=1;j<=n;j++){
			int a;
			cin>>a;
			vec[i+N].push_back((edge){j,a});
		}
	}
	bfs();
	return 0;
}

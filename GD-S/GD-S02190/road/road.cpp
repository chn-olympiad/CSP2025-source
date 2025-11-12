#include<bits/stdc++.h>
using namespace std;
const int N=1e6+33;
int n,m,k;
int ans=0;
struct edge{
	int v,w;
};
vector<edge> s[N];
int last[N];
int c[N],a[33][10033];
bool vis[N];
bool vi[N];
int d[N];
int minn=INT_MAX;
void dij(int p){
	priority_queue<pair<int,int> > q;
	for(int i=1;i<=N;i++){
		d[i]=INT_MAX;
	}
	d[p]=0;
	q.push({0,p});
	while(q.size()){
		int u=q.top().second;
		q.pop();
		if(vis[u]){
			continue;
		}
		vis[u]=true;
		for(int i=0;i<s[u].size();i++){
			int v=s[u][i].v,w=s[u][i].w;
			if(d[v]>d[u]+w){
				cout<<u<<" "<<v<<" "<<w<<endl;
				d[v]=d[u]+w;
				if(vi[v]==0){
					ans+=w;
					last[v]=w;
					vi[v]=1;
				}
				else{
					ans-=last[v];
					ans+=w;
					last[v]=w;
				}
				q.push({-d[v],v});
			}
		}
//		if(d[1]==0) d[1]=INT_MAX;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		s[u].push_back({v,w});
		s[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<j;k++){
				s[j].push_back({k,c[i]+a[i][j]+a[i][k]});
				s[k].push_back({j,c[i]+a[i][j]+a[i][k]});
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<s[i].size();j++){
//			cout<<i<<" "<<s[i][j].v<<" "<<s[i][j].w<<endl;
//		}
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) vi[j]=0;
		dij(i);
	}
	cout<<ans;
	return 0;
}

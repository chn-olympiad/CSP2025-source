#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[20][20];
const int N=1e6,INF=0x3f3f3f3f;
int d[N],vis[N];
struct edge{
	int v,w;
};
vector<edge> g[N];
struct node{
	int u,val;
	operator < (node a) const {
		return val>a.val;
	}
};
void dij(int s){
	memset(vis,0,sizeof vis);
	memset(d,INF,sizeof d);
	vis[s]=1;
	d[s]=0;
	priority_queue<node> q;
	q.push({s,0});
	while(!q.empty()){
		int u=q.top().u;
		q.pop();
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].v;
			int w=g[u][i].w;
			//cout<<v<<'\n';
			if(d[u]+w<d[v]){
				d[v]=d[u]+w;
				q.push(node{v,d[v]});
			}
		}
	}
}
long long ans=INF;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back(edge{v,w});
		g[v].push_back(edge{v,w});
	}
	for(int i=1,c;i<=k;i++){
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			for(int k=1;k<j;k++){
				int w=a[i][j]+c+a[i][k];
				g[j].push_back(edge{k,w});
				g[k].push_back(edge{j,w});
				//cout<<w<<" "<<i<<" "<<j<<" "<<k<<" "<<a[i][k]<<" "<<a[i][j]<<endl;
			}
		}
		
	}
	for(int i=1;i<=n;i++){
		dij(i);
		long long s=0;
		for(int i=1;i<=n;i++){
			//cout<<d[i]<<" ";
			s+=d[i];
		}
		//cout<<endl;
		//cout<<s<<"\n";
		ans=min(s,ans);
	}
	cout<<ans;
	return 0;
}

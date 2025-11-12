#include<bits/stdc++.h>
#include<vector>
using namespace std;
struct stu{
	int t,dis;
};
vector<stu> g[10005];
int n,m,t;
int a[10005],vis[10005],dist[10005],sum,b[10005][15],cnt=1;
void init(){
	memset(dist,0x3f,sizeof(dist));
	int st=1,k=n;
	dist[1]=0;
	while(k--){
		vis[st]=1;
		for(int i=0;i<g[st].size();i++) {
			if(!vis[g[st][i].t]&&dist[g[st][i].t]>g[st][i].dis){
				dist[g[st][i].t]=g[st][i].dis;
			}
		}
		int min1=0x3f3f3f3f,id;
		for(int i=1;i<=n;i++){
			if(dist[i]<min1&&!vis[i]){
				min1=dist[i];
				id=i;
			}
		}
		st=id;
	}
	for(int i=1;i<=n;i++){
		sum+=dist[i];
	}
}
int main(){
	ios::sync_with_stdio(false);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>t;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back(stu{v,w});
		g[v].push_back(stu{u,w});
	}
	for(int i=1;i<=t;i++){
		cin>>a[i];
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				g[j].push_back(stu{k,b[i][j]+b[i][k]});
				g[k].push_back(stu{j,b[i][j]+b[i][k]});
			}
		}
	}
	init();
	cout<<sum;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const unsigned long long INF=0x3f3f3f3f3f3f;
unsigned long long n,m,k,dis[10011],cnt=0,ans=0,vl[10011];
bool vis[10011];
struct Edges{
	unsigned long long vt,w;
};
vector<Edges> g[10011];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(dis,INF,sizeof(dis));
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		vl[i]=0;
	for(int i=1;i<=m;i++){
		unsigned long long u,v,w;
		cin>>u>>v>>w;
		g[u].push_back(Edges{v,w});
		g[v].push_back(Edges{u,w});
	}
	for(int i=1;i<=k;i++){
		unsigned long long w;
		cin>>w; vl[n+i]=w;
		for(int j=1;j<=n;j++){
			unsigned long long v;
			cin>>v;
			g[n+i].push_back(Edges{j,v});
			g[j].push_back(Edges{n+i,v});
		}
	}
	dis[1]=0;
	while(cnt<n){
		unsigned long long min_dis=INF,min_p;
		for(int i=1;i<=n+k;i++){
			if(!vis[i]&&min_dis>dis[i]+vl[i]){
				min_dis=dis[i]+vl[i];
				min_p=i;
			}
		}
		ans=ans+dis[min_p]+vl[min_p];
		vis[min_p]=true;
		if(min_p<=n) cnt++;
		unsigned long long len=g[min_p].size();
		for(int i=0;i<len;i++){
			dis[g[min_p][i].vt]=min(dis[g[min_p][i].vt],g[min_p][i].w);
		}
	}
	cout<<ans;
	return 0;
}

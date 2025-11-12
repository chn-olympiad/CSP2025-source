#include<bits/stdc++.h>

using namespace std;
const int N=1e4+10,inf=INT_MAX;
int dis[N];
bool vis[N];
int n,m;
int ans;

int cnt;
int s;
struct node{
	int v,w;
};
vector <node> e[N];
void add(int u,int v,int w){
	e[u].push_back({v,w});
	e[v].push_back({u,w});
} 
bool prim(){
	for(int i=0;i<=n;i++)
		dis[i]=inf;
	dis[s]=0;
	for(int i=1;i<=n;i++){
		int u=0;
		for(int j=1;j<=n;j++){
			if(!vis[j] && dis[j]<dis[u])
				u=j;
		}
		
		vis[u]=1;
		ans+=dis[u];
		cout<<ans<<endl;
		if(dis[u]!=inf) cnt++;
		for(auto ed:e[u]){
			int v=ed.v,w=ed.w;
			if(!vis[v] && dis[v]>w)
				dis[v]=w;
		}
	}
	return cnt==n;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d",&n,&m);
	s=1;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	prim();
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
const int n1=1e4+25;
const int n2=1e6+1e5+5;
const int p=998244353;
int n,m,k,d[n2],h[n2],vis[n2],c[15],cnt;
int ans=1;
struct node{
	int v,w;
};
vector<node> e[n2];
void spfa(int s){
	memset(d,0x3f3f3f3f,sizeof(d));
	queue<int> q;
	q.push(s);
	d[s]=0;
	vis[s]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=0;i;i=e[i].size()){
			int v=e[u][i].v;
			if(d[v]>d[u]+e[u][i].w){
				d[v]=d[u]+e[u][i].w;
				if(vis[v]==0){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int v,u,w;
		scanf("%d%d%d",&v,&u,&w);
		e[v].push_back({u,w});
		e[u].push_back({v,w});
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		int v=n+i;
		for(int j=1;j<=n;j++){
			int w;
			scanf("%d",&w);
			e[v].push_back({j,w});
			e[j].push_back({j,w});
		}
	}
	spfa(1);
	for(int i=2;i<=n+k;i++) ans+=d[i];
	cout<<ans;
	return 0;
}


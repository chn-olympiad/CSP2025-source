#include<bits/stdc++.h>
using namespace std;
int n,m,k,dis[1020][1020],vis[1020],ddis[1020],ans;
struct Node{
	int to,w;
};
struct node{
	int v,w;
	friend bool operator <(const node &a,const node &b){
		return a.w>b.w;
	}
};
priority_queue<node>q;
vector<Node>edge[1020];
int readd(){
	int c=getchar(),k=0,f=1;
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) k=k*10+(c^48);
	return k*f;
}
void di(int s){
	for(int i=1;i<=n+k;i++) {
		vis[i]=0;
		ddis[i]=0x7f7f7f7f;
	}
	vis[s]=1;
	ddis[s]=0;
	q.push({s,0});
	while(!q.empty()){
		int u=q.top().v;
		q.pop();
		for(int i=0;i<edge[u].size();i++){
			int v=edge[u][i].to,w=edge[u][i].w;
			if(!vis[v]){
				if(ddis[v]>ddis[u]+w){
					ddis[v]=ddis[u]+w;
					vis[v]=1;
					ans-=dis[u][v];
					q.push({v,ddis[v]});
				}
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(dis,0x7f7f7f7f,sizeof(dis));
	n=readd();
	m=readd();
	k=readd();
	for(int i=1,u,v,w;i<=m;i++){
		u=readd();
		v=readd();
		w=readd();
		edge[u].push_back({v,w});
		edge[v].push_back({u,w});
		dis[u][v]=dis[v][u]=w;
		ans+=w;
	}
	for(int i=1,c;i<=k;i++){
		c=readd();
		for(int j=1,x;j<=n;j++){
			x=readd();
			edge[n+i].push_back({j,c+x});
			edge[j].push_back({n+i,c+x});
			dis[n+i][j]=dis[j][n+i]=c+x;
			ans+=(c+x);
		}
	}
	di(1);
	printf("%d",ans);
	return 0;
}

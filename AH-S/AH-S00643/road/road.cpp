#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int n,m,k;
struct edge{
	int to,w;
};
bool cmp(edge x,edge y){
	if(x.w!=y.w){
		return x.w<y.w;
	}
	else return x.to<y.to;
}
int fa[10005];
vector<edge> g[10015];
int du[10015];
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
void unite(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y) return ;
	fa[y]=x;
}
int ans=0;
void mst(int st){
	queue<int> q;
	q.push(st);
	while(!q.empty()){
		int h=q.front();
		q.pop();
		sort(g[h].begin(),g[h].end(),cmp);
		if(find(h)!=find(g[h][1].to)){
			ans+=g[h][1].w;
			unite(h,g[h][1].to);
			q.push(g[h][1].to);
		}
		bool flag=true;
		for(int i=1;i<=n;i++){
			if(fa[i]!=st) flag=false;
		}
		if(flag==true) {
			return ;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		du[u]++,du[v]++;
	}
	for(int i=1,u;i<=k;i++){
		cin>>u;
		for(int j=1,v;j<=n;j++){
			cin>>v;
			g[j].push_back({i+n,u+v});
			g[i+n].push_back({j,v});
			du[j]++;
		}
	}
	int min=0x3f3f3f3f,st;
	for(int i=1;i<=n;i++){
		if(du[i]<min){
			min=du[i];
			st=i;
		}
	}
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	mst(st);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

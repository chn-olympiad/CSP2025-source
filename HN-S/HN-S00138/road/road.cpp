#include<bits/stdc++.h>
using namespace std;

long long n,m,k,u,v,w,cnt,yuan2,po,n2,tot,ans;
int minn=1e9,p[15][2005],c[2005],yuan,t=-1;
bool P[2005],vis[2005];
int fa[2005];

struct ed{
	int v,w;
};

vector<ed> g[2005];

struct Edge{
	int u,v,w;
};

Edge edge[2000005];

bool cmp(Edge x,Edge y){
	return x.w<y.w;
}

int find(int x){
	return (x==fa[x])?x:fa[x]=find(fa[x]);
}

void dfs(int u){
	vis[u]=1;
	for(ed t:g[u]){
		int v=t.v,w=t.w;
		if(!vis[v]){
			po+=w;
			dfs(v);
		}
	}
}

int ck(){
	for(int i=2;i<=n;i++){
		if(find(i)!=find(i-1)){
			return 0;
		}
	}
	return 1;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		edge[i]={u,v,w};
	}
	if(!k){
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		sort(edge+1,edge+1+m,cmp);
		for(int i=1;i<=n;i++){
			int u=edge[i].u,v=edge[i].v,w=edge[i].w;
			int fu=find(u),fv=find(v);
			if(fu!=fv){
				fa[fu]=fv;
				tot++;
				ans+=w;
				if(tot==n-1){
					cout<<ans;
					return 0;
				}
			}
		}
		return 0;
	}
	n2=n;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>p[i][j];
			edge[++m]={++n2,j,p[i][j]};
		}
	}
	sort(edge+1,edge+1+m,cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	} 
	for(int i=n+1;i<=n2;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u=edge[i].u,v=edge[i].v,w=edge[i].w,fu=find(u),fv=find(v);
		if(fu!=fv){
			fa[fv]=fu;
			ans+=w;
			if(ck()){
				cout<<ans;
				return 0;
			}
		}
	}
	return 0;
}
/*
 4 4 2
 1 4 6
 2 3 7
 4 2 5
 4 3 4
 1 1 8 2 4
 100 1 3 2 4
*/

//GZ-S00065 观山湖区华润中学 刘秦璋 
#include<bits/stdc++.h>
using namespace std;

struct Edge{
	int to,w;
};

int n,m,k;
vector<Edge> edges[10011];
int c[21]={};
int a[21][10011]={};
bool b[10111]={};
int ans=1e9;

void dfs(const int &p,const int &s){
	if(p==1&&b[p]){
		ans=min(ans,s);
		return;
	}
	
	const int l=edges[p].size();
	for(int i=0;i<l;i++){
		if(!b[edges[p][i].to]){
			b[edges[p][i].to]=1;
			dfs(edges[p][i].to,s+edges[p][i].w);
			b[edges[p][i].to]=0;
		}
	}
	
	
	
	
	return;
}

void work(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		edges[u].push_back({v,w});
		edges[v].push_back({u,w});
	}
	
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
		}
	
	dfs(1,0);
	
	printf("%d",ans);
	
	return;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int _=1;
	//scanf("%d",&_);
	//cin>>_
	while(_--)
		work();
	return 0;
} 

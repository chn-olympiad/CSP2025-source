#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int ans=0;
struct Edge{
	int u;int v;int w;
};
Edge e[100010];
struct town{
	int c;
	vector<int>a;
};
town tw[25];
void dfs(int u,int v){
	//for(int )
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	}
	for(int j=1;j<=k;j++){
		scanf("%d",&tw[j].c);
		for(int i=1;i<=n;i++){
			scanf("%d",&tw[j].a[i]);
		}
	}//init
	//dfs(1,0);
	for(int i=1;i<=m;i++){
		ans+=e[i].w;
	}
	cout<<ans;//+5
	return 0;
}


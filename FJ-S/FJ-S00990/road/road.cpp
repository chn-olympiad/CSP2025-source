#include<bits/stdc++.h>
using namespace std;
struct node{
	int v,w;
};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,vis[10005],ans;
	vector<node>ma[10005];
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++)vis[i]=2e9;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		ma[u].push_back({v,w});
		ma[v].push_back({u,w});
	}
	queue<node>q;
	q.push({1,0});
	while(!q.empty()){
		node x=q.front();
		printf("%d %d\n",x.v,x.w);
		q.pop();
		for(int i=0;i<ma[x.v].size();i++){
			if(vis[ma[x.v][i].v]>ma[x.v][i].w+x.w){
				vis[ma[x.v][i].v]=ma[x.v][i].w+x.w;
				q.push({ma[x.v][i].v,ma[x.v][i].w+x.w});
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,vis[i]);
	}
	printf("%d",ans);
	return 0;
}
/*4 4 0
1 4 6
2 3 7
4 2 5
4 3 4*/
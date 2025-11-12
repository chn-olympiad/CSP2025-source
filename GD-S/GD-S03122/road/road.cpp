#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
const int M=1e6+10;
int n,m,k,c[15],dis[15][N],tot,fa[N],ans;
struct node{
	int from,to,val;
}edge[M*3];
bool cmp(node x,node y){
	return x.val<y.val;
}
int find(int x){
	if(x!=fa[x]) fa[x]=find(fa[x]);
	return fa[x];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	ans=0;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		edge[++tot].from=u,edge[tot].to=v,edge[tot].val=w;
	}
	bool flag=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]) flag=0;
		for(int j=1;j<=n;j++) {
			cin>>dis[i][j];
			if(dis[i][j]) flag=0;
		}
	}
	if(flag){
		sort(edge+1,edge+1+tot,cmp);
		for(int i=1;i<=n;i++) fa[i]=i;
		int sum=0;
		for(int i=1;i<=tot;i++){
			if(find(edge[i].from)!=find(edge[i].to ) ){
				fa[fa[edge[i].from]]=fa[edge[i].to];
				ans+=edge[i].val;
				sum++;
			}
			if(sum==n-1) break;
		}
		printf("%lld\n",ans);
	}
	else{
		
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

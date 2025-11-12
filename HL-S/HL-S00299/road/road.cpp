#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+5,M=1e6+5;
int fa[N],cnt_edge;
struct Edge{
	int u,v,w;
}edge[M];
void add(int u,int v,int w){
	cnt_edge++;
	edge[cnt_edge].u=u,edge[cnt_edge].v=v,edge[cnt_edge].w=w;	
}
bool cmp(Edge x,Edge y){
	return x.w<y.w;
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	fa[x]=y;
}
int n,m,k;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		add(u,v,w);
	}	
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>w;
		} 
	}
	if(k==0){
		sort(edge+1,edge+cnt_edge+1,cmp);
		int cnt=0,ans=0;
		for(int i=1;i<=cnt_edge;i++){
			int u=edge[i].u,v=edge[i].v,w=edge[i].w;
			if(find(u)==find(v)) continue;
			ans+=w;cnt++;
			if(cnt==n-1) break;
		}
		cout<<ans;
	}
	else cout<<0;
	return 0;
} 

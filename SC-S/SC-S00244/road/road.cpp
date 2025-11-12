#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5,M=4e6+5;
struct Edge{
	int u,v,w;
}edge[M];
int cnt=1;
int n,m,k;
int a[15][N];
int fa[N];
void init(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
}
int getfa(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=getfa(fa[x]);
}
void merge(int x,int y){
	x=getfa(x),y=getfa(y);
	fa[y]=x;
}
bool cmp(Edge x,Edge y){
	return x.w<y.w;
}
void kruskal(){
	init();
	sort(edge+1,edge+1+cnt,cmp);
//	for(int i=1;i<=cnt;i++){
//		cout<<edge[i].u<<" "<<edge[i].v<<" "<<edge[i].w<<" ";
//	}
	int ans=0;
	for(int i=1;i<=cnt;i++){
		int u=edge[i].u,v=edge[i].v,w=edge[i].w;
//		int fu=getfa(u),fv=getfa(v);
//		cout<<fu<<" "<<fv<<"\n";
		if(getfa(u)!=getfa(v)){
			merge(u,v);
			ans+=w;
		}
	}
	cout<<ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		edge[cnt++]={u,v,w};
		edge[cnt++]={v,u,w};
	}
	cnt--;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(k==0){
		kruskal();
		return 0;
	}
	bool s1=1;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			if(a[i][j]!=0){
				s1=0;
				break;
			}
		}
	}
	if(s1==1){
		cout<<0;
		return 0;
	}
	return 0;
}
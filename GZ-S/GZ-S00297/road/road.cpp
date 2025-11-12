//GZ-S00297 毕节七星关东辰实验学校 洪崇昊
#include<bits/stdc++.h>
using namespace std;
const int N=2e6+1000;
int n,m,k;
struct Way{
	int u,v;
	long long w;
}way[N];
int fa[N];
int find_(int x){
	if(fa[x]==x) return x;
	return fa[x]=find_(fa[x]);
}
int c[100];
int a[100][N];
bool cmp(Way x,Way y){
	return x.w<y.w;
}
long long ans=0;
void kruskal( ){
	int tol=0;
	for(int i=1;i<=m+k*n;i++){
		if(tol==n+k-1) break;
		int fu=find_(way[i].u);
		int fv=find_(way[i].v);
		if(fu!=fv){
			fa[fu]=fv;
			tol++;
			ans+=way[i].w;
		}
	}
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		way[i].u=u;
		way[i].v=v;
		way[i].w=w;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			way[m+n*(i-1)+j].u=m+i;
			way[m+n*(i-1)+j].v=j;
			way[m+n*(i-1)+j].w=c[i]+a[i][j];
		}
	}
	sort(way+1,way+m+k*n+1,cmp);
	for(int i=1;i<=n+k;i++) fa[i]=i;
	kruskal( );
	cout<<ans;
	return 0;
}

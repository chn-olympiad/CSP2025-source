#include<bits/stdc++.h>
using namespace std;
int n,m,k,head[10010],cnt,c[13][10010],ans;
struct edge{
	int to,next,w,f;
}e[2000010];
void add(int u,int v,int w){
	e[++cnt].to=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w),add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%d",&c[i][j]);
		}
	}
	sort(e+1,e+1+2*m,cmp);
	for(int i=1;i<2*(n-1);i+=2) ans+=e[i].w;
	printf("%d",ans);
	return 0;
}

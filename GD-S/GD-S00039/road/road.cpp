#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int f[10005],c[15],a[15][10005];
int head[10005],nxt[1000005],cnt;
struct tni{
	int x,val;
}to[1000005];
struct E{
	int u,v,w;
}e[1000005];
bool cmp(E x,E y){
	return x.w<y.w;
}
int fr(int x){
	if(f[x]!=x) f[x]=fr(f[x]);
	return f[x];
}
void add(int u,int v,int w){
	nxt[++cnt]=head[u];
	head[u]=cnt;
	to[cnt]={v,w};
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(head,-1,sizeof(head));
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	}
	stable_sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(fr(e[i].u)!=fr(e[i].v)){
			f[fr(e[i].u)]=fr(e[i].v);
			add(e[i].u,e[i].v,e[i].w);
			add(e[i].v,e[i].u,e[i].w);
			ans+=e[i].w;
		}
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	printf("%d",ans);
	return 0;
}

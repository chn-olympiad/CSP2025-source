#include<bits/stdc++.h>
using namespace std;
int n,m,r,i,j;
long long ans;
struct edge{
	int u,v;
	long long w;
};
edge k[1000005];
edge c[15][20005];
struct countryside{
	long long cst;
	edge len[10005];
}d[15];
bool cmp(edge o,edge p){
	return o.w<p.w;
}
int l[15];
int fa[20005];
int f(int u){
	if(fa[u]==u) return u;
	return fa[u]=f(fa[u]);
}
void dfs(int lst,int now,long long ss){
	if(now==r+1){
		return;
	}
	int z1=1,z2=1;
	long long sz=0;
	l[now]=0;
	for(int i=1;i<=n+r;i++){
		fa[i]=i;
	}
	while(z1<=l[lst]||z2<=n){
		if(z1<=l[lst]&&(z2==n+1||c[lst][z1].w<d[now].len[z2].w)){
			int fa1=f(c[lst][z1].u),fa2=f(c[lst][z1].v);
			if(fa1!=fa2){
				fa[fa1]=fa2;
				sz+=c[lst][z1].w;
				c[now][++l[now]]=c[lst][z1];
			}
			z1++;
		}else{
			int fa1=f(d[now].len[z2].u),fa2=f(d[now].len[z2].v);
			if(fa1!=fa2){
				fa[fa1]=fa2;
				sz+=d[now].len[z2].w;
				c[now][++l[now]]=d[now].len[z2];
			}
			z2++;
		}
	}
	ans=min(ans,sz+ss+d[now].cst);
	dfs(now,now+1,ss+d[now].cst);
	l[now]=0;
	dfs(lst,now+1,ss);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&r);
	for(i=1;i<=m;i++){
		scanf("%d%d%lld",&k[i].u,&k[i].v,&k[i].w);
	}
	sort(k+1,k+m+1,cmp);
	for(i=1;i<=n;i++) fa[i]=i;
	for(i=1;i<=m;i++){
		int fa1=f(k[i].u),fa2=f(k[i].v);
		if(fa1!=fa2){
			fa[fa1]=fa2;
			ans+=k[i].w;
			c[0][++l[0]]=k[i];
		}
	}
	for(i=1;i<=r;i++){
		scanf("%lld",&d[i].cst);
		for(j=1;j<=n;j++){
			scanf("%lld",&d[i].len[j].w);
			d[i].len[j].u=n+i;
			d[i].len[j].v=j;
		}
		sort(d[i].len+1,d[i].len+n+1,cmp);
	}
	dfs(0,1,0);
	printf("%lld\n",ans);
	return 0;
}

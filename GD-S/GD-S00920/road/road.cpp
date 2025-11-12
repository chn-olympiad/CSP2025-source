#include<bits/stdc++.h>
using namespace std;
const int N=10005,M=1000005;
struct edge{int u,v,w;}e[M<<1],te[M<<1];
bool cmp(edge a,edge b){return a.w<b.w;}
int es,tes,n,m,k,c[15][N],f[N],z=0x3f3f3f3f;
void add(int u,int v,int w){
	e[++es].u=u,e[es].v=v,e[es].w=w;
}
void tadd(int u,int v,int w){
	te[++tes].u=u,te[tes].v=v,te[tes].w=w;
}
int root(int x){
	return f[x]==x?x:f[x]=root(f[x]);
}
int csh(int x){
	int s=0;
	for(int wi=1,i=1;wi<=x;wi<<=1,i++){
		if(x&wi){
			s+=c[i][0];
			for(int j=1;j<=n;j++){
				tadd(n+1,j,c[i][j]);
			}
		}
	}return s;
}
int kj(){
	int s=0;
	for(int i=1;i<=n+1;i++)f[i]=i;
	sort(te+1,te+1+tes,cmp);
	for(int i=1;i<=tes;i++){
		int x=root(e[i].u),y=root(e[i].v);
		if(x==y)continue;
		f[x]=n+1,f[y]=n+1;s+=e[i].w;
	}return s;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i][0]);
		for(int j=1;j<=n;j++)scanf("%d",&c[i][j]);
	}
	int s=0;
	for(int i=1;i<=n+1;i++)f[i]=i;
	sort(e+1,e+1+es,cmp);
	for(int i=1;i<=es;i++){
		int x=root(e[i].u),y=root(e[i].v);
		if(x==y)continue;
		f[x]=y;s+=e[i].w;
	}return cout<<s,0;
	for(int i=0,wk=1<<k;i<wk;i++){
		memcpy(te,e,sizeof(e)),tes=es;
		z=min(z,csh(i)+kj());
	}
	printf("%d",z);
	return 0;
}

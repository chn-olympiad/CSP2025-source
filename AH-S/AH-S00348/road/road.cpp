#include<stdio.h>
#include<algorithm>
#define MAXN 10100
#define MAXM 1200005
using namespace std;
struct road{
	int u;
	int v;
	int w;
	
}a[MAXM];
bool cmp(road x,road y){
	return x.w<y.w;
}
int f[MAXN];
int findfa(int i){
	if(f[i]==i)return i;
	return findfa(f[i]);
}
int d[13][MAXN];
int c[13];
bool jk[13][MAXN];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d %d %d",&a[i].u,&a[i].v,&a[i].w);
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&d[i][j]);
			a[++m].u=i,a[m].v=j,a[m].w=d[i][j];
		}
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=n+k;i++)
		f[i]=i;
	int ans=0;
	for(int i=1;i<=m;i++){
		int uf=findfa(a[i].u),vf=findfa(a[i].v);
		if(uf!=vf){
			f[uf]=vf;
			ans+=a[i].w;
		}
		printf("%d\n",ans);
	}
	printf("%d\n",ans);
	
	return 0;
}

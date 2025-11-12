#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k,f[10005],c[10],a[12][10005];
long long ans;
struct E{
	int u,v,w;
	bool operator < (const E x)const{
		return w<x.w;
	}
}e[1200005];
int find(int k){
	if(k==f[k])return k;
	return f[k]=find(f[k]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
	for(int i=1,j;i<=k;i++){
		scanf("%d",&c[i]);
		for(j=1;j<=n;j++)scanf("%d",&a[i][j]);
		if(c[i]==0){
			for(j=1;j<=n;j++)if(a[i][j]==0)break;
			for(int l=1;l<=n;l++){
				e[++m].u=j;
				e[m].v=l;
				e[m].w=a[i][l];
			}
		}
	}
	for(int i=1;i<=n;i++)f[i]=i;
	sort(e+1,e+m+1);
	int lt=0;
	for(int i=1;i<=m && lt<n-1;i++)
		if(find(e[i].u)!=find(e[i].v)){
		    lt++;
		    ans+=e[i].w;
		    f[find(e[i].u)]=f[find(e[i].v)];
	}
	printf("%lld",ans);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int c[11],b[11][10001];
struct bian{
	int u,v,w;
}a[1000001],ac[10001];
bool cmp(bian x,bian y){
	return x.w>y.w;
}
int f[10001],cnt;
int find(int x){
	if(x!=f[x])f[x]=find(f[x]);
	return f[x];
}
bool bj=true;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	register int n,m,k,i,j,ans=0;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=m;++i)
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	for(i=1;i<=k;++i){
		scanf("%d",&c[i]);
		if(c[i])bj=false;
		for(j=1;j<=n;++j)
			scanf("%d",&b[i][j]);
	}
	for(i=1;i<=n;++i)
		f[i]=i;
	if(k==0){
		sort(a+1,a+m+1,cmp);
		for(i=1;i<n;++i){
			while(find(a[m].u)==find(a[m].v))--m;
			ans+=a[m].w,f[f[a[m].u]]=f[a[m].v],--m;
		}
		printf("%d",ans);
		return 0;
	}
	if(bj){
		for(i=1;i<=m;++i)
			for(j=1;j<=k;++j)
				a[i].w=min(a[i].w,b[j][a[i].v]+b[j][a[i].u]);
		sort(a+1,a+m+1,cmp);
		for(i=1;i<n;++i){
			while(find(a[m].u)==find(a[m].v))--m;
			ac[++cnt]=a[m],ans+=a[m].w,f[f[a[m].u]]=f[a[m].v],--m;
		}
		for(i=1;i<=cnt;++i){
			int minn=INT_MAX;
			for(j=1;j<=k;++j)
				minn=min(minn,b[j][ac[i].u]+b[j][ac[i].v]);
			if(minn<ac[i].w)ans-=ac[i].w-minn;
		}
		printf("%d",ans);
	}
	return 0;
}

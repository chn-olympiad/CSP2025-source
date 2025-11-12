#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
int n,m,k,u,v,w,minn,s,ans;
int fa[10005],c[15],a[15][10005];
struct node{
	int u,v,w;
}e[1000005];
bool cmp(node x,node y){
	return x.w<y.w;
}
int finds(int x){
	if(x==fa[x])return fa[x];
	return fa[x]=finds(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i,j;
	cin>>n>>m>>k;
	for(i=1;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		e[i]=node{u,v,w};
	}
	minn=1e18;
	for(i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		s=c[i];
		for(j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
			s+=a[i][j];
		}
		minn=min(minn,s);
	}
	if(minn==0){
		cout<<0;
		return 0;
	}
	for(i=1;i<=n;i++)fa[i]=i;
	sort(e+1,e+m+1,cmp);
	for(i=1;i<=m;i++){
		int nu=finds(e[i].u);
		int nv=finds(e[i].v);
		if(nu!=nv){
			fa[nv]=nu;
			ans+=e[i].w;
			s++;
			if(s==n-1)break;
		}
	}
	printf("%lld",min(minn,ans));
}

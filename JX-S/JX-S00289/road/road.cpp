#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans,cnt,fa[10005],c[15],a[15][10005];
struct node{
	long long u,v,w;
}e[1000005];
bool cmp(node a,node b){
	if(a.w==b.w)return a.u<b.u;
	return a.w<b.w;
}
int find(int x){
	if(fa[x]!=x)return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=1;i<=n;i++)fa[i]=i;
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
	sort(e+1,e+1+n,cmp);
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	for(int i=1;i<=m;i++){
		int p=find(e[i].u),q=find(e[i].v);
		if(p==q)continue;
		ans+=e[i].w;
		cnt++;
		fa[p]=q;
		if(cnt==n-1)break;
	}
	printf("%lld",ans);
	return 0;
}

//1-4+A 48
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,f[10010],cnt,ans,w[10010];
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
struct E{
	int u,v,w;
}a[6000010];
int l;
bool cmp(E x,E y){
	return x.w<y.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
		scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
	l=m;
	for(int i=1;i<=k;i++){
		int x;
		scanf("%lld",&x);
		for(int j=1;j<=n;j++){
			scanf("%lld",&w[j]);
			if(w[j]==0) x=j;
		}
		for(int j=1;j<=n;j++){
			if(j==x) continue;
			a[++l]=(E){x,j,w[j]};
		}
	}
	sort(a+1,a+l+1,cmp);
	for(int i=1;i<=l;i++){
		int u=a[i].u,v=a[i].v,w=a[i].w;
		int fu=find(u),fv=find(v);
		if(fu==fv) continue;
		f[fu]=fv;
		ans+=w;
		if((++cnt)==n-1){
			printf("%lld",ans);
			return 0;
		}
	}
	return 0;
}

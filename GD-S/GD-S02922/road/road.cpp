#include "bits/stdc++.h"
using namespace std;
#define int long long
int n,m,k,ans=1e18;
int c[11],w[11],f[10011];
struct node{
	int u,v,w;
}a[10000001];
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]),f[x];
}
void dg(int x){
	if(x>k){
		int res=0,cntt=n-1;
		for(int i=1;i<=n+k;i++) f[i]=i;
		for(int i=1;i<=k;i++) res+=w[i]*c[i],cntt+=w[i];
		if(res>=ans) return;
		for(int i=1;i<=m;i++)
			if(!(a[i].u>n && !w[a[i].u-n])){
				int p1=find(a[i].u),p2=find(a[i].v);
				if(p1==p2) continue;
				f[p1]=p2,res+=a[i].w,cntt--;
				if(res>=ans) return;
				if(!cntt) break;
			}
		if(cntt) return;
		return void(ans=min(ans,res));
	}
	w[x]=0;
	dg(x+1);
	w[x]=1;
	dg(x+1);
}
signed main(void){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++) m++,a[m].u=i+n,a[m].v=j,scanf("%lld",&a[m].w);
	}
	stable_sort(a+1,a+m+1,[](node x,node y){
		return x.w<y.w;
	});
	dg(1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}

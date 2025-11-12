#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10,M=3e6+10;
struct sgs{
	int u,v,w,ji;
}a[M];
int t,n,m,k,f[N],p[N],qw,maxn;
long long ans;
bool cmp(sgs a,sgs b){
	return a.w<b.w;
}
int fa(int x){
	if(f[x]==x) return x;
	return f[x]=fa(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n+k;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
		maxn=(maxn,a[i].w);
	}
	for(int j=1;j<=k;j++){
		scanf("%d",&t);
		int minn=INT_MAX,sg;
		for(int i=1;i<=n;i++){
			scanf("%d",&p[i]);
			if(p[i]<minn){
				minn=p[i];
				sg=i;
			}
		}
		if(maxn<=t+p[sg]) continue;
		for(int i=1;i<=n;i++){
			a[m+i].u=n+j;
			a[m+i].v=i;
			a[m+i].w=p[i];
		}
		a[m+sg].w=p[sg]+t;
		m+=n;
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++){
		if(f[fa(a[i].u)]!=fa(a[i].v)){
			f[fa(a[i].u)]=fa(a[i].v);
			ans+=a[i].w;
		}
	}
	printf("%lld",ans);
	return 0;
}

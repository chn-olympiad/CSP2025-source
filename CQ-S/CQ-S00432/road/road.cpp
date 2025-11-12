#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
struct node {int u,v,w;}v[2000005];
int c[15],cnt;
inline bool cmp(node p,node q){return p.w<q.w;}
int f[2000005];
inline int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
int ans;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)scanf("%lld%lld%lld",&v[i].u,&v[i].v,&v[i].w);cnt=m;
	int cnt2=n;
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		if(!c[i])cnt2++;
		for(int j=1;j<=n;j++){
			int x;cin>>x;
			if(!c[i])v[++cnt].u=cnt2,v[cnt].v=j,v[cnt].w=x;
		}
	}
	sort(v+1,v+1+cnt,cmp);
	int s=0;
	for(int i=1;i<=n+cnt-m;i++)f[i]=i;
	for(int i=1;i<=cnt;i++){
		if(f[find(v[i].u)]!=f[find(v[i].v)])ans+=v[i].w,s++,f[find(v[i].u)]=f[find(v[i].v)];
		if(s==n+cnt-m)break;
	}
	printf("%lld",ans);
	return 0;
}

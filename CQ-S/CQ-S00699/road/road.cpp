#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+15;
int n,m,k,f[N],cnt;
ll c[N],a[11][N],ans;
struct edge {
	int u,v;
	ll w;
} e[N*100],ee[N*11];
inline bool cmp(edge x,edge y) {
	return x.w<y.w ;
}
inline int find(int x) {
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) {
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++) {
		if(find(e[i].u)!=find(e[i].v)) {
			ee[++cnt]=e[i];
			ans+=e[i].w;
			f[find(e[i].u)]=find(e[i].v);
		}
	}
	for(int i=1;i<=k;i++) {
		cin>>c[i];
		for(int j=1;j<=n;j++) {
			cin>>a[i][j];
			ee[++cnt]={n+i,j,a[i][j]};
		}
	}
	sort(ee+1,ee+cnt+1,cmp);
	for(int p=1;p<(1<<k);p++) {
		ll sum=0;
		for(int i=1;i<=k;i++) if((p>>(i-1))&1) {
			sum+=c[i];
		}
		for(int i=1;i<=n+k;i++) f[i]=i;
		for(int i=1;i<=cnt;i++) {
			if(ee[i].u>n&&((p>>(ee[i].u-n-1))&1)==0) continue ;
			if(ee[i].v>n&&((p>>(ee[i].v-n-1))&1)==0) continue ;
			if(find(ee[i].u)!=find(ee[i].v)) {
				sum+=ee[i].w;
				f[find(ee[i].u)]=find(ee[i].v) ;
			}
		}
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}
/*
2e9能跑过去我吃一斤啊 
*/

#include<bits/stdc++.h>
using namespace std;
struct node{int u,v,w;}g[1000005];
inline bool cmp(const node& a,const node& b){return a.w<b.w;};
int n,m,k;
long long ans;
int par[10005];
int find(const int& x){return par[x]=par[x]==x?x:find(par[x]);}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&g[i].u,&g[i].v,&g[i].w);
	for(int i=1;i<=n;i++) par[i]=i;
	sort(g+1,g+m+1,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(cnt==n-1) break;
		int ru=find(g[i].u),rv=find(g[i].v);
		if(ru!=rv)
			ru=rv,ans+=g[i].w,cnt++;
	}
	printf("%lld",ans);
	return 0;
}

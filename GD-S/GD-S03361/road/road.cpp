#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+25,M=1e6+5;
int n,m,k,tote,l,r,totv,fx,fy,cnte,res,ans=1e18;
int fa[N],c[15],mp[15][N];
struct edge{
	int u,v,w;
}e[M],ee[M];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1; i<=m; i++) scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
	sort(e+1,e+1+m,cmp);
	for(int i=1; i<=k; i++){
		scanf("%lld",&c[i]);
		for(int j=1; j<=n; j++) scanf("%lld",&mp[i][j]);
	}
	for(int st=0; st<(1<<k); st++){
		tote=res=0,totv=n;
		for(int i=0; i<k; i++){
			if(st>>i&1){
				totv++,res+=c[i+1];
				for(int j=1; j<=n; j++){
					ee[++tote].u=n+i+1;
					ee[tote].v=j;
					ee[tote].w=mp[i+1][j];
				}
			}
		}
		sort(ee+1,ee+1+tote,cmp);
		for(int i=1; i<=n+k; i++) fa[i]=i;
		l=1,r=1,cnte=0;
		while(1){
			if(r>tote || (l<=m && e[l].w<=ee[r].w)){
				fx=find(e[l].u),fy=find(e[l].v);
				if(fx!=fy){
					fa[fx]=fy;
					cnte++;
					res+=e[l].w;
				} 
				l++;
			}
			else if(l>m || (r<=tote && ee[r].w<=e[l].w)){
				fx=find(ee[r].u),fy=find(ee[r].v);
				if(fx!=fy){
					fa[fx]=fy;
					cnte++;
					res+=ee[r].w;
				}
				r++;
			}
			if(res>=ans) break;
			if(cnte==totv-1){
				ans=min(ans,res);
				break;
			} 
		}
	}
	printf("%lld\n",ans);
	return 0;
}

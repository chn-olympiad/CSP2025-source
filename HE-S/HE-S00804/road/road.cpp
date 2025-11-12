#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e4+10,M=1e6+10;
const ll INF=1e18;
int n,m,K;
int tot;
struct Edge {
	int u,v,w;
} E[M],B[M];
int c[11],a[11][N];
int fa[N];
ll sum;
ll ans=INF;

inline bool cmp(Edge a,Edge b) {
	return a.w<b.w ;
}

inline int find(int x) {
	return fa[x]==x ? x : fa[x]=find(fa[x]) ;
}

inline ll Kruskal() {
	ll s=0;
	for(int i=1;i<=n+K;i++) fa[i]=i;
	sort(B+1,B+1+tot,cmp);
	int p1=1,p2=1;
	while(p1<=m && p2<=tot){
		int V=min(E[p1].w,B[p2].w);
		int u,v,w;
		if(V==E[p1].w){
			u=E[p1].u,v=E[p1].v,w=E[p1].w; p1++;
		}
		else {
			u=B[p2].u,v=B[p2].v,w=B[p2].w; p2++;
		}
		int x=find(u),y=find(v);
		if(x==y) continue;
		fa[x]=y;
		s+=w;
		if(sum+s>ans) return ans+1;
	}
	while(p1<=m){
		int u=E[p1].u,v=E[p1].v,w=E[p1].w; p1++;
		int x=find(u),y=find(v);
		if(x==y) continue;
		fa[x]=y;
		s+=w;
		if(sum+s>ans) return ans+1;
	}
	while(p2<=tot){
		int u=B[p2].u,v=B[p2].v,w=B[p2].w; p2++;
		int x=find(u),y=find(v);
		if(x==y) continue;
		fa[x]=y;
		s+=w;
		if(sum+s>ans) return ans+1;
	}
	return s;
}

signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1; i<=m; i++) scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].w);
	for(int i=1;i<=K;i++) {
		scanf("%d",&c[i]);
		for(int j=1; j<=n; j++) scanf("%d",&a[i][j]);
	}
	int F=1;
	for(int i=1;i<=n;i++){
		if(c[i]) F=0;
	}
	sort(E+1,E+1+m,cmp);
	//cerr<<clock()*1.0/CLOCKS_PER_SEC<<endl;
	int be=0;
	if(F) be=(1<<K)-1;
	for(int i=be; i<(1<<K); i++) {
		//cerr<<i<<endl;
		tot=0; sum=0;
		int x=i;
		for(int j=1; j<=K; j++,x>>=1) {
			if(x&1) {
				sum+=c[j];
				for(int k=1; k<=n; k++) B[++tot]= {n+j,k,a[j][k]};
			}
		}
		if(sum<ans) ans=min(ans,sum+Kruskal());
	}
	cout<<ans<<endl;
	//cerr<<clock()*1.0/CLOCKS_PER_SEC<<endl;
	return 0;
}

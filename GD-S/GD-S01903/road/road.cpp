#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5,K=15;
#define int long long
int inf=114514191981010056;
int n,m,k,c[K];
int ans=inf;
int ct,fa[N+K];
bool vis[N+K];
struct edg {
	int u,v,w;
}e[M],us[M]; 
bool cmp(edg a,edg b) { return a.w<b.w;}
int find(int x) {
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void kruskal() {
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) {
		int x=find(e[i].u),y=find(e[i].v);
		if(x==y) continue;
		fa[x]=y;
		us[++ct]=e[i];
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	freopen("A.txt","r",stdin);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) vis[i]=1;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+1+m,cmp);
//	for(int i=1;i<=m;i++) us[++ct]=e[i];
	kruskal();
	for(int i=1;i<=k;i++) {
		cin>>c[i];
		for(int j=1;j<=n;j++) {
			int w; cin>>w;
			us[++ct]=edg{n+i,j,w};
		}
	}
	sort(us+1,us+1+ct,cmp);
	
	for(int i=0;i<(1<<k);i++) {
		int az=n,tot=0;
		for(int j=0;j<k;j++) {
			if(i&(1<<j)) {
				vis[n+j+1]=1;
				tot=tot+c[j+1];
				az++;
			} else vis[n+j+1]=0;
		}
		
		for(int j=1;j<=n+k;j++) fa[j]=j;
		for(int j=1;j<=ct;j++) {
			int u=us[j].u,v=us[j].v,w=us[j].w;
			if(!vis[u]) continue;
			int x=find(u),y=find(v);
			if(x==y) continue;
			fa[x]=y;
			tot=tot+w;
			az--;
		}
		ans=min(ans,tot);
	}
	cout<<ans;
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/

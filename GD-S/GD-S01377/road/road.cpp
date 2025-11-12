#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+5,M=1e6+5;
struct edge {
	int u,v,w;
	bool operator < (const edge &b) const {return w<b.w;}
} e[M];
int n,m,k,f[N],c[15],a[15][N],b[15],siz[N],ans=1e18;
int find(int x) {
	if(f[x]==x) return f[x];
	return f[x]=find(f[x]);
} 
bool cmp(edge a,edge b) {
	return a.w<b.w;
}
vector<edge> g;
int work() {
	int res=0;
	for(int i=1;i<=n;i++) f[i]=i,siz[i]=1;
	for(int i=1;i<=k;i++) f[n+i]=n+i,siz[n+i]=0;
	for(int i=1;i<=k;i++) {
		if(b[i]) res+=c[i];
	}
	for(int i=0;i<g.size();i++) {
		edge t=g[i];
		if(t.u>n&&!b[t.u-n]) continue;
		int fu=find(t.u),fv=find(t.v),w=t.w;
		if(fu==fv) continue;
		f[fv]=fu; res+=w; 
		if(res>ans) return 1e18;
		siz[fu]+=siz[fv],siz[fv]=0;
		if(siz[fu]==n) break;
	}
	return res;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++) {
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	for(int i=1;i<=m;i++) g.push_back(e[i]);
	for(int i=1;i<=k;i++) 
		for(int j=1;j<=n;j++) g.push_back((edge){n+i,j,a[i][j]});
	sort(g.begin(),g.end(),cmp);
	for(int S=0;S<(1<<k);S++) {
		for(int i=0;i<k;i++) 
			if(S&(1<<i)) b[i+1]=true;	
			else b[i+1]=false;
		ans=min(ans,work());
	}
	cout<<ans;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=1e6+5;
struct Edge {
	int u,v,w;
	inline friend bool operator <(const Edge &x,const Edge &y) {
		return x.w<y.w;
	}
}	a[MAXN],b[MAXN];
int n,m,k,q,dsu[MAXN],vl[MAXN];
int find(int x) { return dsu[x]!=x?dsu[x]=find(dsu[x]):x; }
ll ans=0;
void qry(int s) {
	ll z=0;
	for(int i=0;i<k;++i) if(s>>i&1) z+=vl[i];
	iota(dsu+1,dsu+n+k+1,1);
	for(int i=1;i<=q&&z<ans;++i) if(b[i].v<=n||(s>>(b[i].v-n-1)&1)) {
		int u=find(b[i].u),v=find(b[i].v);
		if(u!=v) dsu[u]=v,z+=b[i].w;
	}
	ans=min(ans,z);
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i) cin>>a[i].u>>a[i].v>>a[i].w;
	for(int j=1;j<=k;++j) {
		cin>>vl[j-1];
		for(int i=1,z;i<=n;++i) cin>>z,b[++q]={i,j+n,z};
	}
	sort(a+1,a+m+1);
	iota(dsu+1,dsu+n+k+1,1);
	for(int i=1;i<=m;++i) {
		int u=find(a[i].u),v=find(a[i].v);
		if(u!=v) dsu[u]=v,b[++q]=a[i],ans+=a[i].w;
	}
	sort(b+1,b+q+1);
	for(int s=1;s<(1<<k);++s) qry(s);
	cout<<ans<<"\n";
	return 0;
}


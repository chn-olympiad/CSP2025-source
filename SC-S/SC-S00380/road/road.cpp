#include<bits/stdc++.h>
using namespace std;
const int N=1e4+15,M=2e6+5;
#define int long long
struct edge {
	int u,v,w;
	bool operator<(edge b)const& {
		return w<b.w;
	}
} e[M];
int n,m,k,cnt;
int c[15][N],w[15];
int f[N];
int getfa(int x) {
	return x==f[x]?x:f[x]=getfa(f[x]);
}
int ans=0;
void kru() {
	sort(e+1,e+m+1);
	for(int i=1; i<=m; i++) {
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int fu=getfa(u),fv=getfa(v);
		if(fu==fv)continue;
		f[fu]=fv;
		ans+=w;
//		cout<<u<<" "<<v<<' '<<w<<'\n';
	}
}
main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		int u,v,w;
		cin>>u>>v>>w;
		e[++cnt]= {u,v,w};
	}
	for(int i=1; i<=n+k; i++)f[i]=i;
	if(k==0) {
		kru();
		cout<<ans;
		return 0;
	}
	for(int i=1; i<=k; i++) {
		cin>>w[i];
		for(int j=1; j<=n; j++) {
			cin>>c[i][j];
			e[++m]= {i+n,j,c[i][j]};
		}
	}
	kru();
	cout<<ans;
	return 0;
}
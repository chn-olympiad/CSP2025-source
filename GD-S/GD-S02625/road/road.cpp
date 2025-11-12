#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct Edge {
	int u,v,w;
	friend bool operator <(Edge a,Edge b) {
		return a.w<b.w;
	}
} edges[10000010];
int f[10010],c[11],a[11][10100];
int find(int x) {
	return f[x] = (f[x]==x?x:find(f[x]));
}
bool made[11];
long long ans;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1; i<=n; i++) f[i]=i;
	for(int i = 1; i<=m; i++)
		cin>>edges[i].u>>edges[i].v>>edges[i].w;
	for(int i = 1; i<=k; i++) {
		cin>>c[i];
		for(int j=1; j<=n; j++)
			cin>>a[i][j];
	}
	for(int i = 1; i<=m; i++)
		for(int j = 1; j<=k; j++)
			edges[i].w=min(edges[i].w,c[j]+a[j][edges[i].u]+a[j][edges[i].v]);


	sort(edges+1,edges+m+1);
	for(int i = 1; i<=m; i++) {
		int u=edges[i].u,v=edges[i].v,w=edges[i].w;
		if(find(u)!=find(v)) {
			ans+=w;
			f[find(u)]=find(v);
		}
	}
	cout<<ans;
	return 0;
}


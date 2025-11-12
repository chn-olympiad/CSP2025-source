#include <bits/stdc++.h>
#define int long long
constexpr int maxn=10010, maxm=2000010;
using namespace std;
struct edge{
	int u, v, w;
}E[maxm];
int fa[maxn], n, m, k, a[12][maxn], c[12], ans=0, b[12], tmp;
bool flag=true;
int findfa(int u){
	while (u!=fa[u]) u=fa[u]=fa[fa[u]];
	return u;
}
bool cmp(edge a, edge b){
	return a.w<b.w;
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for (int i=1; i<=m; i++){
		cin>>E[i].u>>E[i].v>>E[i].w;
	}
	
	for (int i=1; i<=n; i++){
		fa[i]=i;
	}
	for (int i=1; i<=k; i++){
		cin>>c[i];
		if (c[i]) flag=false;
		for (int j=1; j<=n; j++){
			cin>>a[i][j];
			if (a[i][j]==0) b[i]=j;
		}
	}
	tmp=m;
	if (flag){
		for (int i=1; i<=k; i++){
			for (int j=1; j<=n; j++){
				if (j==b[i]) continue;
				E[++tmp].u=b[i];
				E[tmp].v=j;
				E[tmp].w=a[i][j];
			}
		}
	}
	sort(E+1, E+tmp+1, cmp);
	for (int i=1; i<=tmp; i++){
		int u=findfa(E[i].u), v=findfa(E[i].v);
		if (u!=v){
			fa[u]=v;
			ans+=E[i].w;
		}
	}
	cout<<ans<<"\n";
	return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5,M=1e6+5;
int n,m,k,ans;
int fa[N],c[15],a[15][N];
struct Node {
	int u,v,w;
} e[M];
void init() {
	for(int i=1; i<=N-5; i++)fa[i]=i;
}
int findd(int x) {
	if(x!=fa[x])fa[x]=findd(fa[x]);
	return fa[x];
}
void bing(int x,int y) {
	int a=findd(x),b=findd(y);
	fa[x]=y;
}
bool cmp(Node a,Node b) {
	return a.w<b.w;
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	init();
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		for(int j=1; j<=n; j++) {
			cin>>a[i][j];
			if(c[i]==0) {
				if(a[i][j]==0)bing(n+i,j);
			}
		}
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1; i<=m; i++) {
		int u=findd(e[i].u),v=findd(e[i].v);
		if(u==v)continue;
		fa[u]=v;
		ans+=e[i].w;
	}
	cout<<ans;
	return 0;
}

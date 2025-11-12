#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,p;
const int M = 1e7+5,N = 1e4 + 5,Nm = 1e3 + 5;
int fa[N],wx[N],eval[Nm][Nm];
struct Edge{
	int u,v,w;
}e[M];
int _find(int x) {
	return (x==fa[x])?fa[x]:fa[x]=_find(fa[x]);
}
bool mg(int x,int y) {
	x = _find(x),y = _find(y);
	if(x==y) return 0;
	fa[x] = y;return 1;
}
bool cmp(Edge x,Edge y) {
	return x.w < y.w;
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m >> k ;
	// int t1 = clock();
	memset(eval,0x3f,sizeof(eval));
	for(int i=1;i<=n;i++) fa[i] = i;
	for(int i=1;i<=m;i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	int cnt = m;
	for(int i=1;i<=k;i++) {
		cin >> p;
		for(int j=1;j<=n;j++) {
			cin >> wx[j];
		}
		for(int j=1;j<=n;j++) {
			for(int jx=j+1;jx<=n;jx++) {
				eval[j][jx] = eval[jx][j] = min(eval[j][jx],wx[j]+wx[jx]+p);
			}
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=2;j<=n;j++) e[++cnt] = Edge{i,j,eval[i][j]};
	}
	sort(e+1,e+cnt+1,cmp);
	int ccnt = 0,tot = 0;
	for(int i=1;i<=cnt;i++) {
		if(mg(e[i].u,e[i].v)) ccnt++,tot += e[i].w;
		// cout << "add:" << e[i].u << "~" << e[i].v << " cost = " << e[i].w << "\n";
		if(ccnt==n-1)break;
	}
	// int t2 = clock();
	cout << tot << "\n";
	// cout << t1 << " " << t2 << " " << t2 - t1 << "\n";
	return 0;
}
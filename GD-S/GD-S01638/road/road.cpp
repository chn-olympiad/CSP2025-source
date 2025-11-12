#include<bits/stdc++.h>
using namespace std;
constexpr int N = 1e4+50;
#define int long long
int n,m,k;
struct Node{
	int x,y,v;
}a[N*200];

int fa[N];
int f[N][15];
int vis[N][15];
int find(int x) {
	if (fa[x] == x) {
		return x;
	}
	else {
		fa[x] = find(fa[x]);
		for (int i=1;i<=k;i++) f[fa[x]][i] = min(f[fa[x]][i], f[x][i]), vis[fa[x]][i] |= vis[x][i];
		return fa[x];
	}
//	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int val[15];
int visk[15];

int dis(int k,int X) {
	if (vis[X][k]) return 0;
	return f[X][k];
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++) {
		cin>>a[i].x>>a[i].y>>a[i].v;
	}
	sort(a+1,a+m+1,[](Node A, Node B) {
		return A.v < B.v;
	});
	
	int SubA=1;
	for (int i=1;i<=k;i++) {
		cin>>val[i];
		if (val[i] != 0) SubA = 0;
		int Z = 0;
		for (int j=1;j<=n;j++) {
			int x;cin>>x;
			if (x == 0) Z = 1;
			f[j][i] = x;
		}
		if (Z == 0) SubA = 0;
	}
	
	int res = 0,cnt=0;
	if (SubA) {
//		cout << "SubA" << endl;
		for (int i=n+1;i<=n+k;i++) {
			for (int j=1;j<=n;j++) {
				a[++m] = {i,j,f[j][i-n]};
			}
		}
		sort(a+1,a+m+1,[](Node A, Node B) {
			return A.v < B.v;
		});
		int _n = n+k;
		iota(fa,fa+_n+1,0);
		for (int i=1;i<=m;i++) {
			int x = a[i].x, y = a[i].y, v = a[i].v;
			int fx = find(x), fy = find(y);
			if (fx != fy) {
				res += v;
				cnt++;
				fa[fx] = fy;
			}
			if (cnt == n-1) continue;
		}
		for (int i=1;i<=k;i++) res += val[i];
	}
	else {
		iota(fa,fa+n+1,0);
		for (int i=1;i<=m;i++) {
			int x = a[i].x, y = a[i].y, v = a[i].v;
			int fx = find(x), fy = find(y);
			if (fx != fy) {
				int mi = 1e18,wh=0;
				for (int j=1;j<=k;j++) {
					int d = dis(j,fx) + dis(j,fy);
					if (visk[j] == 0) d += val[j];
					if (mi > d) mi = d, wh = j;
				}
				if (mi <= v) {
					res += mi;
					visk[wh]=1;
					vis[fy][wh] = 1;
	//				cout <<"MD1:" << mi << endl;
				}
				else {
					res += v;
	//				cout <<"MD2:" << v << endl;
				}
				cnt++;
				fa[fx] = fy;
			}
			if (cnt == n-1) continue;
		}
	}
	cout << res;
	return 0;
} 

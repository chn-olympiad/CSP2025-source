#include <bits/stdc++.h>
using namespace std;

struct Edge{int u,v;long long w;}e[2000005];
int n,m,k,fa[10005],cnt;
long long ans;
bool cmp(Edge x,Edge y) {return x.w < y.w;}
int find(int x) {
	if (fa[x] == x) return x;
	int p = find(fa[x]);
	fa[x] = p;
	return p;
}
void merge(int x,int y) {fa[y] = x;}

int main() {
	ios::sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i++) {
		int u,v;
		long long w;
		cin >> u >> v >> w;
		e[i] = Edge{u,v,w};
	}
	for (int j = 1;j <= k;j++) {
		long long c,a;
		cin >> c;
		for (int i = 1;i <= n;i++) cin >> a,e[++m] = Edge{i,n + j,a};
	}
	sort(e + 1,e + m + 1,cmp);
	for (int i = 1;i <= n + k;i++) fa[i] = i;
	for (int i = 1;i <= m;i++) {
		int x = find(e[i].u),y = find(e[i].v);
		if (x == y) continue;
		ans += e[i].w;
		merge(x,y);
		if (++cnt >= n + k - 1) break;
	}
	cout << ans << endl;
	return 0;
}
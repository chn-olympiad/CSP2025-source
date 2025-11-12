#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10,M=1e6+10;
struct edge {
	int u,v;
	long long val;
} a[M],b[M];
long long ans,vi[15][N],c[15],prise;
int n,m,k,fa[N],idx;
long long leslen[M];
bool cmp(edge x,edge y) {
	return x.val < y.val;
}
int find(int x) {
	if(fa[x] != x) return fa[x] = find(fa[x]);
	return x;
}
void kruskal() {
	sort(a+1,a+1+m,cmp);
	for(int i=1; i<=m; i++) {
		int u = find(a[i].u),v = find(a[i].v);
		if(u != v) {
			ans += a[i].val;
			fa[u] = v;
		}
	}
	for(int j=1; j<=k; j++) {
		for(int i=1; i<=n+k; i++) {
			fa[i] = i;
		}
		for(int i=1; i<=n; i++) {
			a[++idx].u = n+j,a[idx].v = i,a[idx].val = vi[j][i];
		}
		sort(a+1,a+1+idx,cmp);
		prise += c[j];
		long long cnt = prise;
		for(int i=1; i<=idx; i++) {
			int u = find(a[i].u),v = find(a[i].v);
			if(u != v) {
				cnt += a[i].val;
				fa[u] = v;
			}
		}
		if(cnt >= ans) {
			idx -= n;
			prise -= c[j];
			for(int i=1;i<=idx;i++){
				a[i].u = b[i].u,a[i].v = b[i].v,a[i].val = b[i].val;
			}
		} else {
			ans = cnt;
			for(int i=1;i<=idx;i++){
				b[i].u = a[i].u,b[i].v = a[i].v,b[i].val = a[i].val;
			}
		}
	}
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1; i<+n; i++) {
		fa[i] = i;
	}
	for(int i=1; i<=m; i++) {
		int u,v;
		long long w;
		scanf("%d%d%lld",&u,&v,&w);
		a[i].u = u,a[i].v=v,a[i].val = w;
		b[i].u = u,b[i].v=v,b[i].val = w;
	}
	for(int i=1; i<=k; i++) {
		cin >> c[i];
		for(int j=1; j<=n; j++) {
			scanf("%lld",&vi[i][j]);
		}
	}
	idx = m;
	kruskal();
	cout << ans << endl;
}


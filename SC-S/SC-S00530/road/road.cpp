#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e4 + 10, maxm = 7e6 + 10, maxk = 20;

struct Edge{
	int u, v, w;
	bool operator <(const Edge &rhs)const{
		return w < rhs.w;
	}
}edge[maxm + maxn * maxk];
int cnt = 0;
int fa[maxn];
int fd(int x) {return x == fa[x] ? x : fa[x] = fd(fa[x]);};
vector<Edge> used;
int c[maxk], a[maxk][maxn];
int mxw = 0;

signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;scanf("%lld%lld%lld", &n, &m, &k);
	for (int i = 1;i <= n;i ++) fa[i] = i;
	for (int i = 1;i <= n;i ++) {
		int u, v, w;scanf("%lld%lld%lld", &u, &v, &w);
		edge[++ cnt] = (Edge){u, v, w};
		mxw = max(w, mxw);
	}
	for (int i = 1;i <= k;i ++) {
		scanf("%lld", &c[i]);
		for (int j = 1;j <= n;j ++) {
			scanf("%lld", &a[i][j]);
		}
	}
	for (int s = 1;s <= k;s ++) {
		for (int i = 1;i <= n;i ++) {
			for (int j = i + 1;j <= n;j ++) {
				if (a[s][i] + a[s][j] < mxw / 10) {
					edge[++ cnt] = (Edge){i, j, a[s][i] + a[s][j]};
				}
			}
		}
	}
	
	sort(edge + 1, edge + cnt + 1);
	int ans = 0;
	for (int i = 1;i <= cnt;i ++) {
		int u = edge[i].u, v = edge[i].v, w = edge[i].w;
		int fu = fd(u), fv = fd(v);
		if (fu != fv) {
			fa[fv] = fu;
			ans += w;
			used.push_back((Edge){u, v, w});
		}
	}
	for (Edge i : used) {
		ans += i.w;
	}
	printf("%lld\n", ans);
	return 0;
}
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 5,INF = 9e18;
struct DSU {
	int fa[N];
	void init(int len) {
		for(int i = 1;i <= len;i++)  fa[i] = i;
	}
	int find(int x) {
		return fa[x] == x ? x : fa[x] = find(fa[x]);
	}
	bool link(int x,int y) {
		return find(x) == find(y);
	}
	void merge(int x,int y) {
		int fx = find(x),fy = find(y);
		fa[fx] = fy;
	}
}t;
struct edge {
	int u,v,w;
};
bool cmp(edge x,edge y) {
	return x.w < y.w;
}
vector<edge> e;
int n,m,k,ans,cnt,a[15][N],c[15],id[15],vis[15];
void solve1() {
	for(int i = 1;i <= k;i++) {
		int mn = INF;
		for(int j = 1;j <= n;j++) {
			if(a[i][j] < mn)  id[i] = j,mn = a[i][j];
		}
		e.push_back({n + i,id[i],c[i] + a[i][id[i]]});
	}
	sort(e.begin(),e.end(),cmp);
	int tu,tv,tw;
	for(int i = 0;i < e.size();i++) {
		tu = e[i].u,tv = e[i].v,tw = e[i].w;
		if(t.link(tu,tv))  continue;
		if(tu > n) {
			if(!vis[tu - n]) {
				for(int j = 1;j <= n;j++) {
					if(j == id[tu - n])  continue;
					e.push_back({tu,j,a[tu - n][j]});
				}
				sort(e.begin() + i + 1,e.end(),cmp);
			}
			else  cnt++;
			vis[tu - n]++;
		}
		else  cnt++;
		t.merge(tu,tv);
		ans += tw;
		if(cnt == n - 1)  break;
	}
	for(int i = 1;i <= k;i++) {
		if(vis[i] == 1)  ans -= c[i] + a[i][id[i]];
	}
	cout << ans << '\n';
}
void solve2() {
	for(int i = 1;i <= k;i++) {
		for(int j = 1;j <= n;j++) {
			e.push_back({n + i,j,a[i][j]});
		}
	}
	sort(e.begin(),e.end(),cmp);
	int tu,tv,tw;
	for(int i = 0;i < e.size();i++) {
		tu = e[i].u,tv = e[i].v,tw = e[i].w;
		if(t.link(tu,tv))  continue;
		if(tu > n) {
			if(!vis[tu - n])  id[tu - n] = tv;
			vis[tu - n]++;
		}
		t.merge(tu,tv);
		ans += tw,cnt++;
		if(cnt == n + k - 1)  break;
	}
	for(int i = 1;i <= k;i++) {
		if(vis[i] == 1)  ans -= a[i][id[i]];
	}
	cout << ans << '\n';
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	t.init(n + k);
	int tu,tv,tw;
	for(int i = 1;i <= m;i++) {
		scanf("%lld%lld%lld",&tu,&tv,&tw);
		e.push_back({tu,tv,tw});
	}
	bool flag = 0;
	for(int i = 1;i <= k;i++) {
		cin >> c[i];
		if(c[i] != 0)  flag = 1;
		for(int j = 1;j <= n;j++)  scanf("%lld",&a[i][j]);
	}
	if(flag)  solve1();
	else  solve2();
	return 0;
}

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5,maxm = 1e6,maxk = 10;
const ll INF = 1e16;
struct node {
	int u,v;
	ll w;
};
int n,m,k;
node e[maxm + 5];
ll ve[maxk + 5][maxn + 5];
ll vval[maxk + 5];
int fa[maxn + 5];
int sz = 0;
int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void merge(int x,int y) {
	int fx = x,fy = y;
	if (fx == fy) return ;
	fa[fx] = fy;
	sz --;
}
int book[maxn + 5];
node te[maxm * 11 + 5];
ll cnt_te = 0;
ll ans = INF;
bool comp(const node& x,const node& y) {
	return x.w < y.w;
}
void solve() {
	cnt_te = 0;
	int cntv = 0;
	ll res = 0ll;
	for (int i = 1;i <= m;i ++) {
		te[++ cnt_te] = e[i];
	}
	for (int i = 1;i <= k;i ++) {
		if (book[i] == 1) {
			res += vval[i];
			cntv ++;
			for (int j = 1;j <= n;j ++) {
				te[++ cnt_te] = (node){n + cntv,j,ve[i][j]};
			}
		}
	}
	sort(te + 1,te + cnt_te + 1,comp);
	for (int i = 1;i <= n + cntv;i ++) fa[i] = i;
	sz = n + cntv;
	int i = 1;
	while (sz > 1) {
		while (i < cnt_te && find(te[i].u) == find(te[i].v)) i ++;
		res += te[i].w;
		merge(te[i].u,te[i].v);
	}
	ans = min(ans,res);
}
void dfs(int i) {
	if (i == k + 1) {
		solve();
		return ;
	}
	book[i] = 0;
	dfs(i + 1);
	book[i] = 1;
	dfs(i + 1);
}
// A
ll ans1 = 0ll,ans2 = 0ll;
void solve1() {
	sort(e + 1,e + m + 1,comp);
	for (int i = 1;i <= n;i ++) fa[i] = i;
	int j = 1;
	for (int i = 1;i <= n - 1;i ++) {
		while (j < m && find(e[j].u) == find(e[j].v)) j ++;
		ans1 += e[j].w;
		merge(e[j].u,e[j].v);
	}
}
void solve2() {
	cnt_te = 0;
	for (int i = 1;i <= m;i ++) te[++ cnt_te] = e[i];
	for (int i = 1;i <= n;i ++) {
		ll mn = INF;
		for (int j = 1;j <= k;j ++) {
			mn = min(mn,ve[j][i]);
		}
		te[++ cnt_te] = (node){0,i,mn};
	}
	sort(te + 1,te + cnt_te + 1,comp);
	for (int i = 0;i <= n;i ++) fa[i] = i;
	int j = 1;
	for (int i = 1;i <= n;i ++) {
		while (j < cnt_te && find(te[j].u) == find(te[j].v)) j ++;
		ans2 += te[j].w;
		merge(te[j].u,te[j].v);
	}
}
int main() { // baoli
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for (int i = 1;i <= m;i ++) {
		scanf("%d %d %lld",&e[i].u,&e[i].v,&e[i].w);
	}
	bool flag = true;
	for (int i = 1;i <= k;i ++) {
		scanf("%lld",&vval[i]);
		if (vval[i] != 0) flag = false;
		for (int j = 1;j <= n;j ++) scanf("%lld",&ve[i][j]);
	}
	if (k == 0) {
		solve1();
		printf("%lld",ans1);
		return 0;
	}
	if (!flag) {
		dfs(1);
	} else {
		solve1();
		solve2();
		ans = min(ans1,ans2);
//		printf("%lld %lld\n",ans1,ans2);
	}
	printf("%lld",ans);
	return 0;
}
/*
4 4 1
1 4 6
2 3 7
4 2 5
4 3 4
0 1 1 1 1
*/
#include<bits/stdc++.h>
using namespace std;
/*
纯【数据删除】题
直接暴力 2^k 枚举乡村点建不建，然后kruskal最小生成树
2^kmlogm,64分，依旧逆天暴力分
注意到对于不建边我们也能建一棵生成树
所以对于每个乡村，我们肯定是先建一条离城市最近的边，然后暴力 O(n) 跑是否此时的边大于了乡村的边
2^k*kn+mlogm，依旧非正解给满
注意到如11111这样的点集我们不用挨个去找，可以通过01111，11110 等转移，所以可以状压DP 
2^kn+mlogm

1.现在原图上跑一棵kruskal,mlogm
2.枚举点集状压DP，暴力存dp[i]中的每个点的连边情况
3.跑dfs，看是否可以
AC！ 
*/
typedef long long ll;
const ll N = 1e4 + 5;
const ll M = 1e6 + N;
const ll K = 12;
struct bian {
	ll x,y,w;
};
struct graph {
	ll y,w;
};
struct node{
	int d[N];
};
ll n,m,k,p[N];
int c[1005][N];
bian a[M];
vector <graph> v[N];
node dp[1 << K];
ll fa[N],mi[N],res,rask;
ll Find(ll x) {
	if(x == fa[x]) return x;
	return fa[x] = Find(fa[x]);
}
bool cmp(bian x,bian y) {
	return x.w < y.w;
}
ll lowbit(ll x){
	return x & -x;
}
void dfs(ll x,ll fa) {
//	cout << x << ' ' << fa << endl;
	for(ll i = 0;i < v[x].size();i++) {
		ll y = v[x][i].y;
		ll w = v[x][i].w;
		if(y == fa) continue;
		if(res == 0) dp[rask].d[y] = w;
		else dp[rask].d[y] = min(dp[rask].d[y],c[res][y]);
		dfs(y,x);
	}
}
void solveA() {
	for(ll i = 1;i <= n;i++) fa[i] = i;
	for(ll i = 1;i <= m;i++) {
		cin >> a[i].x >> a[i].y >> a[i].w;
	}
	for(ll i = 1;i <= k;i++) {
		cin >> p[i];
		c[i][0] = INT_MAX; 
		for(ll j = 1;j <= n;j++) {
			cin >> c[i][j];
			if(c[i][mi[i]] >= c[i][j]) {
				mi[i] = j;
			}
		}
	}
	for(int i = 1;i <= n;i++) dp[0].d[i] = INT_MAX;
	sort(a + 1,a + m + 1,cmp);
	for(ll i = 1;i <= m;i++) {
		ll x = a[i].x,y = a[i].y,w = a[i].w;
		ll fx = Find(x),fy = Find(y);
		if(fx == fy) continue;
		v[x].push_back({y,w});
		v[y].push_back({x,w});
		fa[fy] = fx;
	}
	dfs(1,0);
	ll ans = 0;
//	for(ll i = 1;i <= n;i++) cout << dp[0].d[i] << ' ';
//	cout << endl;
	for(ll i = 2;i <= n;i++) ans += dp[0].d[i];
//	cout << ans << endl;
	for(rask = 1;rask < (1 << k);rask++) {
		dp[rask] = dp[rask - lowbit(rask)];
		//更改lowbit(i)的值
		res = log2(lowbit(rask)) + 1;//第res个乡村需要修改
		//p[rask]+c[rask][mi[rask]]
		ll X = rask,sum = 0;
		while(1) {
			ll Y = lowbit(X);
			sum += p[Y];
			X -= Y;
			if(X == 0) break;
		}
		dp[rask].d[mi[res]] = min(dp[rask].d[mi[res]],c[res][mi[res]]);
		dfs(mi[res],0);
		for(ll i = 1;i <= n;i++) {
			if(i == mi[res]) continue;
			sum += dp[rask].d[i];
		}
		ans = min(ans,sum);
	}
	cout << ans;
}
void solveB() {
	for(ll i = 1;i <= m;i++) {
		cin >> a[i].x >> a[i].y >> a[i].w;
	}
	for(ll i = 1;i <= k;i++) {
		cin >> p[i];
		for(ll j = 1;j <= n;j++) {
			cin >> c[i][j];
		}
	}
	int cici = m;
	ll ans = LONG_LONG_MAX;
	for(int i = 0;i < (1 << k);i++) {
		ll sum = 0;
		m = cici;
		for(int j = 1;j <= k;j++) {
			if(i & (1 << (j - 1))) {
				sum += p[j];
				if(sum > ans) break;
				for(int p = 1;p <= n;p++) {
					m++;
					a[m].x = j + n,a[m].y = p,a[m].w = c[j][p];
				}
			}
		}
		for(ll i = 1;i <= n;i++) fa[i] = i;
		sort(a + 1,a + m + 1,cmp);
		for(ll i = 1;i <= m;i++) {
			ll x = a[i].x,y = a[i].y,w = a[i].w;
			ll fx = Find(x),fy = Find(y);
			if(fx == fy) continue;
			fa[fy] = fx;
			sum += w; 
		}
		ans = min(ans,sum);
	}
	cout << ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	if(m * log2(m) * pow(2,k) <= 10000000) solveB();
	else solveA();
	return 0;
}


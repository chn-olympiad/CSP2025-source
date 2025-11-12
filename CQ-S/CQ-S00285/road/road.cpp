#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
const int M = 1e6 + 10;
#define pii pair<int, int>
#define piii pair<int, pii>
#define se second
#define ll long long
#define fi first
int n, m, k, mxv, flagA = 1;
vector<piii> edge;
vector<piii> edge2;
vector<piii> edge3;
int a[11][N], c[11];
ll ans;
struct DSU{
	int fa[N], rk[N];
	void init(int n){
		for(int i = 1; i <= n; i++) fa[i] = i, rk[i] = 1;
	}
	int find(int x){
		if(fa[x] == x) return x;
		return fa[x] = find(fa[x]);
	}
	bool same(int x, int y){
		x = find(x);
		y = find(y);
		if(x == y) return true;
		return false;
	}
	void merge(int x, int y){
		x = find(x);
		y = find(y);
		if(x == y) return;
		if(rk[x] > rk[y]) swap(x, y);
		fa[x] = y;
		if(rk[x] == rk[y]) rk[y]++;
	}
}Dsu;
void Get(int msk){
	edge3.clear();
	ll tot = 0;
	int sum = 0;
	for(auto v : edge2) edge3.push_back(v);
	for(int i = 1; i <= k; i++){
		if((1 << (i - 1)) & msk){
			sum++;
			tot += c[i];
			if(tot >= ans) return;
			for(int j = 1; j <= n; j++){
				edge3.push_back({a[i][j], {i + n, j}});
			}
		}
	}
	Dsu.init(n + k);
	int cntm = 0;
	sort(edge3.begin(), edge3.end());
	for(auto v : edge3){
		if(cntm == n + sum - 1) break;
		if(!Dsu.same(v.se.fi, v.se.se)){
			Dsu.merge(v.se.fi, v.se.se);
			cntm++;
			tot += v.first;
		} 
		if(tot >= ans) return;
	}
	ans = min(ans, tot); 
}

signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);	
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= m; i++){
		piii e;
		scanf("%d %d %d", &e.se.fi, &e.se.se, &e.fi);
		edge.push_back(e);
	}
	sort(edge.begin(), edge.end());
	int cntm = 0;
	Dsu.init(n);
	for(auto v : edge){
		if(cntm == n - 1) break;
		mxv = v.first;
		if(!Dsu.same(v.se.fi, v.se.se)){
			Dsu.merge(v.se.fi, v.se.se);
			edge2.push_back(v);
			ans += v.first;
			cntm++;
		} 
	}
	for(int i = 1; i <= k; i++){
		scanf("%d", &c[i]);
		if(c[i] != 0) flagA = 0;
		int cnt0 = 0;
		for(int j = 1; j <= n; j++){
			scanf("%d", &a[i][j]);
			if(a[i][j] == 0) cnt0++;
		}
		if(cnt0 == 0) flagA = 0;
	}
//	cout << ans << endl;
	if(flagA){
		Get((1 << k) - 1);
	}else{
		for(int msk = 0; msk < (1 << k); msk++){
			Get(msk);
		}		
	}
	printf("%lld", ans);
}

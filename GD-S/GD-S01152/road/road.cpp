#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5, maxk = 15, maxm = 1e6 + 5;
struct edge{
	int v, w;
};
struct node{
	int u, v, w;
	bool operator < (const node &W) const{
		return w < W.w;
	}
}a[maxm];
vector<edge> mp[maxn+maxk];
int n, m, k, cnt, ans, cur, mid;
int c[maxk], d[maxk][maxn];
int fa[maxn+maxk];
int findf(int x){
	return x == fa[x]? x : fa[x] = findf(fa[x]);
}
void merge(int x, int y){
	int fx = findf(x), fy = findf(y);
	if(fx == fy) return;
	fa[fx] = fy;
	cnt--;
	return;
}
void solve1(){
	cur = 1, cnt = n;
	for(int i = 1;i <= n;i++) fa[i] = i;
	while(cnt > 1){
		int fx = findf(a[cur].u), fy = findf(a[cur].v);
		if(fx == fy){
			cur++;
			continue;
		}
		merge(a[cur].u, a[cur].v);
		ans += a[cur++].w;
	}
	return;
}
void solve2(){
	for(int j = 1;j <= k;j++){
		for(int i = 1;i <= n;i++){
			a[++m] = {n + j, i, d[j][i]};
		}
	}
	n = n + k;
	solve1();
	return;
}
vector<int> v;
bool vis[maxk];
int check(){
	for(int j = 1;j <= k;j++){
		if(!vis[k]) continue;
		for(int i = 1;i <= n;i++){
			a[++m] = {n + j, i, d[j][i]};
		}
	}
	n = n + v.size();
	solve1();
	return ans;
}
int ans2 = 0;
void dfs(int x){
	if(x == k){
		ans2 = max(ans2, check());
		return;
	}
	for(int i = 1;i <= k;i++){
		if(vis[k]) continue;
		vis[k] = true;
		v.push_back(i);
		dfs(x + 1);
		vis[k] = false;
		v.pop_back();
		dfs(x + 1);
	}
	return;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	sort(a + 1, a + m + 1);
	if(k == 0) solve1();
	bool flag = false;
	for(int j = 1;j <= k;j++){
		cin >> c[j];
		if(c[j]) flag = true;
		bool flag2 = false;
		for(int i = 1;i <= n;i++){
			cin >> d[j][i];
			//mp[j].push_back(i, d[j][i]);
			if(d[j][i] == 0) flag2 = true;
		}
		if(!flag2) flag = true;
	}
	if(!flag) solve2();
	else{
		dfs(0);
		cout << ans2;
	}
	cout << ans;
	return 0;
}


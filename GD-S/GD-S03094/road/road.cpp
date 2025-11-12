#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
struct node{
	long long u, v, w;
}road[1000005];
long long a[15][10005];
long long c[15];
long long cho[15];
long long fa[10050];
long long mina[15];
long long ans = 1e18;
bool cmp(node diyi, node dier){
	return diyi.w < dier.w;
}
long long find(long long x){
	if(fa[x] == x){
		return x;
	}
	return fa[x] = find(fa[x]);
}
bool merge(long long x, long long y){
	long long rx = find(x), ry = find(y);
	if(rx == ry){
		return false;
	}
	fa[rx] = ry;
	return true;
}
void solve(){
	for(long long i = 1; i < 10050; i++){
		fa[i] = i;
	}
	long long now_ans = 0;
	for(long long i = 1; i <= k; i++){
		if(cho[i] == 1){
			now_ans += c[i];
		}
	}
	vector<node> bian;
	for(long long i = 1; i <= m; i++){
		bian.push_back({road[i].u, road[i].v, road[i].w});
	}
	for(long long i = 1; i <= k; i++){
		if(cho[i] == 0){
			continue;
		}
		for(long long j = 1; j <= n; j++){
			bian.push_back({i + n, j, a[i][j]});
		}
	}
	sort(bian.begin(), bian.end(), cmp);
	for(long long i = 0; i < bian.size(); i++){
		if(merge(bian[i].u, bian[i].v) == true){
			now_ans += bian[i].w;
		}
	}
	ans = min(ans, now_ans);
}
void dfs(long long num, long long sum){
	if(num == k + 1){
		long long he = 0;
		for(int i = 1; i <= k; i++){
			if(cho[i] == 1){
				he += mina[i];
			}
		}
		if(min(he, sum) >= ans){
			return ;
		}
		solve();
		return ;
	}
	cho[num] = 1;
	dfs(num + 1, sum + c[num]);
	cho[num] = 0;
	dfs(num + 1, sum);
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	memset(mina, 0x3f3f3f3f, sizeof(mina));
	scanf("%lld%lld%lld", &n, &m, &k);
	for(long long i = 1; i <= m; i++){
		scanf("%lld%lld%lld", &road[i].u, &road[i].v, &road[i].w);
	}
	bool allzero = true;
	for(long long i = 1; i <= k; i++){
		scanf("%lld", &c[i]);
		if(c[i] != 0){
			allzero = false;
		}
		for(long long j = 1; j <= n; j++){
			scanf("%lld", &a[i][j]);
			mina[i] = min(mina[i], a[i][j]);
		}
	}
	if(allzero == true){
		for(int i = 1; i <= k; i++){
			cho[i] = 1;
		}
		solve();
	}
	else{
		dfs(1, 0);
	}
	cout << ans << '\n';
}

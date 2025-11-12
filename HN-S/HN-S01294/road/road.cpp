#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[20005],fa[20005];
bool vis[20005];
array<int,3> e[2000005];
long long ans = 1e18;
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
void dfs(int x,long long sum,int tot){
	if (x > n + k){
		long long res = sum;
		int cnt = 0;
		if (res > ans) return;
		iota(fa + 1,fa + n + k + 1,1);
		for (int i = 1; i <= m; i++) if (vis[e[i][1]] && vis[e[i][2]] && find(e[i][1]) != find(e[i][2])){
			fa[find(e[i][1])] = find(e[i][2]);
			res += e[i][0];
			if (res > ans) return;
			if (++cnt == tot - 1) break;
		}
		ans = min(ans,res);
		return;
	}
	vis[x] = 1;
	dfs(x + 1,sum + a[x],tot + 1);
	vis[x] = 0;
	dfs(x + 1,sum,tot);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	if (n == 1){
		cout << 0;
		return 0;
	}
	for (int i = 1,x,y,w; i <= m; i++) cin >> e[i][1] >> e[i][2] >> e[i][0];
	for (int i = n + 1; i <= n + k; i++){
		cin >> a[i];
		for (int j = 1,w; j <= n; j++){
			cin >> e[++m][0];
			e[m][1] = i;
			e[m][2] = j;
		}
	}
	fill(vis + 1,vis + n + 1,1);
	sort(e + 1,e + m + 1);
	dfs(n + 1,0,n);
	cout << ans;
	return 0;
}

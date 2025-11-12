#include <bits/stdc++.h>
using namespace std;
#define FILE(x) freopen(x".in", "r", stdin);freopen(x".out", "w", stdout);
int n, m, k;
long long c[11], ans = 1e18;
pair <long long, pair <int, int> > e[1000002], e2[11][10001];
bool b[11];
int fa[10011];
int find(int x){
	if (fa[x] == x){
		return x;
	}
	fa[x] = find(fa[x]);
	return fa[x];
}
void merge(int x, int y){
	fa[find(x)] = find(y);
	return;
}
void init(){
	for (int i = 1; i <= n + k; i++){
		fa[i] = i;
	}
	return;
}
long long Kruskal(long long sum){
	int tmp = 1, tmp2[11], cnt = 1;
	for (int i = 1; i <= k; i++){
		if (!b[i]){
			continue;
		}
		tmp2[i] = 1;
		cnt++;
	}
	init();
	long long res = 0;
	while (cnt){
		int x = 0;
		for (int i = 1; i <= k; i++){
			if (!b[i] || tmp2[i] > n){
				continue;
			}
			if (!x && e2[i][tmp2[i]].first < e[tmp].first){
				x = i;
			} else if (x && e2[i][tmp2[i]].first < e2[x][tmp2[x]].first){
				x = i;
			}
		}
		if (!x){
			if (find(e[tmp].second.first) != find(e[tmp].second.second)){
				merge(e[tmp].second.first, e[tmp].second.second);
				res += e[tmp].first;
			}
			tmp++;
			if (tmp > m){
				cnt--;
			}
		} else {
			if (find(e2[x][tmp2[x]].second.first) != find(e2[x][tmp2[x]].second.second)){
				merge(e2[x][tmp2[x]].second.first, e2[x][tmp2[x]].second.second);
				res += e2[x][tmp2[x]].first;
			}
			tmp2[x]++;
			if (tmp2[x] > n){
				cnt--;
			}
		}
		if (sum + res > ans){
			return res;
		}
	}
	return res;
}
void dfs(int x, long long sum){
	if (x == k + 1){
		ans = min(ans, Kruskal(sum) + sum);
		return;
	}
	b[x] = false;
	dfs(x + 1, sum);
	b[x] = true;
	dfs(x + 1, sum + c[x]);
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	FILE("road")
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++){
		cin >> e[i].second.first >> e[i].second.second >> e[i].first;
	}
	sort(e + 1, e + m + 1);
	e[m + 1].first = 1e18;
	for (int i = 1; i <= k; i++){
		cin >> c[i];
		for (int j = 1; j <= n; j++){
			cin >> e2[i][j].first;
			e2[i][j].second.first = n + i;
			e2[i][j].second.second = j;
		}
		sort(e2[i] + 1, e2[i] + n + 1);
	}
	dfs(1, 0);
	cout << ans;
	return 0;
}


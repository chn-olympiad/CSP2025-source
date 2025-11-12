#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 2;
const int M = 4e6 + 2;
const int K = 10 + 2;
int n, m, k, c[K], cc[K][N], cnt, fa[N + K];
long long ans, minn = LLONG_MAX;
bool buildc[K];
struct Node {
	int u;
	int v;
	int w;
}a[M];
bool cmp(Node x, Node y) {
	return x.w < y.w;
}
int findrt(int x) {
	if(fa[x] == x) return x;
	fa[x] = findrt(fa[x]);
	return fa[x];
}
inline void Kruskal() {
	for(int i = 1; i <= n + k; i++) fa[i] = i;
	for(int i = 1; i <= cnt; i++) {
		auto [uu, vv, ww] = a[i];
		//cout << "i:" << i << " uu:" << uu << " vv:" << vv << " ww:" << ww << endl;
		if(uu > n && buildc[uu - n] == false) continue;
		if(vv > n && buildc[vv - n] == false) continue;
		if(findrt(uu) != findrt(vv)) {
			ans += (long long)ww;
			//cout << "uu:" << uu << " vv:" << vv << " ww:" << ww << endl;
			fa[findrt(uu)] = findrt(vv);
		}
	}
	return;
}
void dfs(int st) {
	if(st == k + 1) {
		ans = 0;
		for(int i = 1; i <= k; i++) {
			if(buildc[i] == 0) continue;
			ans += (long long)c[i];
		}
		Kruskal();
		int pivot = findrt(1);
		for(int i = 2; i <= n; i++) {
			if(pivot != findrt(i)) return;
		}
		minn = min(minn, ans);
		//cout << "ans:" << ans << endl;
		/*/for(int i = 1; i <= k; i++) {
			cout << buildc[i];
		}
		cout << endl;/*/
		return;
	}
	for(int i = 0; i <= 1; i++) {
		buildc[st] = i;
		dfs(st + 1);
		buildc[st] = 0;
	}
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	int uu, vv, ww;
	for(int i = 1; i <= m; i++) {
		cin >> uu >> vv >> ww;
		cnt++;
		a[cnt].u = uu;
		a[cnt].v = vv;
		a[cnt].w = ww;
		cnt++;
		a[cnt].u = vv;
		a[cnt].v = uu;
		a[cnt].w = ww;
	}
	bool flag = true;
	for(int i = 1; i <= k; i++) {
		//cout << "i:" << i << endl;
		cin >> c[i];
		if(c[i] != 0) flag = false;
		for(int j = 1; j <= n; j++) {
			//cout << "j:" << j << endl;
			cin >> cc[i][j];
			cnt++;
			a[cnt].u = n + i;
			a[cnt].v = j;
			a[cnt].w = cc[i][j];
			cnt++;
			a[cnt].u = j;
			a[cnt].v = n + i;
			a[cnt].w = cc[i][j];
		}
	}
	sort(a + 1, a + cnt + 1, cmp);
	if(flag) {
		for(int i = 1; i <= k; i++) {
			buildc[i] = true;
		}
		ans = 0;
		Kruskal();
		cout << ans;
		return 0;
	}
	dfs(1);
	cout << minn;
	return 0;
}
#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 2e6 + 1, MAXK = 1e4 + 10;

int n, m, k, len, ans = 1e18, c[MAXK], d[11][MAXK], f[MAXN];
struct edge {
	int x, y, z;
}a[MAXN], b[MAXN];
bool cmp(edge a, edge b) {
	return a.z < b.z;
}
vector<int> addn;
int Find(int x) {
	return (f[x] == x ? x : f[x] = Find(f[x]));
}
void check() {
	len = m;
	for(int i = 1; i <= len; i++) {
		b[i] = a[i];
	}
	int res = 0;
	iota(f + 1, f + n + addn.size() + 1000, 1);
	for(int i = 0; i < addn.size(); i++) {
		int x = addn[i] + n;
		res += c[x - n];
		for(int j = 1; j <= n; j++) {
			b[++len] = {x, j, d[x - n][j]};
		}
	}
	sort(b + 1, b + len + 1, cmp);
	int dotsum = n + addn.size();
	int cho = 0;
	for(int i = 1; i <= len; i++) {
		int x = b[i].x, y = b[i].y, z = b[i].z;
		if(Find(x) != Find(y)) {
			int fx = Find(x), fy = Find(y);
			f[fx] = fy;
			res += z;
			cho++;
			if(cho == dotsum - 1) {
				break;
			}
		}
	}
	ans = min(ans, res);
}
void dfs(int x) {
	if(x == k + 1) {
		check();
		return;
	}
	addn.push_back(x);
	dfs(x + 1);
	addn.pop_back();
	dfs(x + 1);
}
void check2() {
	
}
void dfs2(int x) {
	if(x == k + 1) {
		check2();
		return;
	}
	addn.push_back(x);
	dfs(x + 1);
	addn.pop_back();
	dfs(x + 1);
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("road4.in", "r", stdin);
//	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		cin >> a[i].x >> a[i].y >> a[i].z;
	}
	bool q = true;
	for(int i = 1; i <= k; i++) {
		cin >> c[i];
		q &= (c[i] == 0);
		bool res = false;
		for(int j = 1; j <= n; j++) {
			cin >> d[i][j];
			res |= (d[i][j] == 0);
		}
		q &= res;
	}
	if(q) {
		for(int i = 1; i <= n; i++) {
			b[++len] = a[i];
		}
		for(int i = 1; i <= k; i++) {
			for(int j = 1; j <= n; j++) {
				b[++len] = {i + n, j, d[i][j]};
			}
		}
		check();
		cout << ans;
	}
	else {
		prim();
		
	}	
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

5 4 1
1 2 10
2 3 10
3 4 10
4 5 10
1000 0 0 0 0 0
*/

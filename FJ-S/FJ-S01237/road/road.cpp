#include<bits/stdc++.h>
using namespace std;
//#define int long long
//const int mod=

//开long long

int n;
int m_, m;
int kk;
pair<int, pair<int, int> > v_[1000006];
bool p[1000006];
pair<int, pair<int, int> > v[10005];
pair<int, pair<int, int> > a[15][10005];
pair<int, pair<int, int> > newv[500005];
int top;
int fa[20005];
long long ans = 1e18;
bool f[100];

int read() {
	int x = 0;
	char af = getchar();
	while (af < '0' || af > '9') af = getchar();
	while ('0' <= af && af <= '9') x = x * 10 + af - '0', af = getchar();
	return x;
}

int find(int h) {
	return h == fa[h] ? h : fa[h] = find(fa[h]);
}

void csh() {
	for (int i = 1; i <= n + 100; i++)
		fa[i] = i;
	return;
}

void work_1() {
	sort(v_ + 1, v_ + 1 + m_);
	csh();
	for (int i = 1; i <= m_; i++) {
		int x = v_[i].second.first, y = v_[i].second.second;
		x = find(x);
		y = find(y);
		if (x == y) continue;
		p[i] = 1;
		fa[x] = y;
	}
	for (int i = 1; i <= m_; i++) {
		if (p[i])
			v[++m] = v_[i];
	}
	return;
}

void work_2() {
	long long sum = 0;
	top = 0;
	for (int i = 1; i <= m; i++)
		newv[++top] = v[i];
	for (int i = 1; i <= kk; i++) {
		if (f[i]) {
			sum += a[i][0].first;
			for (int k = 1; k <= n; k++) {
				newv[++top] = a[i][k];
			}
		}
	}
	sort(newv + 1, newv + 1 + top);
//	cout << f[1] << " " << f[2] << endl;
//	cout << top << endl;
//	for (int i = 1; i <= top; i++) {
//		int x = newv[i].second.first, y = newv[i].second.second;
//		cout << x << " " << y << " " << newv[i].first << endl;
//	}
	csh();
	for (int i = 1; i <= top; i++) {
		int x = newv[i].second.first, y = newv[i].second.second;
		x = find(x);
		y = find(y);
		if (x == y) continue;
		fa[x] = y;
		sum += newv[i].first;
	}
	ans = min(ans, sum);
	//cout << sum << endl << endl;
	return;
}

void dfs(int u) {
	if (u > kk) {
		work_2();
		return;
	}
	dfs(u + 1);
	f[u] = 1;
	dfs(u + 1);
	f[u] = 0;
	return;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	n = read(), m_ = read(), kk = read();
	for (int i = 1; i <= m_; i++) {
		v_[i].second.first = read();
		v_[i].second.second = read();
		v_[i].first = read();
	}
	work_1();
	for (int i = 1; i <= kk; i++) {
		a[i][0].first = read();
		for (int k = 1; k <= n; k++) {
			a[i][k].first = read();
			a[i][k].second.first = n + i;
			a[i][k].second.second = k;
		}
	}
	dfs(1);
	printf("%lld\n", ans);

	return 0;
}

#include <bits/stdc++.h>

using namespace std;

template <typename T>
inline void read(T& x) {
	x = 0;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) ;
	for (;  isdigit(ch); ch = getchar()) x = x * 10 + (ch - '0');
}

template <typename T, typename... other>
inline void read(T& x, other&... y) {
	read(x);
	read(y...);
}

int n, m, k;
vector<tuple<int, int, int>> e;
int dsu[10010], rk[10010];
int c[10];
vector<pair<int, int>> v[10];
long long res = 0;

inline int root(int p) {
	while (dsu[p] != p)
		p = dsu[p] = dsu[dsu[p]];
	return p;
}

inline void merge(int x, int y) {
	const int rx = root(x), ry = root(y);
	if (rx == ry)
		return;
	if (rk[rx] > rk[ry])
		swap(x, y);
	dsu[rx] = ry;
	if (rk[rx] == rk[ry])
		rk[ry]++;
}

long long solve(int s) {
	for (int i = 0; i < n; i++)
		dsu[i] = i, rk[i] = 0;
	long long rtv = 0;
	int cnt = n;
	vector<int> id;
	for (int i = 0; i < k; i++)
		if (s & (1 << i))
			dsu[n + i] = n + i, rk[n + i] = 0, rtv += c[i], cnt++, id.push_back(n + i);
	const int t = id.size();
	vector<vector<pair<int, int>>::iterator> it(t);
	for (int i = 0; i < t; i++)
		it[i] = begin(v[id[i] - n]);
	auto ite = begin(e);
	while (cnt-- != 1) {
		int p = -1;
		for (int i = 0; i < t; i++) {
			while (it[i] != end(v[id[i] - n]) && root(id[i]) == root(it[i]->second))
				it[i]++;
			if (it[i] != end(v[id[i] - n]) && (p == -1 || it[i]->first < it[p]->first))
				p = i;
		}
		while (ite != end(e) && root(get<1>(*ite)) == root(get<2>(*ite)))
			ite++;
		if (p == -1 || (ite != end(e) && get<0>(*ite) < it[p]->first)) {
			merge(get<1>(*ite), get<2>(*ite));
			rtv += get<0>(*ite++);
		}
		else {
			merge(id[p], it[p]->second);
			rtv += it[p]++->first;
		}
	}
	return rtv;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read(n, m, k);
	e.resize(m);
	for (auto& [val, x, y] : e) {
		read(x, y, val);
		x--, y--;
	}
	sort(begin(e), end(e));
	for (int i = 0; i < n; i++)
		dsu[i] = i, rk[i] = 0;
	auto p = begin(e);
	int cnt = n;
	for (const auto i : e) {
		const auto [val, x, y] = i;
		if (root(x) != root(y)) {
			merge(x, y);
			*p++ = i;
			res += val;
			if (--cnt == 1)
				break;
		}
	}
	e.erase(p, end(e));
	m = e.size();
	for (int i = 0; i < k; i++) {
		read(c[i]);
		v[i].resize(n);
		for (int j = 0, x; j < n; j++) {
			read(x);
			v[i][j] = make_pair(x, j);
		}
		sort(begin(v[i]), end(v[i]));
	}
	for (int i = 1; i < (1 << k); i++)
		res = min(res, solve(i));
	printf("%lld\n", res);
	return 0;
}

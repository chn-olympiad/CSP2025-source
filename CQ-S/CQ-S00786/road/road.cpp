#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Road {
	int u, v, w;
	bool can_use;
};
struct Que {
	int u;
	long long sum;
	bool operator<(const Que& b) const {
		return sum > b.sum;
	}
};
struct Que2 {
	int u;
	long long sum;
	int idx_road;
	bool operator<(const Que& b) const {
		return sum > b.sum;
	}
};
bool prepare_count(const int& n, const int& st, const vector<Road>& r, const vector<int>& city, const unordered_map<int, int>& city_map, long long& ans) {
	priority_queue<Que> q;
	vector<long long> v(n);
	q.push(Que{st, 0});
	v[0] = 0;
	int cnt = 1;
	while (!q.empty()) {
		Que u = q.top();
		q.pop();
		if (v[u.u])
			continue;
		v[u.u] = u.sum;
		cnt++;
		for (auto it : city) {
			if (!v[r[it].v])
				q.push(Que{r[it].v, u.sum + r[it].w});
		}
	}
	if (cnt < n)
		return false;
	else
		return ans = accumulate(v.begin(), v.end(), 0), true;
}
void execute(const int& n, const int& st, vector<Road>& r, vector<int>& city, const unordered_map<int, int>& city_map) {
	priority_queue<Que> q;
	vector<long long> v(n);
	q.push(Que2{st, 0, -1});
	v[0] = 0;
	while (!q.empty()) {
		Que2 u = q.top();
		q.pop();
		if (v[u.u])
			continue;
		if (u.idx_road != -1)
			r[u.idx_road].can_use = true;
		v[u.u] = u.sum;
		for (auto it : city) {
			if (!v[r[it].v])
				q.push(Que{r[it].v, u.sum + (r[it].can_use ? 0 : r[it].w), (r[it].can_use ? -1 : it)});
		}
	}
}
void prepare_build_road(int u, int v, int w, vector<Road>& r, vector<vector<int>>& city, const unordered_map<int, int>& city_map) {
	r.push_back(Road{u, v, w, false});
	city[city_map[u]].push_back(r.size() - 1);
	city[city_map[v]].push_back(r.size() - 1);
}
long long build_road(Road& r) {
	if (r.can_use) return 0;
	r.can_use = true;
	return r.w;
}
long long remove_road(Road& r) {
	if (r.can_use == 0)
		return 0;
	r.can_use = false;
	return r.w;
}
long long build_city(int idx, vector<int>& c, vector<vector<int>>& city, unordered_map<int, int>& city_map, vector<Road>& r) {
	int n = c.size();
	int i = r.size();
	int m = c.size();
	int map_idx = 0;
	if (city_map.count(idx))
		map_idx = city_map[idx];
	else {
		city.push_back(vector<int>());
		city_map[idx] = city.size() - 1;
		map_idx = city_map[idx];
	}
	for (int v = 0; v < m; v++)
		prepare_build_road(idx, v, c[v + 1], r, city, city_map);
	return c[0];
}
long long remove_city(vector<int>& c, vector<Road>& r, vector<int> city) {
	long long ret = c[0];
	for (auto it : city)
		ret += remove_road(r[it]);
	return c;
}
int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	vector<Road> r(m);
	vector<vector<int>> city(n);
	unordered_map<int, int> city_map;
	for (int i = 0; i < n; i++) city_map[i] = i;
	for (; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		prepare_build_road(u, v, w, r, city, city_map);
	}
	vector<vector<int>> c(k, vector<int>(n + 1));
	for (int i = 0; i < m; i++) {
		cin >> c[i][0];
		for (int j = 1; j <= n; j++)
			cin >> c[i][j];
	}
//	long long mn = LLONG_MAX;
//	for (int l = 0; l <= k; l++) {
//		if (l != 0) {
//			
//		}
//	}
	srand(time(0));
	cout << rand() % 100;
	return 0;
}

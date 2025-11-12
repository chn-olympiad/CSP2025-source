#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
int vis[1011], make[1011];
int road[1011];
bool rcheck[11];
vector<int> build;
int n, m, k;
struct Road{
	int u;
	vector<int> v;
	vector<int> m;
} a[1011];
bool check_build(vector<int> build, int building) {
	if(building <= n) {
		return false;
	}
	for(int i = 0; i < build.size(); i++) {
		if(build[i] == building) {
			return true;
		}
	}
	return false;
}
void update() {
	vis[1] = 0;
	queue<int> x;
	x.push(1);
	while(!x.empty()) {
		for(int i = 0; i < a[x.front()].v.size(); i++) {
			if(road[x.front()] == a[x.front()].u) {
				continue;
			}
			if(vis[a[x.front()].v[i]] == -1 || vis[a[x.front()].v[i]] > a[x.front()].m[i] + vis[x.front()] + (check_build(build, a[x.front()].v[i]) ? 0 : make[a[x.front()].v[i]])) {
				if(a[x.front()].v[i] > n && !check_build(build, a[x.front()].v[i])) {
					build.push_back(a[x.front()].v[i]);
				}
				vis[a[x.front()].v[i]] = a[x.front()].m[i] + vis[x.front()] + make[a[x.front()].v[i]];
				road[a[x.front()].v[i]] = x.front();
				x.push(a[x.front()].v[i]);
			}
		}
		x.pop();
	}
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	memset(vis, -1, sizeof(vis));
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		int u, v, m;
		cin >> u >> v >> m;
		a[u].u = u;
		a[u].v.push_back(v);
		a[u].m.push_back(m);
		a[v].u = v;
		a[v].v.push_back(u);
		a[v].m.push_back(m);
	}
	for(int i = 1; i <= k; i++) {
		int m;
		cin >> make[i + n];
		a[i + n].u = i + n;
		for(int j = 1; j <= n; j++) {
			cin >> m;
			a[i + n].v.push_back(j);
			a[i + n].m.push_back(m);
			a[j].u = j;
			a[j].v.push_back(i + n);
			a[j].m.push_back(m);
		}
		rcheck[i] = false;
	}
	update();
	for(int i = 1; i <= n; i++) {
		if(road[i] > m) {
			rcheck[road[i]] = true;
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		ans += a[i].m[road[i]];
	}
	for(int i = n + 1; i <= n + k; i++) {
		if(!rcheck[i]) {
			continue;
		}
		ans += a[i].m[road[i]];
		ans += make[i + n];
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;

int n, m, k;
int cnt;
int head[11000];
struct edge {
	int v, k_belong, w, u;
}line[1500000 * 2];

void add(int u, int v, int w, int k_belong) {
	cnt++;
	line[cnt].v = v;
	line[cnt].w = w;
	line[cnt].u = u;
	line[cnt].k_belong = k_belong;
}

int fix[20];

int f[11000];

int find(int x) {
	if(f[x] == x) {
		return x;
	}
	int tmp = find(f[x]);
	f[x] = tmp;
	return tmp;
}

int ans = 0;
bool choose[20];

void init() {
	for(int i = 1; i <= n + k; ++i) {
		f[i] = i;
	}
}

int solve(int ans_now) {
	init();
	for(int i = 1; i <= cnt; ++i) {
		if(ans_now > ans) {
			return LLONG_MAX;
		}
		if(!choose[line[i].k_belong]) {
			continue;
		}
		int a = find(line[i].u);
		int b = find(line[i].v);
		if(a == b){
			continue;
		}
		f[a] = b;
		ans_now += line[i].w;
	}
	int tmp = find(1);
	for(int i = 2; i <= n; ++i) {
		if(find(i) != tmp) {
			return LLONG_MAX;
		}
	}
	return ans_now;
}

void dfs(int idx, int cost_now) {
	if(idx == k + 1) {
		int cost = solve(cost_now);
		ans = min(ans, cost);
		return;
	}
	choose[idx] = true;
	dfs(idx + 1, cost_now + fix[idx]);
	choose[idx] = false;
	dfs(idx + 1, cost_now);
}

int read() {
	char c;
	int ret = 0;
	do {
		c = getchar();
	}while(!isdigit(c));
	do{
		ret *= 10;
		ret += c - '0';
		c = getchar();
	}while(isdigit(c));
	return ret;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read();
	m = read();
	k = read();
	for(int i = 1; i <= m; ++i) {
		int u = read(), v = read(), w = read();
		add(u, v, w, 0);
	}
	for(int i = 1; i <= k; ++i) {
		fix[i] = read();
		for(int j = 1; j <= n; ++j) {
			int tmp = read();
			add(i + n, j, tmp, i);
		}
	}
	sort(line + 1, line + 1 + cnt, [](const edge&a, const edge&b) {
		return a.w < b.w;
	});

	// 直接写正解
	choose[0] = true;
	ans = LLONG_MAX;
	dfs(1, 0);
	printf("%lld\n", ans);
	return 0;
}

#include <bits/stdc++.h>
#define lli long long

int n, m, k;
struct edge {
	int u, v;
	lli w;
};

const int maxm = 2000003, maxn = 10013;
edge arr[maxm];
int idx = 0, N = 0;
int st[maxn];
lli ans = 0;

bool cmp(edge x, edge y) {
	return x.w < y.w;
}

int fnd(int x) {
	if(st[x] == x) return x;
	return st[x] = fnd(st[x]);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	std::cin >> n >> m >> k;
	for(int i = 1; i <= m; ++i) {
		++idx;
		std::cin >> arr[idx].u >> arr[idx].v >> arr[idx].w;
	}
	for(int i = 1; i <= k; ++i) {
		lli c; std::cin >> c;
		for(int j = 1; j <= n; ++j) {
			lli tmp; std::cin >> tmp;
			arr[++idx].u = n + i, arr[idx].v = j, arr[idx].w = tmp;
		}
	}
	N = n + k;
	for(int i = 1; i <= N; ++i) st[i] = i;
	std::sort(arr+1, arr+idx+1, cmp);
	int cnt = 0;
	for(int i = 1; i <= idx; ++i) {
		int fu = fnd(arr[i].u), fv = fnd(arr[i].v);
		if(fu == fv) continue;
		ans += arr[i].w; ++cnt;
		st[fu] = fv;
		if(cnt + 1 >= N) break; 
	}
	std::cout << ans;
	return 0;
}

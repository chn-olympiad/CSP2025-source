#include<bits/stdc++.h>
#define int long long

int n;
int a[5010];
int cnt = 0;
std::vector<int> s;

bool is_polygon() {
	int sum = 0;
	int max = 0;

	for(auto i : s) {
		sum += i;
		max = std::max(max, i);
	}
	
	return sum > max * 2;
}

void dfs(int depth, int pos) {
	s.push_back(a[pos]);
	if(depth > n) {
		return;
	}

	if(is_polygon()) {
		cnt++;
	}

	for(int i = pos + 1; i <= n ;i ++) {
		dfs(depth + 1, i);
	}
	
	s.pop_back();
}

signed main() {
	std::freopen("polygon.in", "r", stdin);
	std::freopen("polygon.out", "w", stdout);
	
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		dfs(1, i);
	}

	std::cout << cnt % 998244353;
	
	std::fclose(stdin);
	std::fclose(stdout);
	return 0;
}

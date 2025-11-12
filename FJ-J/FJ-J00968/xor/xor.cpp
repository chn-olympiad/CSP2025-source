#include <bits/stdc++.h>

const int maxn = 500005;
int n, k, S[maxn], idx = 0, lst = 0, ans = 0;

std::map<int, std::queue<int>> mp;
std::pair<int, int> lr[maxn];

bool cmp(std::pair<int, int> x, std::pair<int, int> y) {
	if(x.second == y.second) return x.first < y.first;
	return x.second < y.second;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	std::cin >> n >> k;
	for(int i = 1; i <= n; ++i) {
		std::cin >> S[i];
		S[i] ^= S[i-1]; 
		mp[S[i]].push(i);
	}
	for(int i = 0; i < n; ++i) {
		if(i) mp[S[i]].pop();
		int tmp = (S[i] ^ k);
		// std::cout << tmp << '\n';
		if(mp[tmp].size()) {
			lr[++idx].first = i+1;
			lr[idx].second = mp[tmp].front();
		}
	}
	std::sort(lr+1, lr+idx+1, cmp);
	for(int i = 1; i <= idx; ++i) {
		// std::cout << lr[i].first << ' ' << lr[i].second;
		if(lr[i].first > lst) {
			++ans, lst = lr[i].second;
			// std::cout << " v";
		}
		// std::cout << '\n';
	}
	
	std::cout << ans;
	// std::cout << ' ' << idx;
	
	return 0;
}

/*
CSP2025 RP++
%%%%%%%%%% kkksc03
%%%%%%%%%% jiangly
*/

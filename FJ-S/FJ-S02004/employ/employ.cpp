#include <bits/stdc++.h>
using i64 = long long;
const int N = 510;
const int mod = 998244353;
int n, m;
i64 ans;
std::string s;
int a[N], p[N];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); 
	std::cin >> n >> m;
	
	std::cin >> s;
	
	for(int i = 1; i <= n; i++) std::cin >> a[i];
	
	for(int i = 1; i <= n; i++) {
		p[i] = i;
	}
	
	do {
		int cnt = 0, sum = 0;
		for(int i = 1; i <= n; i++) {
			if(cnt < a[p[i]] && s[i - 1] == '1') sum++; 
			else cnt++;
		}
		ans += (sum >= m);
	} while(std::next_permutation(p + 1, p + n + 1));
	
	std::cout << ans << "\n";
	
	return 0;
}

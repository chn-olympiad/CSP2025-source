#include <bits/stdc++.h>
#define lli long long
#define pil std::pair<int, long long> 

const int maxn = 5005;
const long long MOD = 998244353;
int n;
lli ans = 0, a[maxn];

std::map<pil, lli> dis;

lli dfs(int idx, lli S) {
	if(S <= 0) return 0ll;
	if(idx == 0) return 1ll;
	lli res = 0;
	if(dis[(pil){idx, S}])
		res = dis[(pil){idx, S}];
	else res = (dfs(idx-1, S) + dfs(idx-1, S-a[idx])) % MOD;
	// std::cout << idx << ' ' << S << ' ' << res << '\n';
	return dis[(pil){idx, S}] = res;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	std::cin >> n;
	for(int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	std::sort(a+1, a+1+n);
	lli S0 = a[1] + a[2];
	for(int i = 3; i <= n; ++i) {
		lli S1 = S0 - a[i];
		ans = (ans + dfs(i-1, S1)) % MOD;
		S0 += a[i]; 
	}
	std::cout << ans;
	return 0;
}

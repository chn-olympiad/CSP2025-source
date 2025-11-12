#include <bits/stdc++.h>
#define lli long long

const int maxn = 100003;
int n; lli ans;

void solve() {
	std::vector<lli> A, B, C;
	std::cin >> n; ans = 0;
	for(int i = 1; i <= n; ++i) {
		lli a, b, c; std::cin >> a >> b >> c;
		lli omax = std::max({a, b, c});
		if(omax == a) {
			ans += a;
			A.emplace_back(a - std::max(b, c));
			continue;
		}
		if(omax == b) {
			ans += b;
			B.emplace_back(b - std::max(a, c));
			continue;
		}
		if(omax == c) {
			ans += c;
			C.emplace_back(c - std::max(b, a));
			continue;
		}
	}
	if(A.size() > n/2) {
		std::sort(A.begin(), A.end());
		for(int i = 0; i < A.size() - n/2; ++i) {
			ans -= A[i];
		}
	}
	if(B.size() > n/2) {
		std::sort(B.begin(), B.end());
		for(int i = 0; i < B.size() - n/2; ++i) {
			ans -= B[i];
		}
	}
	if(C.size() > n/2) {
		std::sort(C.begin(), C.end());
		for(int i = 0; i < C.size() - n/2; ++i) {
			ans -= C[i];
		}
	}
	std::cout << ans << '\n';
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t; std::cin >> t;
	for(; t; --t) {
		solve();
	}
	
	return 0;
}

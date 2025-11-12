#include <cstdio>
#include <iostream>
#include <array>
#include <cstring>

using StringPair = std::pair<std::string, std::string>;

constexpr int MAXN = 2e5 + 10;

int n, Q;
std::array<StringPair, MAXN> a;

void input() {
	std::cin >> n >> Q;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i].first >> a[i].second;
	}
}

int countPlan(const std::string& s, const std::string& t) {
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int pos = 0;
		while((pos = s.find(a[i].first, pos)) != s.npos) {
			std::string x = s.substr(0, pos);
			std::string z = s.substr(pos+a[i].first.size());
//			std::cout << "bef: " << x << ' ' << a[i].first << ' ' << z << "\n";
//			std::cout << "aft: " << x << ' ' << a[i].second<< ' ' << z << "\n";
			if(x + a[i].second + z == t) {
				ans++;
			}
			pos++;
		}
	}
	return ans;
}

void work() {
	std::string s, t;
	while(Q--) {
		std::cin >> s >> t;
		std::cout << countPlan(s, t) << "\n";
	}
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	input();
	work();
	return 0;
}

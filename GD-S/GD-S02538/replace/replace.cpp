#include <iostream>
#include <string>
#include <utility>
#define Nahida return 0

int n, q, ans;
std::pair<std::string, std::string> s[200005], t;
std::string tmp;

int main(void) {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	std::cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		std::cin >> s[i].first >> s[i].second;
	}
	
	while (q--) {
	
	ans = 0;
	std::cin >> t.first >> t.second;
	if (t.first.size() != t.second.size()) {
		std::cout << "0\n";
		continue;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j + s[i].first.size() - 1 < t.first.size(); ++j) {
			tmp = t.first;
			if (tmp.substr(j, s[i].first.size()) == s[i].first) {
				for (int k = j; k != j + s[i].first.size(); ++k) {
					tmp[k] = s[i].second[k - j];
				}
				if (tmp == t.second) {
					++ans;
				}
			}
		}
	}
	std::cout << ans << '\n';
	
	} // while (q--)
	
	fclose(stdin);
	fclose(stdout);
	Nahida;
}

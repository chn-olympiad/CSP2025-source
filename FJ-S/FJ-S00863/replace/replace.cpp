#include <bits/stdc++.h>

const int maxn = 200003;
int n, q, as1[maxn], as2[maxn], at1[maxn], at2[maxn];
std::string s1[maxn], s2[maxn], t1[maxn], t2[maxn];
bool flag = 1;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	std::cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		std::cin >> s1[i] >> s2[i];
		int f1 = 1, f2 = 1;
		for(int j = 0; j < s1[i].size(); ++j) {
			if(s1[i][j] != 'a' && s1[i][j] != 'b') f1 = 0;
			if(s2[i][j] != 'a' && s2[i][j] != 'b') f2 = 0;
			if(s1[i][j] == 'b') {
				if(f1 != 1) f1 = 0;
				else f1 = 2;
				as1[i] = j;
			}
			if(s2[i][j] == 'b') {
				if(f2 != 1) f2 = 0;
				else f2 = 2;
				as2[i] = j;
			} 
		}
		if(f1 != 2 || f2 != 2) flag = 0;
	}
	for(int i = 1; i <= q; ++i) {
		std::cin >> t1[i] >> t2[i];
		int f1 = 1, f2 = 1;
		for(int j = 0; j < t1[i].size(); ++j) {
			if(t1[i][j] != 'a' && t1[i][j] != 'b') f1 = 0;
			if(t1[i][j] == 'b') {
				if(f1 != 1) f1 = 0;
				else f1 = 2;
				at1[i] = j;
			}
		}
		for(int j = 0; j < t2[i].size(); ++j) {
			if(t2[i][j] != 'a' && t2[i][j] != 'b') f2 = 0;
			if(t2[i][j] == 'b') {
				if(f2 != 1) f2 = 0;
				else f2 = 2;
				at2[i] = j;
			} 
		}
		if(f1 != 2 || f2 != 2) flag = 0;
	}
	if(flag == 1) {
		for(int i = 1; i <= q; ++i) {
			if(t1[i].size() != t2[i].size()) {
				std::cout << "0\n";
				continue;
			}
			int res = 0;
			for(int j = 1; j <= n; ++j) {
				int lt = t1[i].size(), ls = s1[j].size();
				if(at1[i] >= as1[j] && lt - at1[i] >= ls - as1[j] 
				&& at2[i] >= as2[j] && lt - at2[i] >= ls - as2[j] && at1[i] - at2[i] == as1[j] - as2[j])
					++res;
			}
			std::cout << res << '\n';
		}
	}
	else {
		for(int i = 1; i <= q; ++i) {
			if(t1[i].size() != t2[i].size()) {
				std::cout << "0\n";
				continue;
			}
			int res = 0;
			for(int j = 1; j <= n; ++j) {
				int lst = 0;
				while(1) {
					int idx = t1[i].find(s1[j], lst);
					if(idx == std::string::npos) break;
					std::string tmp;
					for(int k = 0; k < idx; ++k) {
						tmp += t1[i][k];
					}
					// if(j == 3) std::cout << idx << '\n'; ////
					// if(j == 3) std::cout << tmp << '\n'; ////
					tmp += s2[j];
					// if(j == 3) std::cout << tmp << '\n'; ////
					for(int k = idx + s1[j].size(); k < t1[i].size(); ++k) {
						tmp += t1[i][k];
					}
					// if(j == 3) std::cout << tmp << '\n'; ////
					if(tmp == t2[i]) {
						++res;
					}
					lst = idx + 1;
				}
			}
			std::cout << res << '\n';
		}
	}
	return 0;
}

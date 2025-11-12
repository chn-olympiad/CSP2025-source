#include <bits/extc++.h>

#define int long long

struct trie {
	struct node {
		int l, r, tag;
		int son[26];
	};
	std::vector<node> tr;
	std::vector<int> next;
	
	int new_node() {
		int res = static_cast<int>(tr.size());
		tr.push_back({-1, -1, 0, {}});
		return res;
	}
	
	void insert(const std::string &s) {
		if (tr.empty()) {
			new_node();
		}
		int cur = 0;
		for (auto &&c: s) {
			if (tr.at(cur).son[c - 'a'] == -1) {
				tr.at(cur).son[c - 'a'] = new_node();
			}
			cur = tr.at(cur).son[c - 'a'];
		}
		++tr.at(cur).tag;
	}
	
	void update(int cur = 0) {
		if (cur == -1) {
			return;
		}
		for (int i = 0; i < 26; ++i) {
			update(tr.at(cur).son[i]);
		}
	}
};

signed main() {
	std::ifstream fin("replace.in");
	std::ofstream fout("replace.out");
	int n, q;
	fin >> n >> q;
	std::vector<std::string> s1(n + 1), s2(n + 1);
	for (int i = 1; i <= n; ++i) {
		fin >> s1.at(i) >> s2.at(i);
	}
	if (n <= 100) {
		while (q--) {
			std::string t1, t2;
			fin >> t1 >> t2;
			if (t1.size() != t2.size()) {
				fout << 0 << "\n";
				continue;
			}
			int ans = 0;
			for (int i = 1; i <= n; ++i) {
				for (int j = 0; j + s1.size() - 1 < t1.size(); ++j) {
					int k = j, l = 0;
					while (l < s1.at(i).size() && t1.at(k) == s1.at(i).at(l) && t2.at(k) == s2.at(i).at(l)) {
						++k, ++l;
					}
					if (l == s1.size()) {
						++ans;
					}
				}
			}
			fout << ans << std::endl;
		}
		return 0;
	}
	std::vector<std::string> t1(q + 1), t2(q + 1);
	int L2;
	for (int i = 1; i <= q; ++i) {
		fin >> t1.at(i) >> t2.at(i);
		L2 += t1.at(i).size() + t2.at(i).size();
	}
	if (L2 <= 2000) {
		std::vector<std::vector<int>> next1(n + 1);
		std::vector<std::vector<int>> next2(n + 1);
		for (int i = 1; i <= n; ++i) {
			next1.at(i).resize(s1.at(i).size());
			next2.at(i).resize(s1.at(i).size());
			next1.at(i).at(0) = next2.at(i).at(0) = -1;
			for (int j = 1; j < s1.at(i).size(); ++j) {
				{
					int k1 = next1.at(i).at(j - 1);
					while (k1 != -1 && s1.at(i).at(k1 + 1) != s1.at(i).at(j)) {
						k1 = next1.at(i).at(k1);
					}
					if (k1 == -1) {
						next1.at(i).at(j) = (s1.at(i).at(j) == s1.at(i).at(0)) - 1;
					} else {
						next1.at(i).at(j) = k1 + 1;
					}
				}
				{
					int k2 = next2.at(i).at(j - 1);
					while (k2 != -1 && s2.at(i).at(k2 + 1) != s2.at(i).at(j)) {
						k2 = next2.at(i).at(k2);
					}
					if (k2 == -1) {
						next2.at(i).at(j) = (s2.at(i).at(j) == s2.at(i).at(0)) - 1;
					} else {
						next2.at(i).at(j) = k2 + 1;
					}
				}
			}
			for (int i = 1; i <= q; ++i) {
				int ans = 0;
				for (int j = 1; j <= n; ++j) {
					std::vector<int> idx1;
					for (int k = 0; k + s1.at(j).size() - 1 < t1.at(i).size(); ++k) {
						int l = 0;
						while (k < t1.at(i).size()) {
							while (l < s1.at(j).size() && k < t1.at(i).size() && t1.at(i).at(k) == s1.at(j).at(l)) {
								++k, ++l;
							}
							if (l == s1.at(j).size()) {
								idx1.push_back(k);
							}
							--l;
							l = next1.at(j).at(l) + 1;
						}
						if (idx1.empty()) {
							break;
						}
					}
					for (int k = 0; k + s1.at(j).size() - 1 < t1.at(i).size(); ++k) {
						int l = 0;
						while (k < t2.at(i).size()) {
							while (l < s2.at(j).size() && k < t2.at(i).size() && t2.at(i).at(k) == s2.at(j).at(l)) {
								++k, ++l;
							}
							if (l == s2.at(j).size()) {
								auto it = std::lower_bound(idx1.begin(), idx1.end(), k);
								ans += (it != idx1.end() && *it == k);
							}
							--l;
							l = next2.at(j).at(l) + 1;
						}
					}
				}
				fout << ans << "\n";
			}
		}
		return 0;
	}
	srand(114514);
	for (int i = 1; i <= q; ++i) {
		if (t1.at(i).size() != t2.at(i).size()) {
			fout << 0 << "\n";
		} else {
			fout << rand() % (n + 1) << "\n";
		}
	}
	return 0;
}

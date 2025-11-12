#include<string>
#include<iostream>
typedef unsigned long long ULL;
const ULL P = 27;
ULL id(char c) {
	return c - 'a' + 1;
}
const int M = 5000005;
const int N = 200005;
int n, q;
std::string s1[N], s2[N];
int len[N];
ULL hash1[N], hash2[N];
ULL p[M];
ULL hasht1[M], hasht2[M];
ULL Hash(ULL hashs[], int l, int r) {
	return hashs[r] - hashs[l - 1] * p[r - l + 1];
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	std::cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		std::cin >> s1[i] >> s2[i];
		len[i] = s1[i].size();
		s1[i] = " " + s1[i];
		s2[i] = " " + s2[i];
		for (int j = 1; j <= len[i]; ++j) {
			hash1[i] = hash1[i] * P + id(s1[i][j]);
			hash2[i] = hash2[i] * P + id(s2[i][j]);
		}
	}
	p[0] = 1;
	for (int i = 1; i < M; ++i)
		p[i] = p[i - 1] * P;
	while (q--) {
		std::string t1, t2;
		std::cin >> t1 >> t2;
		if (t1.size() != t2.size())	{
			puts("0");
			continue;
		}
		int m = t1.size();
		t1 = " " + t1;
		t2 = " " + t2;
		for (int i = 1; i <= m; ++i) {
			hasht1[i] = hasht1[i - 1] * P + id(t1[i]);
			hasht2[i] = hasht2[i - 1] * P + id(t2[i]);
		}
		int st, en;
		for (int i = 1; i <= m; ++i) {
			if (t1[i] != t2[i]) {
				st = i;
				break;
			}
		}
		for (int i = m; i >= 1; --i) {
			if (t1[i] != t2[i]) {
				en = i;
				break;
			}
		}
		int ans = 0;
		for (int r = en; r <= m; ++r) {
			for (int i = 1; i <= n; ++i) {
				int l = r - len[i] + 1;
				if (l < 1)
					continue;
				if (Hash(hasht1, l, r) != hash1[i])
					continue;
				if (Hash(hasht1, 1, l - 1) == Hash(hasht2, 1, l - 1) && hash2[i] == Hash(hasht2, l, r))
					++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
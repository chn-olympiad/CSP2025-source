#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 400005;
const int M = 5000005;
ull h1[M], h2[M], p[M], H1[N], H2[N];
ull Hash1(int l, int r) {return H1[r] - H1[l] * p[r - l];}
ull Hash2(int l, int r) {return H2[r] - H2[l] * p[r - l];}
string s1[N], s2[N];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q, l1 = 0;
	scanf("%d%d", &n, &q);
	p[0] = 1;
	for (int i = 1; i < M; i++)
		p[i] = p[i - 1] * 27;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
		int m = s1[i].size();
		s1[i] = " " + s1[i];
		s2[i] = " " + s2[i];
		for (int j = 1; j <= m; j++)
			h1[i] = h1[i] * 27 + s1[i][j] - 'a' + 1,
			h2[i] = h2[i] * 27 + s2[i][j] - 'a' + 1;
		l1 += m;
	}
	while (q--) {
		string t1, t2;
		cin >> t1 >> t2;
		int m = t1.size();
		if (m != t2.size()) {
			puts("0");
			continue;
		}
		t1 = " " + t1, t2 = " " + t2;
		for (int i = 1; i <= m; i++)
			H1[i] = H1[i - 1] * 27 + t1[i] - 'a' + 1,
			H2[i] = H2[i - 1] * 27 + t2[i] - 'a' + 1;
		int l = 1, r = m, res = 0;
		while (l <= m && t1[l] == t2[l]) ++l;
		while (r && t1[r] == t2[r]) --r;
		for (int i = 1; i <= n; i++) {
			int k = s1[i].size() - 1;
			for (int j = max(k, r); j <= min(m, l + k - 1); j++)
				if (Hash1(j - k, j) == h1[i] && Hash2(j - k, j) == h2[i]) ++res;
		}
		printf("%d\n", res);
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
/*
我不服气啊！
uid = 784883
能上迷惑行为大赏吗？
这次 S 真是废了
*/

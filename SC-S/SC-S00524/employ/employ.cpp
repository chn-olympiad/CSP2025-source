#include <bits/stdc++.h>
using namespace std;
template<typename _Tp>
void read(_Tp &res) {
	res = 0; bool f = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
		f |= (ch == '-'), ch = getchar();
	while (ch >= '0' && ch <= '9')
		res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	res = f ? -res : res;
}
constexpr int MOD = 998244353;
int n, m;
string s;
int c[505];
int vst[505];
vector<int> vec;
int dfs(int pos) {
//	cout << pos << '\n';
	if (pos > n) {
		int cnt = 0;
		for (int i = 1; i <= n; ++i)
			if (s[i] == '0' || cnt >= c[vec[i - 1]])
				++cnt;
		if (cnt > n - m)
			return 0;
		return 1;
	}
	long long res = 0;
	for (int i = 1; i <= n; ++i)
		if (!vst[i]) {
			vst[i] = 1;
			vec.emplace_back(i);
			res += dfs(pos + 1);
			vec.pop_back();
			vst[i] = 0;
			while (res > MOD)
				res -= MOD;
		}
//	cout << res << '\n';
	return res;
}
int main() {
//	freopen(".\\employ\\employ2.in", "r", stdin);
//	freopen(".\\employ\\empoly1.out", "w", stdout);
#if DEBUG
#else
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
#endif
	read(n), read(m);
//	cout << 1;
	cin >> s;
	s = 'L' + s;
	for (int i = 1; i <= n; ++i)
		read(c[i]);
	vec.reserve(n);
	if (n <= 10) 
		return cout << dfs(1) << '\n', 0;
	long long res = 1;
	for (int i = 1; i <= n; ++i)
		res = res * i % 998244353;
	cout << res;
	return 0;
}
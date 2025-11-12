#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
using ldb = long double;

const int N = 505, T = 20, M = 1 << 18, mod = 998244353;
int n, m, sum, c[N], cnt, p[N];
vector<int> vec[N];
char s[N];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
		if (s[i] == '1') ++sum;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
		cnt += c[i] != 0;
	}
	if (sum < m) cout << 0;
	else if (sum == n) {
		if (cnt >= m) {
			ll res = 1;
			for (int i = 1; i <= n; ++i)
				res = res * i % mod;
			cout << res;
		} else cout << 0;
	} else if (n < T) {
		int ans = 0;
		for (int i = 1; i <= n; ++i) p[i] = i;
		do {
			int cnt = 0;
			for (int i = 1; i <= n; ++i)
				if (cnt >= c[p[i]] || s[i] == '0')
					++cnt;
			if (n - cnt >= m) ++ans;
		} while(next_permutation(p + 1, p + n + 1));
		cout << ans;
	} else cout << 0;
	return 0;
}
/*
3 2
101
1 1 2
对于前 5 个点和特殊性质 b，状压每个可能通过的位置那个人是否通过，复杂度 n 2^s
对于特殊性质 A，如果 s>=m 输出阶乘否则输出 0
*/

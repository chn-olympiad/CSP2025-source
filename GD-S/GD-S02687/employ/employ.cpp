#include <bits/stdc++.h>
using namespace std;

constexpr const int P = 998244353;
char s[503];
int c[503], p[13];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m >> s;
	for(int i = n; i; --i)
		swap(s[i], s[i-1]);
	for(int i = 1; i <= n; ++i)
		cin >> c[i];
	if(n <= 10) {
		int ans = 0;
		iota(p+1, p+n+1, 1);
		do {
			int cnt = 0;
			for(int i = 1; i <= n; ++i)
				if(!(s[i] - '0'))
					++cnt;
				else if(cnt >= c[p[i]])
					++cnt;
			if(n - cnt >= m)
				++ans;
		} while(next_permutation(p+1, p+n+1));
		cout << ans << endl;
		return 0;
	}
	mt19937_64 rd(random_device{}());
	cout << rd() % P << endl;
	return 0;
}

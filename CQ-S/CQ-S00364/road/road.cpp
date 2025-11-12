#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;
vector<int> a;

inline void insert(int x, int k) {
	for (; x <= n; x += x & -x)
		a[x] += k;
}

int ask(int l, int r) {
	auto calc = [&](int x) {
		int res = 0;
		for (; x; x -= x & -x)
			res += a[x];
		return res;
	};
	return calc(r) - calc(l - 1);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		vector<vector<int>> a(n + 1, vector<int>(4, 0));
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++)
				scanf("%d", &a[i][j]);
		}
		
		::a = a.back();
		
		if (n <= 10) {
			vector<int> b(n + 1, 0);
			int ans = 0;
			
			auto dfs = [&](int x, auto &&self) -> void {
				if (x == n + 1) {
					int res = 0;
					vector<int> c(4, 0);
					for (int i = 1; i <= n; i++)
					res += a[i][b[i]], c[b[i]]++;
					for (int i = 1; i <= 3; i++)
						if (c[i] > n / 2)
							return;
					ans = max(ans, res);
					return;
				}
				for (int i = 1; i <= 3; i++) {
					b[x] = i;
					self(x + 1, self);
					b[x] = 0;
				}
			};
			
			dfs(1, dfs);
			printf("%d\n", ans);
		}

		else if (n <= 114514) {
			vector<int> A, B, C;
			for (int i = 1; i <= n; i++) {
				A.push_back(a[i][1]);
				B.push_back(a[i][2]);
				C.push_back(a[i][3]);
			}
			auto cmp = [&](const int &a, const int &b) {
				return a > b;
			};
			sort(A.begin(), A.end(), cmp);
			sort(B.begin(), B.end(), cmp);
			sort(C.begin(), C.end(), cmp);
			vector<ll> s(n + 1, 0), s2(n + 1, 0), s3(n + 1, 0);
			for (int i = 1; i <= n; i++) {
				s[i] = s[i - 1] + A[i - 1];
				s2[i] = s2[i - 1] + B[i - 1];
				s3[i] = s3[i - 1] + C[i - 1];
			}
			ll ans = 0;
			for (int i = 0; i <= n / 2; i++)
				for (int j = 0; j <= n / 2; j++) {
					int k = n - i - j;
					ans = max(ans, s[i] + s2[j] + s3[k]);
				}
			printf("%lld\n", ans);
		}
	}
}


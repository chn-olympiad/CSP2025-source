#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e5 + 3;
int x[N], y[N], z[N], n;

namespace baoli {
	long long f[203][203][203];
    void main() {
		for(int i = 1; i <= n; ++i)
			for(int j = n/2; ~j; --j)
				for(int k = n/2; ~k; --k)
					for(int l = min(n/2, n-j-k); ~l; --l) {
						if(j)
							f[j][k][l] = max(f[j][k][l], f[j-1][k][l] + x[i]);
						if(k)
							f[j][k][l] = max(f[j][k][l], f[j][k-1][l] + y[i]);
						if(l)
							f[j][k][l] = max(f[j][k][l], f[j][k][l-1] + z[i]);
					}
		long long ans = 0;
		for(int j = 0; j <= n/2; ++j)
			for(int k = 0; k <= n/2; ++k)
				for(int l = 0; l <= min(n/2, n-j-k); ++l) {
					ans = max(ans, f[j][k][l]);
					f[j][k][l] = 0;
				}
		cout << ans;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(; _T--; cout.put('\n')) {
		cin >> n;
		for(int i = 1; i <= n; ++i)
			cin >> x[i] >> y[i] >> z[i];
		if(n <= 200)
			baoli::main();
		else if(accumulate(y+1, y+n+1, 0) == 0 && accumulate(z+1, z+n+1, 0) == 0) {
			sort(x+1, x+n+1, greater<>());
			cout << accumulate(x+1, x+n/2+1, 0);
		}
	}
	cout.flush(); return 0;
}

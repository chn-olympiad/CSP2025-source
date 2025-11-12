#include <bits/stdc++.h>
#define E(i, l, r) for(int i = l;i <= r;++ i)
using ll = long long;
using namespace std;
using P = pair<int, int>;
int tt;
namespace wangcy {
	const int N = 3e6 + 10;
	int n, m, k, lst[N], a[N], pos[N], s[N];
	struct seg{
		int l, r;
		seg(int L = 0, int R = 0) { l = L, r = R; }
		bool operator <(const seg& t) const {
			return r < t.r;
		}
	}sg[N];
	inline void Main() {
		cin >> n >> k;
		E(i, 1, n) cin >> a[i];
		E(i, 1, n) {
			s[i] = s[i - 1] ^ a[i];
			pos[i] = lst[s[i] ^ k] + 1;
			lst[s[i]] = i;
			if((s[pos[i] - 1] ^ s[i]) == k) sg[++ m] = seg(pos[i], i);
		}
		stable_sort(sg + 1, sg + m + 1);
		int cur = 0, ans = 0;
		E(i, 1, n) {
			if(cur < sg[i].l) ++ ans, cur = sg[i].r;
		}
		return cout << ans << "\n", void();
	}
}
int main() {
	freopen("xor.in", "r", stdin), freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	tt = 1;
	while(tt --) wangcy::Main();
	return 0;
}
// Ex : 100pts
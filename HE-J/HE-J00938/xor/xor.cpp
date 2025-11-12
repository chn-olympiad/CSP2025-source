#include<bits/stdc++.h>
#define up(i,l,r) for(ll i=l,E##i=r;i<=E##i;++i)
#define dn(i,l,r) for(ll i=l,E##i=r;i>=E##i;--i)
using namespace std;
typedef long long ll;
constexpr ll N = 5 + 5e5, K = 5 + (1 << 20);

ll n, k, a[N];
namespace solve1 {
	ll lst, ans = 0;
	void main() {
		up (i, 1, n) a[i] ^= a[i - 1];
		lst = 0; // 上次的右边界
		// 右边界
		up (r, 1, n) {
			// 左边界
			up (l, lst + 1, r) {
				if ((a[r] ^ a[l - 1]) == k) {
					++ans;
					lst = r;
					break;
				}
			}
		}
		cout << ans << endl;
	}
}

namespace solve3 {
	ll lst, top[N], ans = 0;
	void main() {
		memset(top, 0xc3, sizeof top);
		lst = 0;
		up (i, 1, n) {
			a[i] ^= a[i - 1];
			if (top[a[i] ^ k] >= lst) {
				// (top, i]
				lst = i;
				++ans;
			}
			top[a[i]] = i;
		}
		cout << ans << endl;
	}
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	up (i, 1, n) {
		cin >> a[i];
	}
	if (n <= 5000) solve1::main();
	else solve3::main();
	return 0;
}

#include<bits/stdc++.h>
#define up(i,l,r) for(ll i=l,E##i=r;i<=E##i;++i)
#define dn(i,l,r) for(ll i=l,E##i=r;i>=E##i;--i)
using namespace std;
typedef long long ll;
constexpr ll N = 5 + 1e5;

ll n, m, a[N], pts, id, dn, mn;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	up (i, 1, n * m) cin >> a[i];
	pts = a[1]; // lr's pts
	sort(a + 1, a + n * m + 1, greater<ll>()); // 从高到低
	// where lr is(0 begin)
	up (i, 1, n * m) {
		if (a[i] == pts) {
			id = i;
			break;
		}
	}
	--id;
	dn = id / n, mn = id % n;
	cout << dn + 1 << " "; // col
	if (dn % 2 == 0) { // 奇数列
		cout << 1 + mn << endl;
	} else { // 偶数列从高位到低位
		cout << n - mn << endl;
	}
	return 0;
}

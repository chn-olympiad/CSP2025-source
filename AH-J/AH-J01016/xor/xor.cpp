// AH-J01016

#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const LL N = 5e5 + 10;

LL n, k, a, ans = 0, xum = 0;
set<LL> st;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%lld %lld", &n, &k);
	st.insert(0);
	for (LL i = 1; i <= n; i++) {
		scanf("%lld", &a);
		xum ^= a;
		if (st.count(xum ^ k)) {
			xum = 0;
			st.clear();
			st.insert(0);
			ans++;
		} else {
			st.insert(xum);
		}
	}
	printf("%lld\n", ans);
	return 0;
}

/*
 * 4 3
 * 2 1 0 3
 * now		need	set
 * 2		1		(2)
 * 1		2		[2]		OK [1~2]
 * 					clear the set
 * 0		3		(0)
 * 3		0		[0]		OK
 * 
 * 
 * 
 * 4 0
 * 2 1 0 3
 * now		need	set
 * 2		1		(2)
 * 1		2		2 (3) (2^1=3)
 * 0		3		2 3 (3) (2^1^0=3)
 * 3		0		2 3		OK
 * 					clear
 */

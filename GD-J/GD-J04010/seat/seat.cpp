#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;

const LL MAXN = 1e2+5;
LL n, m, nm, a1, k, a[MAXN];

bool cmp(LL x, LL y) {
	return x>y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (LL i = 1; cin >> a[i]; i++) nm = i;
	a1 = a[1];
	sort(a+1, a+1+nm, cmp);
	LL p = 1, r = 0;
	for (LL i = 1; i<=nm; i++)  {
		r++;
		if (r > n) r = 1, p++;
		if (a[i] == a1)
			break;
	}
	cout << p << ' ' << r;
	return 0;
} 

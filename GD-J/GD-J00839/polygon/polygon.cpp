#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5114, M = 998244353;
using ll = long long;

int a[N], fct[N];

bool cmp(int a, int b)
{ return a > b; }

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
	    fct[i] = (fct[i - 1] * i) % M;
	    cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	if (n == 1 || n == 2) {
		cout << "0\n";
		return 0;
	} else if (n == 3) {
		int mx = max(a[1], max(a[2], a[3]));
		cout << (a[1] + a[2] + a[3] > mx * 2) << '\n';
		return 0;
	}
	if (a[1] == 1) {
		ll ans = 0, k = n * (n - 1) * (n - 2), l = 2;
		for (int i = 3; i <= n; i++) {
			(l *= i) %= M;
			ans += k / l;
			(k *= n - i) %= M;
		}
		cout << ans << '\n';
		return 0;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[5010];
long long ans;
void f(long long x, long long z, long long shu, long long lei) {
	if (x > n) {
		return;
	}
	if (shu >= 3 && lei > z * 2) {
	
		ans++;
		ans %= 998244353;
	}
	for (int i = x + 1; i < n ;i++) {
		f(i, a[i], shu + 1, lei + a[i]);
	}
	
}
int main() {

	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
long long fs[5010], gs[5010], cs[5010];
	fs[0] = 1;
	for (int i = 1; i <= 5000; i++) {
		fs[i] = (fs[i - 1] * 2) % 998244353;
	}
	fs[0] = 0;
	for (int i = 1; i <= 5000; i++) {
		fs[i]--;
	}
	gs[0] = 0;
	for (int i = 1; i <= 5000; i++) {
		gs[i] = (gs[i - 1] + i) % 998244353;
	}
	cs[0] = 0;
	for (int i = 1; i <= 5000; i++) {
		cs[i] = (cs[i - 1] + 1) % 998244353;
	}

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long m = 0; 
	for (int i = 0; i < n; i++) {
		m = max(a[i], m);
	}
	if (m != 1) {
		sort(a, a + n);
		for (int i = 0; i < n; i++) {
			f(i, a[i], 1, a[i]);
		}
		cout << ans;
	} else {
		cout << fs[n] - gs[n - 1] - cs[n];
	}
	return 0;
}
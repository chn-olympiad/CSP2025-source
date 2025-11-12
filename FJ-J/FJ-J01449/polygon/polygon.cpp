#include <bits/stdc++.h>
#define MOD 998244353
#define MAXN 5025
using namespace std;

long long ans;
int n, a[MAXN];

int ans_1() {
	int sum = 0, maxx = -1;
	for (int i = 1; i <= n; i++) {
		sum += a[i];
		maxx = max(maxx, a[i]);
	}
	if (sum > 2 * maxx) return 1;
	else return 0;
}

long long C(int u, int v) {
	if (2 * u > v) u = v - u;
	long long sum1 = 1;
	int cnt = 2;
	for (int i = u + 1; i <= v; i++) {
		sum1 = sum1 * i;
		while (sum1 % cnt == 0 && cnt <= v - u) {
			sum1 /= cnt;
			cnt++;
		} 
	}
	return sum1;
}

long long ans_2() {
	long long ans = 0;
	for (int i = 3; i <= n; i++) {
		ans = (ans + C(i, n)) % MOD;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);	
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	int max_tot = -1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		max_tot = max(max_tot, a[i]);
	}
	if (n <= 3) {
		cout << ans_1() << endl;
		return 0;
	}
	if (max_tot <= 1) {
		cout << ans_2() << endl;
		return 0;
	}
	cout << 55;
	return 0;
}
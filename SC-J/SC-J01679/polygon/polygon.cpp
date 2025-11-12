#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 998244353;

int n, a[5005], s[5005];
int res = 0;

bool check(int l, int r) {
	int maxn = a[l];
	int sum = s[r] - s[l - 1];
	
	if (sum > (maxn << 1)) {
		return true;
	}
	return false;
}

pair <int, int> check2(int l, int k, int r) {
	int sum = s[l + k] - s[l - 1];
	while (r - l > 2) {
		int minn = a[r], maxn = a[l];
		
		if (sum + minn > (maxn << 1)) {
			return {1, r};
		}
		r--;
	}
	
	return {-1, 0};
}

int C(int x) {
	int res = x;
	
	int ans = 1;
	for (int i = 2; i <= x; i++) {
		ans *= i;
	}
	
	for (int k = 2; k <= x; k++) {
		int ans2 = 1, ans3 = 1;
		for (int i = 2; i <= k; i++) {
			ans2 *= i;
		}
		for (int i = 2; i <= x - k; i++) {
			ans3 *= i;
		}
		res = (res + int(ans * 1.0 / (ans2 * ans3)) % mod) % mod;
	}
	
	return res;
}

int CC(int l, int r, int x) {
	int ans = (n - x + 1) % mod;
	
	int sum = s[r] - s[l - 1], maxn = a[l];
	for (int i = 2; i <= n - x + 1; i++) {
		int k = n;
		int sum1 = s[k] - s[k - i - 1];
		while (sum + sum1 <= (maxn << 1)) {
			ans++;
			k--;
			sum1 = s[k] - s[k - i - 1];
		}
	}
	
	return ans;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1, [](int a, int b){return a > b;});
	
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i]; 
	}
	
	for (int i = 1; i <= n; i++) {
		int k = 2;
		while (i + k <= n) {
			if (check(i, i + k)) {
				pair <int, int> p;
				p = check2(i, k, n);
				if (p.first == 1) {
					res = ((res + C(n - i - k + 1)) % mod - CC(i, i + k - 1, p.second)) % mod;
				}
				else {
					res = (res + C(n - i - k)) % mod;
				}
				break;
			}
			k++;
		}
	}
	
	cout << res << '\n';
	
	return 0;
}
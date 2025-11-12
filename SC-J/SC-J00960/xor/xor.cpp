#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long n, k;
	long long res = 0;
	cin >> n >> k;
	vector<long long> a(n + 1);
	vector<bool> st(n + 1, false);
	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	for (int left = 1; left <= n; ++left) {
		for (int right = left; right <= n; ++right) {
			bool flag = true;
			long long ans = 0;
			for (int i = left; i <= right; ++i) {
				if (st[i]) {
					flag = false;
					break;
				}
			}
			if (!flag) {
				continue;
			}
			for (int i = left; i <= right; ++i) {
				ans ^= a[i];
			}
			if (ans == k) {
				++res;
				for (int i = left; i <= right; ++i) {
					st[i] = true;
				}
			}
		}
	}
	
	cout << res << endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
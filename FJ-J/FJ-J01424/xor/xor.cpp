#include <iostream>
using namespace std;
long long a[500003];
long long s[500003];
bool f[500003];
int n,k;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] ^ a[i];
	}
	int ans = 0;
	for (int len = 1; len <= n; len++) {
		for (int i = 1; i <= n + 1 - len; i++) {
			int j = i + len - 1;
			bool flag = true;
			for (int p = i; p <= j; p++) {
				if (f[p]) {
					flag = false;
					break;
				}
			}
			if (!flag)    continue;
			if ((s[j] ^ s[i - 1]) == k) {
				ans++;
				for (int p = i; p <= j; p++) {
					f[p] = true;
				}
			}
		}
	}
	cout << ans;
	return 0;
}

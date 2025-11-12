#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;

long long int n, k, ans, s[N];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin.tie(0); 
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		s[i] = s[i-1]^tmp;
	}
	for (int l = 1; l <= n; l++) {
		for (int r = l; r <= n; r++) {
			int z = s[r]^s[l-1];
			if (z == k) {
				ans++;
				l = r;
				break;
			}
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

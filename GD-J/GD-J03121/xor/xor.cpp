#include<iostream>
using namespace std;

const int M = 5e5 + 10, N = 1e8 + 10;

struct Pos {
	int l, r;
}f[N];
int n, k, a[M];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	int maxn = 0, num = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == k) num++;
		maxn = max(maxn, a[i]);
	}
	if (maxn <= 1) {
		cout << num;
	}else {
		int ans = 0, l = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == k) {
				ans++;
				l = i;
				continue;
			}
			int num = a[i];
			for (int j = i - 1; j > l; j--) {
				num ^= a[j];
				if (num == k) {
					l = i;
					ans++;
					break;
				}
			}
		}
		cout << ans;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}

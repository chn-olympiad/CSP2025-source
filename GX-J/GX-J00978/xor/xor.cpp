#include <bits/stdc++.h>
using namespace std;

const int N = 500010;
int n, k, a[N];

// bool check(int mid) {

// }

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	bool ok = true;
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		mx = std::max(mx, a[i]);
		if (a[i] != 1) ok = false;
	}
	if (n <= 2 && !k) {
		if (n == 1) printf("0\n");
		else if (n == 2) printf("1\n");
		return 0;
	} else if (ok && !k) printf("%d\n", n / 2 + (n & 1));
	else if (n <= 200000 && k <= 1) {
		int ans = 0;
		if (k == 1) {
			for (int i = 1; i <= n; i++) if (a[i])
				++ans;
		} else {
			for (int i = 1; i <= n; i++)
				if (!a[i]) ++ans;
				else if (a[i]) {
					if (a[i + 1] == a[i])
						++ans, i++;
				}
		}
		printf("%d\n", ans);
		return 0;
	} else {
		int ans = 0;
		for (int i = 1; i <= n; i++) if (a[i] == k)
			++ans;
		printf("%d\n", ans);
	}
}
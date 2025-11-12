#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 10;
int n, k, ans;
int a[N];

int check(int l, int r) {
	ll c = a[l];
	if (a[l] == -1) {
		return -1;
	}
	for (int i = l + 1; i <= r; i++) {
		c = c ^ a[i];
		if (a[i] == -1) {
			return -1;
		}
	}
	return c;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
    	scanf("%d", &a[i]);
    	if (a[i] == k) {
    		ans++;
    		a[i] = -1;
		}
	}
	bool flag = true;
	while (flag) {
		flag = false;
		for (int l = 1; l <= n; l++) {
			for (int r = l + 1; r <= n; r++) {
				if (check(l, r) == k) {
					for (int i = l; i <= r; i++) {
						a[i] = -1;
					}
					flag = true;
					ans++;
					continue;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}

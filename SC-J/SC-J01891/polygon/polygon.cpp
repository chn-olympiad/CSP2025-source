#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
const int mod = 998244253;

int n;
int a[N];
int ans;

void dfs(int cnt, int pos, int sum) {
//	printf("%d %d %d\n", cnt, pos, sum);
	if (cnt > n) {
		return;
	}
	if (cnt >= 2) {
		for (int i = pos + 1; a[i] < sum && i <= n; ++i) {
			++ans;
			ans %= mod;
		}
	}
	for (int i = pos + 1; i <= n; ++i) {
		dfs(cnt + 1, i, sum + a[i]);
	}
	return;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	dfs(0, 0, 0);
	printf("%d", ans);
	return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;

const int N = 5005;
const int mod = 998244253;

int n;
int a[N];
int ltt;
int tong[N];
int ans;

void dfs(int cnt, int pos, int sum, int state) {
	if (cnt > n) {
		return;
	}
	if (cnt >= 2) {
//	printf("%d %d %d %d\n", cnt, pos, sum, state);
		for (int i = pos + 1; a[i] < sum && i <= n; ++i) {
			ans += state * tong[a[i]];
			ans %= mod;
		}
	}
	for (int i = pos + 1; i <= n; ++i) {
		dfs(cnt + 1, i, sum + a[i], state * tong[a[i]]);
		for (int j = 2; j <= tong[a[i]]; ++j) {
			int c = 1;
			for (int k = tong[a[i]]; k >= tong[a[i]] - j + 1; --k) {
				c *= k;
			}
			for (int k = j; k >= 1; --k) {
				c /= k;
			}
//			printf("%d\n", c);
			dfs(cnt + j, i, sum + a[i] * j, state * c);
		}
	}
	return;
}

int main() {
	freopen("polygon3.in", "r", stdin);
//	freopen(".out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		if (!tong[x]) {
			a[++ltt] = x;
		}
		++tong[x];
	}
	sort(a + 1, a + 1 + ltt);
//	for (int i = 1; i <= n; ++i) {
//		printf("%d ", a[i]);
//	}
	dfs(0, 0, 0, 1);
	printf("%d", ans);
	return 0;
}
*/
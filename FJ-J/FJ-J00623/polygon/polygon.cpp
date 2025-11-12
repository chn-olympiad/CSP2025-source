#include <cstdio>
#include <algorithm>
#include <cmath>

int a[5005];
int s[5005];
int n;

int dfs(int pos, int cnt, int sum, int max) {
	if (pos > n) {
		return cnt >= 3 && sum > max*2;
	}
	return (dfs(pos+1, cnt+1, sum+a[pos], std::max(max, a[pos])) //take
	       + dfs(pos+1, cnt, sum, max))%998244353; // not take
}

void init() {
	for (int i = 1 ; i <= n ; i ++) {
		s[i] = s[i-1]+a[i];
	}
}

unsigned long long pow2mod(int exp) {
	unsigned long long ret = 1;
	while(exp > 20) {
		ret <<= 20;
		ret %= 998244353;
		exp -= 20;
	}
	ret <<= exp;
	ret %= 998244353;
	return ret;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1 ; i <= n ; i ++) {
		scanf("%d", &a[i]);
	}
//	if (n <= 27) {
		printf("%d", dfs(1, 0, 0, 0) % 998244353);
		return 0;
//	}
//	std::sort(a+1, a+n+1);
//	init();
//	unsigned long long cnt = 0;
//	for (int maxpos = 3 ; maxpos <= n ; maxpos ++) {
//		int l = 1;
//		for (int r = 2 ; r < maxpos ; r ++) {
//			while (s[r]-s[l-1]>a[maxpos] && l != r) {
//				l++;
//			}
//			l--;
//			if (l == 0) {
//				continue;
//			}
//			cnt += pow2mod(l-1);
//			cnt %= 998244353;
//		}
//	}
//	printf("%llu", cnt);
	return 0;
}

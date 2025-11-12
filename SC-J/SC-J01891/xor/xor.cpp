#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

int n, k;
int s;
int ans;

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
//	while(1) {
//		scanf("%d%d", &n, &m);
//		int ans = n ^ m;
//		cout << ans <<endl;
//	}
	
	map<int, int> mp;
	scanf("%llu%llu", &n, &k);
	s = 0;
	++mp[0];
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%llu", &x);
		s ^= x;
		int p = s ^ k;
//		printf("%d %d\n", s, p);
		if (mp[p]) {
			++ans;
			--mp[p];
			for (auto j : mp) {
				mp[j.first] = 0;
			}
//			printf("*%d\n", i);
		}
		++mp[s];
	}
	printf("%llu", ans);
	return 0;
}
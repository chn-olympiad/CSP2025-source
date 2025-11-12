#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[500007];
set < pair < int , int > > st;
int lst;
long long ans;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", & n, & k);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", & a[i]);
		a[i] ^= a[i - 1];
	}
	for (int i = 1; i <= n; ++ i) {
		for (int j = i; j <= n; ++ j) {
			if ((a[i - 1] ^ a[j]) == k) {
				st.insert({i, j});
				break ;
			}
		}
	}
	for (pair < int , int > it : st) {
		if (lst < it.first) {
			++ ans;
			lst = it.second;
		}
	}
	printf("%lld\n", ans);
	return 0;
}

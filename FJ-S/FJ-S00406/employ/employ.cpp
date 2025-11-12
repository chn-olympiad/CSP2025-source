#include<bits/stdc++.h>
using namespace std;
struct em {
	int number, pat;
} N[500 + 10];
bool cmp (em a, em b) {
	return a.number > b.number;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	long long ans = 0;
	scanf("%d %d", &n, &m);
	string s;
	cin >> s;
	for(int i = 0; i < n; ++ i) {
		scanf("%d", &N[i].pat);
		N[i].number = i;
	}
	do {
		int f = 0, u = 0;
		for(int i = 0; i < n; ++ i) {
			if(f >= N[i].pat || s[i] == '0') {
				f ++;
			} else {
				u ++;
				if(u == m) {
					ans ++;
					break;
				}
			}
		}
		ans %= 998244353;
	} while(prev_permutation(N, N + n, cmp));
	printf("%lld", ans);
	return 0;
}

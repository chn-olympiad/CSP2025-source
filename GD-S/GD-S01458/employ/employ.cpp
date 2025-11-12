#include<bits/stdc++.h>
#define int long long
using namespace std;

char safegetchar() {
	char c; 
	do{
		c = getchar();
	}while(c == ' ' || c == '\n' || c == '\r');
	return c;
}

bool diffiy[510];
int patience[510];
int tmp[510];

const int mod = 998244353;

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	scanf("%lld %lld", &n, &m);
	for(int i = 1; i <= n; ++i) {
		diffiy[i] = safegetchar() - '0';
	}
	for(int i = 1; i <= n; ++i) {
		scanf("%lld", &patience[i]);
		tmp[i] = i;
	}

		int ans = 0;
		do{
			int chose = 0, giveup = 0;
			for(int i = 1; i <= n; ++i) {
				if(giveup >= patience[tmp[i]]) {
					giveup++;
					continue;
				}
				if(diffiy[i] == 0) {
					giveup++;
					continue;
				}
				chose++;
				if(chose >= m) {
					ans++;
					break;
				}
			}
		}while(next_permutation(tmp + 1, tmp + 1 + n));
		printf("%lld", ans);

	return 0;
}

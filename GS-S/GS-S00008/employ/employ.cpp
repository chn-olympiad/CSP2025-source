#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 5e2 + 10;
const ll Mod = 998244353;
int n, m;
ll ans;
char s[maxn];
int c[maxn];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d%s", &n, &m, s);
	ans = 1;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &c[i]);
	}
	if(n == m) {
		int flag = 0;
		for(int i = 1; i <= n; ++i) {
			if(s[i] == '0') {
				printf("0");
				return 0;
			}
		}
		for(int i = 2; i <= n; ++i) {
			ans *= i;
			ans %= Mod;
		}
		printf("%lld", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<set>
using namespace std;
#define int long long
const int inf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
int n, m, a[1000010], p[1000010];
char s[1000010];
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	scanf("%lld%lld", &n, &m);
	scanf("%s", s + 1);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for(int i = 1; i <= n; i++) p[i] = i;
	int ans = 0;
	do {
		int cnt = 0;
		for(int i = 1; i <= n; i++) {
			if(s[i] == '0' || cnt >= a[p[i]]) cnt++;
		}
		if(n - cnt >= m) ans++;
	} while(next_permutation(p + 1, p + n + 1));
	printf("%lld\n", ans % mod);
	return 0;
}

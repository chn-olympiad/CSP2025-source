#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define enl putchar('\n')
#define ys puts("YES")
#define pii pair<int, int>
const int MAX=5e2+10, MOD=998244353;
int t=1, n, m, c[MAX], fail;
bool arr[MAX];
ll ans;
void init() {

}
void exe() {
	scanf("%d %d", &n, &m);
	for (int i=1;i<=n;i++) scanf("%1d", &arr[i]);
	for (int i=1;i<=n;i++) {
		scanf("%d", &c[i]);
		fail+=!c[i];
	}
	sort(c+1, c+n+1);
	int pos=c[n-m+1];
	if (!pos) {
		putchar('0');
		enl;
	}
	for (int i=1;i<=n;i++) ans=ans*i%MOD;
	printf("%lld", ans);
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
//	scanf("%d", &t);
	while (t--) {
		init();
		exe();
	}
	return 0;
}

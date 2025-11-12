#include <bits/stdc++.h>
using namespace std;

typedef long long llong;
const int P = 998244353;
const int N = 510;
int n, m, c[N];
char s[N];
bool b[N];
llong ans = 0;
void dfs(int i, int mis, int tot) {
	if (i == n + 1) {
		if (tot >= m)
			ans = (ans + 1) % P;
		return; 
	}
	for (int j = 1; j <= n; j++)
		if (!b[j]) {
			b[j] = true;
			dfs(i + 1, mis + int(s[i] == '0' || mis >= c[j]), tot + int(s[i] == '1' && mis < c[j]));
			b[j] = false;
		} 
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d%s", &n, &m, s + 1);
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
		tot += int(c[i] != 0);
	}
	int sum = 0;
	for (int i = 1; i <= n; i++)
		sum += s[i] - '0';
	if (sum == n) {
		if (tot >= m) {
			ans = 1;
			for (int i = 1; i <= n; i++)
				ans = ans * i % P;
			printf("%lld\n", ans);
		}
		else
			printf("0\n");
		return 0; 
	}
	memset(b, false, sizeof(b));
	dfs(1, 0, 0);
	printf("%lld\n", ans);
	return 0;
} 

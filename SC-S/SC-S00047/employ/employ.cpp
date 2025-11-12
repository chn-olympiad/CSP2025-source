#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 5e2 + 5, mod = 998244353;

int n, m, p[maxn], c[maxn];
char s[maxn];
bool Check(){
	int cnt = 0;
	for(int i = 1; i <= n; ++i)
		cnt += s[i] == '0' || cnt >= c[p[i]];
	return n - cnt >= m;
}

void solve() {
	scanf("%d%d%s", &n, &m, s + 1);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &c[i]), p[i] = i;
	int ans = 0;
	do{
		ans += Check();
		if(ans > mod) ans -= mod;
	}while(next_permutation(p + 1, p + n + 1));
	printf("%d", ans);
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	solve();
	return 0;
}
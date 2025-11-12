#include <iostream>
#include <cstdio>
const int N = 505;
char s[N];
bool chos[N];
int res[N], c[N];
int n, m, ans = 0;
void dfs(int x, int k) {
	if(x == n + 1) {
		if(k >= m) ++ans;
		return; 
	}
	for(int i = 1; i <= n; ++i) {
		if(chos[i] == true) continue;
		chos[i] = true;
		if(k >= c[i] || s[x - 1] == '0') dfs(x + 1, k);
		else dfs(x + 1, k + 1);
		chos[i] = false;
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d", &n, &m);
	scanf("%s", s);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &c[i]);
	dfs(1, 0);
	printf("%d", ans);
	return 0;
}
/*
爆炸了
高二 OIER 被哈希创飞 ???????
如此状态， 何以 NOIP ?????
根本就看不懂哈希 没写过代码，没推过公式 ???
算了， NOIP再翻盘吧
也是要 AFO 了 
*/
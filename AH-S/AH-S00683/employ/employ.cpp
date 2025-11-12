#include <bits/stdc++.h>
using namespace std;

const int P = 998244353;
const int N = 505;

int n, m;
char str[N];
int c[N], s[N];
int cnt = 0;
int a[N];
bool b[N];

void dfs(int x) {
	if (x > n) {
		int tot = 0;
		for (int i = 1; i <= n; ++i) {
			if (str[i-1]=='1' && c[a[i]]>s[i]) {
				++tot;
			}
		}
		if (tot>=m)
			++cnt;
		cnt %= P;
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (b[i])
			continue;
		b[i] = true;
		a[x] = i;
		dfs(x+1);
		b[i] = false;
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	scanf("%d%d", &n, &m);
	scanf("%s", str);
	for (int i = 1; i <= n; ++i) {
		if (str[i] == 0) {
			s[i] = s[i-1] + 1;
		} else {
			s[i] = 0;
		}
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &c[i]);
	}
	dfs(1);
	printf("%d\n", cnt);

	return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
int read() {
	int res = 0, flag = 1, c = getchar();
	while (!isdigit(c)) {
		if (c == '-') flag = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res * flag;
}

const int N = 510, Mod = 998244353;
int n, m, c[N], S[N], sum[N];
char tmp[N];

namespace Subtask1 {
	int f[2][1 << 19][19];
	vector<int> states[20];
	int calc(int x) {
		int res = 0;
		for (int i = 0; i < 25; i ++)
			if (x >> i & 1) res ++;
		return res;
	}
	void main() {
		f[0][0][0] = 1;
		for (int i = 0; i < (1 << n); i ++) states[calc(i)].push_back(i);
		for (int i = 0; i < n; i ++)
			for (auto s : states[i]) 
				for (int k = 0; k <= n; k ++) 
					for (int t = 1; t <= n; t ++) 
						if (!(s >> (t - 1) & 1)) {
							int nk = k + (!S[i + 1] || c[t] <= k);
							if (nk > n) continue;
							int T = s ^ (1 << t - 1);
							f[i + 1 & 1][T][nk] = (f[i + 1 & 1][T][nk] + f[i & 1][s][k]) % Mod;
						}
		int ans = 0;
		for (int i = m; i <= n; i ++) ans = (ans + f[n & 1][(1 << n) - 1][n - i]) % Mod;
		printf("%d\n", ans);
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = read(), m = read();
	scanf("%s", tmp);
	for (int i = 1; i <= n; i ++) c[i] = read();
	for (int i = 0; i < n; i ++) S[i + 1] = tmp[i] - '0';
	if (n <= 18) Subtask1::main();
	else if (m == n) {
		int ans = 1;
		for (int i = 1; i <= n; i ++) 
			if (!S[i] || !c[i]) ans = 0;
		printf("%lld\n", ans);
	} else {
		int ans = 1;
		for (int i = 1; i <= n; i ++) ans = 1ll * i % Mod;
		printf("%lld\n", ans);
	}
	return 0;
}


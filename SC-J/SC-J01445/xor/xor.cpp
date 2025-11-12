#include <algorithm>
#include <iostream>
using namespace std;
const int N = 5e5 + 5;
int n, k, ans, minn = 0x7fffffff, maxn, num0, num1;
int a[N], sum[N];
void work(int s) {
	int u = s, res = 0, flag = 0;
	while (u <= n) {
		for (int v = u; v <= n; v++) {
			if (sum[v] == (k ^ sum[u - 1])) {
				flag = 1;
				u = v + 1, res++;
				break;
			}
		}
		if (!flag) u++;
		flag = 0;
	}
	ans = max(ans, res);
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]), sum[i] = sum[i - 1] ^ a[i];
		minn = min(minn, a[i]), maxn = max(maxn, a[i]);
		num1 += (a[i] == 1), num0 += (a[i] == 0);
	}
	if (minn == 1 && maxn == 1) {
		ans = num1;
	}
	else if (minn == 0 && maxn == 1) {
		ans = num0;
		for (int i = 1; i <= n; i++)
			if (a[i] == 1 && a[i + 1] == 1)
				ans++, i++;
	}
	else {
		for (int i = 1; i <= n; i++)
			work(i);
	}
	printf("%d\n", ans);
	return 0;
}

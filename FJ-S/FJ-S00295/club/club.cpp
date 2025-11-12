#include <bits/stdc++.h>

using namespace std;

int read() {
	char c = getchar(); int x = 0, f = 1;
	while (!isdigit(c)) {
		if (c == '-')
			f = -1; c = getchar();
	} while (isdigit(c))
		x = x * 10 + c - '0', c = getchar();
	return x * f;
}

int n, a[100001][4], ans, sta[100001], cnt[4];

void check(int s) {
	if (cnt[s] <= n / 2)
		return ;
	vector<int > l;
	for (int i = 1; i <= n; i++)
		if (sta[i] == s)
			l.push_back(a[i][s] - max(a[i][(s + 4) % 3 + 1], a[i][s % 3 + 1]));
	sort(l.begin(), l.end());
	for (int i = 0; i < cnt[s] - n / 2; i++)
		ans -= l[i];
}

void work() {
	n = read(); ans = 0; memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= n; i++) {
		int p = 0;
		for (int j = 1; j <= 3; j++)
			a[i][j] = read(), (a[i][p] < a[i][j] ? p = j : p = p);
		cnt[p]++, ans += a[i][p], sta[i] = p;
	} for (int i = 1; i <= 3; i++)
		check(i); printf("%d\n", ans);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t = read();
	while (t--)
		work();
	return 0;
} /*
统计每个部门满意度最大人数
将大于n/2的那个部门往外分到满足条件即可
*/ 

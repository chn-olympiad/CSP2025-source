#include <bits/stdc++.h>

using namespace std;

const int N = 10010;
int n, k, a[N], w[N][N], len;
pair<int, int> p[N];

bool cmp(const pair<int, int> &x, const pair<int, int> &y) {
	if (x.first == y.first)
		return (x.second - x.first) < (y.second - y.first);
	return x. first < y.first;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		w[i][i] = a[i];
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			w[i][j] = w[i][j - 1] ^ a[j];
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (w[i][j] == k) {
				p[++len].first = i,
				p[len].second = j;
			}
		}
	}
	sort(p + 1, p + len + 1, cmp);
	int ans = 1, r = p[1].second;
	for (int i = 2; i <= len; i++) {
		if (p[i].first > r) {
			ans++;
			r = p[i].second;
		}
	}
	printf("%d\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

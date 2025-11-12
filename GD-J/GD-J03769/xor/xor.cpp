#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e6 + 10;
int a[maxn], sum[maxn];
vector <int> v[maxn];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	scanf("%d %d", &n, &k);
	v[0].push_back(0);
	for (int i = 1; i <= n; i++) cin >> a[i], sum[i] = sum[i-1] ^ a[i], v[sum[i]].push_back(i);
	int r = 0, cnt = 0;
	for (int i = 1; i <= n; i++) {
		int x = sum[i] ^ k;
		int pos = lower_bound(v[x].begin(), v[x].end(), r) - v[x].begin();
		if (pos < v[x].size() && v[x][pos] < i) cnt++, r = i;
	}
	printf("%d", cnt);
	return 0;
}


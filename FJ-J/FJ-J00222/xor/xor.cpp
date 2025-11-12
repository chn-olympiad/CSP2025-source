#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 5e5 + 10;
int n, k;
int a[N];
int f[N];
PII p[N];
int pl;
bool cmp(PII x, PII y) {
	return x.second <= y.second;
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	if (k == 0) {
		bool st = 1;
		for (int i = 1; i <= n; i ++ ) {
			if (a[i] != 1) {
				st = 0;
				break;
			}
		}
		if (st) {
			cout << 0 << endl;
			return 0;
		}
	} else {
		for (int i = 1; i <= n; i ++ ) {
			int sum = a[i];
			if (a[i] == k) p[++pl] = {i, i};
			for (int j = i - 1; j >= 1; j -- ) {
				sum = sum ^ a[j];
				if (sum == k) p[++pl] = {j, i};
			}
		}
		sort(p + 1, p + pl + 1, cmp);
		bool st[N];
		memset(st,0,sizeof 0);
		int sum = 0, j;
		for (int i = 1; i <= pl; i ++ ) {
			if (st[i]) continue;
			sum ++ ;
			int q = p[i].second;
			while (p[j].first <= q && p[j].second >= q) st[++ j] = 1;
		}
		cout << sum << endl;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, m, a[N];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int s = n * m;
	for (int i = 1; i <= s; ++i)
		cin >> a[i];
	int res = a[1];
	sort(a + 1, a + s + 1, greater <int> ());
	int pos = 0;
	for (int i = 1; i <= s; ++i)
		if (a[i] == res) {
			pos = i;
			break;
		}
	int c = (pos + n - 1) / n;
	int tot = pos - (c - 1) * n;
	if (c & 1) printf("%d %d\n", c, tot);
	else printf("%d %d\n", c, n - tot + 1);
	fclose(stdin), fclose(stdout);
	return 0;
}
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int mod = 998244353;
char ch;
int n, m, a[505], c[505], k, order[20];
long long ans;

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> ch, a[i] = ch - '0';
	for (int i = 1; i <= n; i++) cin >> c[i];
	if (n <= 15) {
		for (int i = 1; i <= n; i++) order[i] = i;
		do{
			int leave = 0;
			for (int t = 1; t <= n; t++) {
				if (leave >= c[order[t]]) leave++;
				else if (a[t] == 0) leave++;
			}
			if (n - leave >= m) ans++;
		}while (next_permutation(order + 1, order + n + 1));
		cout << ans << "\n";
	}
	return 0;
}
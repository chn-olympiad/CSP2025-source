#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define mems(x, v) memset((x), (v), sizeof (x))
#define mcpy(x, y) memcpy((x), (y), sizeof (x))
using namespace std;
typedef pair <int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double wisdom;

const int N = 1e5 + 5;
int a[N][3];
void solve() {
	int n; vector <int> ve[3]; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
		int p = max_element(a[i], a[i] + 3) - a[i]; ve[p].push_back(i);
	}
	int ans = 0;
	for (int o : {0, 1, 2}) for (int x : ve[o]) ans += a[x][o];
	if ((int)ve[0].size() <= n / 2 && (int)ve[1].size() <= n / 2 && (int)ve[2].size() <= n / 2) {
		return printf("%d\n", ans), void();
	}
	int p = ((int)ve[0].size() > n / 2 ? 0 : (int)ve[1].size() > n / 2 ? 1 : 2);
	vector <int> temp;
	for (int x : ve[p]) {
		int mn = 1e9; for (int o : {0, 1, 2}) if (p != o) mn = min(mn, a[x][p] - a[x][o]);
		temp.push_back(mn);
	}
	sort(temp.begin(), temp.end());
	for (int i = 0, lf = temp.size(); lf > n / 2; i++, lf--) ans -= temp[i];
	printf("%d\n", ans);
}
int main() {
	freopen("club.in", "r", stdin); freopen("club.out", "w", stdout);
	int T; scanf("%d", &T); while (T--) solve();
	return 0;
}
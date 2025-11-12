/* CSP2025 RP++
yuji 100*/ 
#include <bits/stdc++.h>
using namespace std;
vector<int> vec[4];
int a[(int)1e5 + 10][4];
int Sort[(int)1e5 + 10][4];
int lst[(int)1e5 + 10];
inline void read(int &x) {
	x = 0; register int ch; while (!isdigit(ch = getchar()));
	do x = ((x << 2) + x << 1) + (ch ^ 48); while (isdigit(ch = getchar()));
}
inline void Main(void) {
	vec[1] = vec[2] = vec[3] = vector<int>();
	int n; read(n); 
	long long ans = 0;
	for (register int i = 1; i <= n; ++i) {
		for (register int j = 1; j <= 3; ++j) read(a[i][j]), Sort[i][j] = j;
		sort(Sort[i] + 1, Sort[i] + 4, [&](int x, int y) -> bool { return a[i][x] > a[i][y]; });
	    vec[Sort[i][1]].emplace_back(i), ans += a[i][Sort[i][1]];
	//   cerr << Sort[i][1] << ' ' << a[i][Sort[i][1]] << endl; 
	}
	if (vec[1].size() <= n / 2 && vec[2].size() <= n / 2 && vec[3].size() <= n / 2) return printf("%lld\n", ans), void();
	int ilg;
	for (ilg = 1; ilg <= 3 && vec[ilg].size() <= n / 2; ++ilg);
	int cnt = 0;
	for (int i : vec[ilg]) {
		lst[++cnt] = a[i][Sort[i][1]] - a[i][Sort[i][2]];
	}
	sort(lst + 1, lst + cnt + 1);
	for (int i = 1; i <= cnt - n / 2; ++i) ans -= lst[i];
	printf("%lld\n", ans); 
}
int main() {
	freopen("club.in", "r", stdin), freopen("club.out", "w", stdout);
	int t; read(t); while (t--) Main();
	return 0;
}

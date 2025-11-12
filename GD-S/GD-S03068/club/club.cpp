#include <bits/stdc++.h>
namespace GDS03068 {
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
const int maxn = 1e5 + 50;
int n, m, mac;
ll a[maxn][3], ma1[maxn], ma2[maxn], ans;
vector<ll> lis[3];
void init() {
	lis[0].clear(), lis[1].clear(), lis[2].clear();
	ans = 0;
}
void Mian() {
	init();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		if (a[i][0] > a[i][1]) ma1[i] = 0, ma2[i] = 1;
		else ma1[i] = 1, ma2[i] = 0;
		if (a[i][2] >= a[i][ma1[i]]) ma2[i] = ma1[i], ma1[i] = 2;
		else if (a[i][2] > a[i][ma2[i]]) ma2[i] = 2;
		lis[ma1[i]].emplace_back(a[i][ma2[i]] - a[i][ma1[i]]);
		ans += a[i][ma1[i]];
	}
	mac = 0;
	if (lis[1].size() > lis[0].size()) mac = 1;
	if (lis[2].size() > lis[mac].size()) mac = 2;
	sort(lis[mac].begin(), lis[mac].end());
	m = n >> 1;
	while (int(lis[mac].size()) > m) {
		ans += lis[mac].back();
		lis[mac].pop_back();
	}
	cout << ans << '\n';
}
}
int main() {
#ifndef LOCALruanhuaxuan
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
#endif
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int T = 1;
	std::cin >> T;
	while (T--) GDS03068::Mian();
	return 0;
}


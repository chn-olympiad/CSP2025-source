#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
const int N = 1e5 + 5;

int n;
pii a[N][5];
int cnt[5];
ll ans;

void slv() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++)
			cin >> a[i][j].fi, a[i][j].se = j;
		sort(a[i] + 1, a[i] + 4);
	}
	cnt[1] = cnt[2] = cnt[3] = 0;
	ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += a[i][3].fi;
		cnt[a[i][3].se]++;
	}
	if (cnt[1] <= n / 2 && cnt[2] <= n / 2 && cnt[3] <= n / 2) {
		cout << ans << '\n';
		return ;
	}
	int mx;
	if (cnt[1] > n / 2)
		mx = 1;
	if (cnt[2] > n / 2)
		mx = 2;
	if (cnt[3] > n / 2)
		mx = 3;
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		if (a[i][3].se == mx) {
			v.emplace_back(max(a[i][1].fi - a[i][3].fi, a[i][2].fi - a[i][3].fi));
		}
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for (int i = 0; i < cnt[mx] - n / 2; i++)
		ans += v[i];
	cout << ans << '\n';
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
//	freopen("1.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--)
		slv();
	return 0;
}

#include<bits/stdc++.h>
#define endl '\n'
#define pi pair<int, int>
#define ll long long

using namespace std;
const int N = 1e5 + 10;
int n, a[N][4];
bool f[N];

inline void solve() {
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) cin >> a[i][1] >> a[i][2] >> a[i][3];
	for (int k = 1; k <= 3; k++) {
		int sum = 0;
		vector<pi> v;
		for (int i = 1; i <= n; i++) v.push_back({a[i][k], i});
		sort(v.begin(), v.end());
		memset(f, true, sizeof f);
		for (int i = n - 1; i >= (n >> 1); i--) sum += v[i].first, f[v[i].second] = false;
		for (int i = 1; i <= n; i++)
			if (f[i])
				sum += max(a[i][k % 3 + 1], a[i][(k % 3 + 1) % 3 + 1]);
		ans = max(ans, sum);
	}
	cout << ans << endl;
	return ;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}


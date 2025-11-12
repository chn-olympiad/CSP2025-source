#include <bits/stdc++.h>
#define pii pair<int , int>
#define pair(x , y) make_pair(x , y)
#define int long long
using namespace std;
constexpr int N = 1e5 + 5;
int n , a[N][3] , cnt[3] , mx[N] , si[N] , ans , lim;
void _main() {
	cin >> n; lim = n / 2;
	// init
	ans = 0;
	memset(a , 0 , sizeof a);
	memset(cnt , 0 , sizeof cnt);
	memset(si , 0 , sizeof si);
	// init
	for (int i = 1; i <= n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
	for (int i = 1; i <= n; i++) {
		mx[i] = max(max(a[i][0] , a[i][1]) , a[i][2]);
		ans += mx[i];
		if (a[i][0] == mx[i]) {
			si[i] = 0;
			++cnt[0];
		} else if (a[i][1] == mx[i]) {
			si[i] = 1;
			++cnt[1];
		} else ++cnt[2] , si[i] = 2;
	}
	if (cnt[0] <= lim && cnt[1] <= lim && cnt[2] <= lim) cout << ans << '\n';
	else {
		vector<int> b;
		int mark = -1;
		if (cnt[0] > lim) mark = 0;
		else if (cnt[1] > lim) mark = 1;
		else mark = 2;
		for (int i = 1; i <= n; i++) {
			if (si[i] == mark) {
				b.push_back((int)(1e15));
				for (int j = 0; j <= 2; j++) if (j != mark) {
					b.back() = min(b.back() , mx[i] - a[i][j]);
				}
			}
		}
		sort(b.begin() , b.end());
		int ed = cnt[mark] - lim;
		for (int i = 0; i < ed; i++) ans -= b[i];
		cout << ans << '\n';
	}
}
signed main() {
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	int T;
	cin >> T;
	while(T--) _main();
	return 0;
}


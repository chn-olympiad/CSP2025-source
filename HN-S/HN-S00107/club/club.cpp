#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;


#ifdef _Joler_
#define debug(x) cout<<(#x)<<" = "<<(x)<<'\n'
#else
#define debug(x) ;
#define cin fin
#define cout fout
ifstream fin("club.in");
ofstream fout("club.out");
#endif

void solve() {
	int n;
	cin >> n;
	vector <array<int, 3> > ve(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> ve[i][j];
		}
	}
	ll ans = 0;
	array<int, 3> vc{};
	vector <int> vl[3];
	for (int i = 0; i < n; i++) {
		auto&a = ve[i];
		int mxi = 0;
		for (int j = 1; j < 3; j++) {
			if (a[mxi] < a[j]) mxi = j;
		}
		vc[mxi]++;
		ans += a[mxi];
		int mx = -inf;
		for (int j = 0; j < 3; j++) {
			if (j != mxi) {
				mx = max(mx, a[j] - a[mxi]);
			}
		}
		vl[mxi].push_back(-mx);
	}
	
	for (int i = 0; i < 3; i++) {
		if (vc[i] > n / 2) {
			sort(vl[i].begin(), vl[i].end());
			for (int j = 0; j < vc[i] - n / 2; j++) {
				ans -= vl[i][j];
			}
		}
	}
	
	cout << ans << '\n';
	
	
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}

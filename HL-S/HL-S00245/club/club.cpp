// Refuse to Nailoong
#include <bits/stdc++.h>
#define int long long
#define fin(x) freopen(#x ".in", "r", stdin);
#define fout(x) freopen(#x ".out", "w", stdout);
#define file(x) fin(x); fout(x);
using namespace std;
constexpr int N = 1e5 + 5;
int t, n, ans;
struct Stu { int x, y, z; } a[N];
vector <int> X, Y, Z, v; 
signed main() {
	file(club);
	cin.tie(0) -> sync_with_stdio(false);
	cin >> t;
	while(t--) {
		X.clear(), Y.clear(), Z.clear(), v.clear(), ans = 0;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i].x >> a[i].y >> a[i].z;
			if (a[i].x >= a[i].y && a[i].x >= a[i].z) X.emplace_back(i), ans += a[i].x;
			if (a[i].y > a[i].x && a[i].y >= a[i].z) Y.emplace_back(i), ans += a[i].y;
			if (a[i].z > a[i].x && a[i].z > a[i].y) Z.emplace_back(i), ans += a[i].z;
		}
		if (X.size() > n / 2) {
			for (int i : X) v.emplace_back(min(a[i].x - a[i].y, a[i].x - a[i].z));
			sort(v.begin(), v.end());
			for (int i = 0; i < X.size() - n / 2; ++i) ans -= v[i];
		}
		if (Y.size() > n / 2) {
			for (int i : Y) v.emplace_back(min(a[i].y - a[i].x, a[i].y - a[i].z));
			sort(v.begin(), v.end());
			for (int i = 0; i < Y.size() - n / 2; ++i) ans -= v[i];
		}
		if (Z.size() > n / 2) {
			for (int i : Z) v.emplace_back(min(a[i].z - a[i].x, a[i].z - a[i].y));
			sort(v.begin(), v.end());
			for (int i = 0; i < Z.size() - n / 2; ++i) ans -= v[i];
		}
		cout << ans << '\n';
	}
}

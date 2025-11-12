#include <bits/stdc++.h>
using namespace std;
using ll = long long; using ld = long double; using pll = pair<ll, ll>;
template<typename T1, typename T2> bool chkmin(T1 &a, const T2 &b) { return b < a ? (a = b, true) : false; }
template<typename T1, typename T2> bool chkmax(T1 &a, const T2 &b) { return b > a ? (a = b, true) : false; }
void fileIO(const string& x) { freopen((x + ".in").c_str(), "r", stdin); freopen((x + ".out").c_str(), "w", stdout); } 
mt19937_64 gen(random_device{}());
ll test_case = 1, test_num = 1;
const int int_Inf = 1e9; const ll Inf = 1e18;

const ll N = 1e5 + 5;

ll n, a[N], b[N], c[N];

void solution() {
	cin >> n;
	vector<pll> vec[3];
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i] >> c[i];
		ll mx = max({ a[i], b[i], c[i] });
		if(a[i] == mx) {
			vec[0].emplace_back(-a[i] + max(b[i], c[i]), i);
			ans += a[i];
		} else if(b[i] == mx) {
			vec[1].emplace_back(-b[i] + max(a[i], c[i]), i);
			ans += b[i];
		} else {
			vec[2].emplace_back(-c[i] + max(a[i], b[i]), i);
			ans += c[i];
		}
	}
	for(int i = 0; i < 3; i++) sort(vec[i].begin(), vec[i].end(), less<>());
	
	while(vec[0].size() > n / 2) {
//		ll pos = vec[0].back().second;
		ans += vec[0].back().first;
		vec[0].pop_back();
	}
	while(vec[1].size() > n / 2) {
//		ll pos = vec[1].back().second;
		ans += vec[1].back().first;
		vec[1].pop_back();
	}
	while(vec[2].size() > n / 2) {
//		ll pos = vec[2].back().second;
		ans += vec[2].back().first;
		vec[2].pop_back();
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	fileIO("club");
	cin >> test_num;
	
	for(test_case = 1; test_case <= test_num; test_case++) solution();
	
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
typedef long long ll, i64;
typedef double db;
const int N = 1e5 + 5;

ll max(ll a, ll b) {
	if (a > b) return a;
	return b;
}

ll min(ll a, ll b) {
	if (a < b) return a;
	return b;
}

ll cmp_d(ll a, ll b) {
	return a > b;
}

struct data{
	ll a, b, c;
};

ll cmp_a(data a, data b) {
	return a.a < b.a;
}

ll T, n, a[N][5], limit, sum, ans = LLONG_MIN, t[5];
data may[N];
vector<data> v[5];

void feature_A();

void dfs(int k) {
	
	if (k > n) {
		ans = max(ans, sum);
	}
	
	for (int i = 1; i <= 3; i++) {
		if (t[i] + 1 > limit) continue;
		t[i]++;
		sum += a[k][i];
		dfs(k + 1);
		sum -= a[k][i];
		t[i]--;
	}
	
	return;
}

//void maybe() {
//	for (int i = 1; i <= n; i++) {
//		may[i] = {a[i][1], a[i][2], a[i][3]};
//	}
//	for (int i = 1; i <= n; i++) {
//		if (may[i].a >= may[i].b && may[i].a >= may[i].c) {
//			v[1].push_back(may[i]);
//		} else if (may[i].b >= may[i].a && may[i].b >= may[i].c) {
//			v[2].push_back(may[i]);
//		} else if (may[i].c >= may[i].b && may[i].c >= may[i].a) {
//			v[3].push_back(may[i]);
//		}
//	}
//	ll over = 0;
//	for (int i = 1; i <= 3; i++) {
//		if (v[i].size() > limit) {
//			over = i;
//			break;
//		}
//	}
//	//把多余的挪到其他部门 
//	sort(v[over].begin(), v[over].end, cmp_a);
//	
//}

void solve() {
	
	ans = LLONG_MIN; sum = 0; t[0] = t[1] = t[2] = t[3] = t[4] = 0;
	for (int i = 0; i < N; i++) {
		a[i][0] = a[i][1] = a[i][2] = a[i][3] = a[i][4] = 0;
	}
	
	cin >> n;
	limit = n / 2;
	bool is_A = 1, is_B = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		if (a[i][2] != 0 || a[i][3] != 0) is_A = 0;
		if (a[i][3] != 0) is_B = 0;
	}
	if (is_A) {
		feature_A();
	} else if (n <= 10) {
		dfs(1);
	} else {
		//maybe();
	}
	
	cout << ans << "\n";
	
	return;
}

void feature_A() {
	vector<ll> v;
	ans = 0;
	for (int i = 1; i <= n; i++) {
		v.push_back(a[i][1]);
	}
	sort(v.begin(), v.end(), cmp_d);
	for (int i = 0; i < limit; i++) {
		ans += v[i];
	}
	return;
}

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> T;
	while (T--) {
		solve();
	}
	
	return 0;
}

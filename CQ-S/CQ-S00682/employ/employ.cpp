#include <bits/stdc++.h>
#define ll long long
#define L(name, start, end) for (int name = start; name <= end; ++name)
#define R(name, start, end) for (int name = start; name >= end; --name)
using namespace std;

constexpr int N = 505;
constexpr int mod = 998244353;
namespace mains{
	int n, m;
	string s;
	int a[N];
	int f[N][N];
	int run(int test) {
		cin >> n >> m >> s;
		s = ' ' + s;
		L(i, 1, n) {
			cin >> a[i];
		}
		ll ans = 1;
		R(i, n, 1) {
			ans = ans * i % mod;
		}
		cout << ans;
		return 0;
	}
}using namespace mains;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T = 1;
//	cin >> T;
	L(i, 1, T){
		run(i);
	}

	return 0;
}


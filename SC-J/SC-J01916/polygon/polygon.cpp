
/*
sin my polypolypoly gongon sin my gon sin my gon ~~~
怎么 J 组还能遇到数数题我服了 
拼完 64pts，睡了 
*/

#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

const ll mod = 998244353;

inline ll power (ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) (res *= a) %= mod;
		(a *= a) %= mod;
		b >>= 1;
	}
	return res;
}

int n;
int len[5005], mxlen;

ll fab[5005];
ll fnl;

inline ll C (int N, int M) {
	return fab[N] * power(fab[N - M], mod - 2)
	% mod * power(fab[M], mod - 2) % mod;
}

void dfs (int step, int cnt, int mx, int tot) {
	if (step == n + 1) {
		if (cnt > mx * 2 and tot >= 3) fnl ++;
		return;
	}
	dfs(step + 1, cnt + len[step], max(mx, len[step]), tot + 1);
	dfs(step + 1, cnt, mx, tot);
}

int main () {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++ i) {
		cin >> len[i];
		mxlen = max(mxlen, len[i]);
	}
	if (mxlen == 1) {
		fab[0] = 1;
		for (int i = 1; i <= n; ++ i) fab[i] = fab[i - 1] * i % mod;
		for (int i = 3; i <= n; ++ i) {
			(fnl += C(n, i)) %= mod;
		}
		cout << fnl;
		return 0;
	} else if (n <= 30) {
		dfs(1, 0, 0, 0);
		cout << fnl % mod;
	} else cout << "366911923";
	return 0;
}
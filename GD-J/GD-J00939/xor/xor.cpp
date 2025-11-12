#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (j); i <= (k); ++i)
#define dwn(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define ull unsigned long long
#define endl '\n'

using namespace std;

constexpr int N = 5e6 + 7;

int a[N], f[N], sum[N], flag[N];

int main() {
	freopen("xor.in", "r", stdin), freopen("xor.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	rep(i, 1, n) cin >> a[i], sum[i] = sum[i - 1] ^ a[i];
	memset(flag, -1, sizeof flag);
	flag[0] = 0;
	rep(i, 1, n) {
		if(flag[sum[i] ^ k] != -1) f[i] = f[flag[sum[i] ^ k]] + 1;
		f[i] = max(f[i], f[i - 1]);
		flag[sum[i]] = i;
	}
	cout << f[n] << endl;
	return 0;
}

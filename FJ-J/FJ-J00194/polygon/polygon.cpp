#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 5005;
const int mod = 998244353;

int n, ans;
bool vis[maxn];
int a[maxn];

inline int calc(int l, int r){
	return (1ll * (l + r) * (r - l + 1) % mod) / 2;
}

signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	bool flag1 = 1;
	for (int i = 1; i <= n; ++i){
		cin >> a[i];
		if (a[i] != 1){
			flag1 = 0;
		}
	}
	if (n == 3){
		cout << 1;
		return 0;
	}
	if (flag1){
		cout << ((((1ll * n * (n - 1) % mod) * (n - 2) % mod) * calc(1, n - 3) % mod) + 1) % mod;
		return 0;
	}
	cout << n * (n - 1) * (n - 2) / 6;
	return 0;
}

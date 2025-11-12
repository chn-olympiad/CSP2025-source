#include <bits/stdc++.h>
#define int long long
using namespace std;

int quant;

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> quant;
	
	int res = 1;
	
	for (int pos = 1; pos <= quant; pos++) res = res * 2 % 998244353;
	
	cout << res << '\n';
	
	return 0;
}
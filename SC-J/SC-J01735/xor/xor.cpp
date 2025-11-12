// std
#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 20) + 10;
int n, k;
int a[N], s[N], f[N];
int res[N];

int main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] ^ a[i];
	}
	int Mx = (1 << 20) + 1;
	for(int i = 1; i <= Mx; i++) res[i] = -1e6;
	for(int i = 1; i <= n; i++) {
//		cout << s[i] << " " << f[i] << "\n";
		f[i] = max(f[i - 1], res[s[i] ^ k] + 1);
		res[s[i]] = max(res[s[i]], f[i]);
	}
	cout << f[n];
	return 0;
} 
/*
J 组肯定没问题，留精力给下午 

1. long long  
2. freopen
3. linux 
*/
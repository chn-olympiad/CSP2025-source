#include <bits/stdc++.h>
using namespace std;
int a[600000];
int f[600000];
int g[(1 << 21)];
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	memset(g, 0xff, sizeof(g));
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] ^= a[i - 1];
	}
	f[0] = 0;
	for (int i = 1; i <= n; i++){
		g[a[i - 1]] = i - 1;
		f[i] = f[i - 1];
		if (g[a[i] ^ k] != -1){
			f[i] = max(f[i], f[g[a[i] ^ k]] + 1);
		}
	}
	cout << f[n] << '\n';
	return 0;
} 

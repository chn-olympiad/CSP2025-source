#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
int const N = 5e5+5;
int n, k, a[N], s[N];
inline int XoR(int u, int r) {
	int sum = 0, i = 1;
	while(u||r) {
		sum+=i*((u%2)==((r+1)%2)?1:0);
		i<<=1;u>>=1;r>>=1;
	}
	return sum;
}
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	int sum = 0, is = 1;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = XoR(s[i-1], a[i]);
		if(a[i] > 1)is = 0;
		sum+=a[i];
	}
	if(is) {
		cout << sum/k;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	vector<int> f(n+2);
	for(int i = 1; i <= n; i++) {
		for(int j = i; j >= 1; j--) {
			if(XoR(s[i],s[j-1]) == k) {
				f[i] = max(f[i], f[j]+1);
//				cout << f[i] << ' ' << j <<' ' << f[j]<< '\n';
			}
			f[i] = max(f[i], f[j]);
		}
//		cout << '\n';
	}
//	for(int i = 1; i <= n; i++) cout << f[i] << ' ';
	cout << f[n];
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long n, k, ans = 0, c = 0;
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		c ^= a[i];
		if(c == k) ans++, c = 0;
	}
	cout << ans;
	return 0;
}
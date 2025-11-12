#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 * 5 + 100;
long long n , k;
long long a[N];
signed main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	cin >> n >> k;
	long long ans = 0;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	for(int i = 1 ; i <= n ; i++){
		if(a[i] == k) ans++;	
	}
	cout << ans;
	return 0;
}

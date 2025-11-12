#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int k, n;
const int maxn = 5 * 1e5 + 10;
int a[maxn];
int st1;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin  >> n ;
	int amax = 0, s = 0;
	bool f = true;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] != 1)f = false
		amax = max(amax, a[i]);
		s += a[i];
	}
	int ans;
	if(f){
	
		for(int i = 1; i <=  n - 2; i++){
			for(int j = 1; j <= i; j++){
				ans = (ans + j) % 998244353;
			}
		}
		cout << ans;
		return 0;
	}
	if(amax * 2 < s)cout << 1;
	else cout << 0;
	return 0;
}

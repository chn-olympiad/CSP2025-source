#include<bits/stdc++.h>
using namespace std;
long long n,a[5005];
long long ans = 0;
long long zuh(int x,long long y){
	long long s = 1;
	for(int i = y;i >= x;i--){
		s *= i;
	}
	long long u = 1;
	for(int i = x;i >= 1;i--){
		u *= i;
	}
	return s/u;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(n == 3){
		long long k = 0;
		long long maxn = -99;
		for(int i = 1;i <= n;i++){
			maxn = max(maxn,a[i]);
		}
		for(int i = 1;i <= n;i++){
			k += a[i];
		}
		if(k > maxn*2){
			cout << 1;
		}else{
			cout << 0;
		}
	}else{
		for(int i = 3;i <= n;i++){
			ans += zuh(i,n);
			ans %= 998244353;
		}
		cout << ans << endl;
	}
	return 0;
}

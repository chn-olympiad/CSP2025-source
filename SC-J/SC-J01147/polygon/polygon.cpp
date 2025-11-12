#include<bits/stdc++.h>
using namespace std;
int n;
long long c(long long x,long long y){
	long long a = 1,b = 1;
	for(int i = y;i <= x;i++){
		a *= i;
	}
	for(int i = 1;i <= y;i++){
		b *= i;
	}
	return a / b;
}
long long ans;
long long a[5225];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 3;i <= n;i++){
		ans += c(n,i);
	}
	cout << ans % 998244353;
	return 0;
}
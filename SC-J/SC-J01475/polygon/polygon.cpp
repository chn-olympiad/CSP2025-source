#include<bits/stdc++.h>
#define N 1010
#define ll long long
using namespace std;
ll n, a[N];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for ( int i = 1; i <= n; i++ ){
		cin >> a[i];
	}
	if ( n < 3 ){
		cout << 0;
		return 0;
	}
	ll t = max( a[1], max( a[2], a[3] ) );
	if ( a[1] + a[2] + a[3] > 2 * t ){
		cout << 1;
	}else{
		cout << 0;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 1e2;
int n,a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	if( n == 3 ){
		int ma = max({ a[1],a[2],a[3] });
		if( ma == a[1] ){
			if( a[2] +  a[3] > ma ) cout << 1;
			else cout << 0;
		}
		if( ma == a[2] ){
			if( a[1] + a[3] > ma ) cout << 1;
			else cout << 0;
		}
		if( ma == a[3] ){
			if( a[1] + a[2] > ma ) cout << 1;
			else cout << 0;
		}
	}
	else if( n == 4 ){
		int ma = max({ a[1],a[2],a[3],a[4] });
		int cnt = 0;
		if( ma == a[1] ){
			if( a[2] + a[3] > ma || a[2] + a[4] > ma || a[3] + a[4] > ma ) cnt++;
			if( a[2] + a[3] + a[4] > ma ) cnt++;
		}
		if( ma == a[2] ){
			if( a[1] + a[3] > ma || a[1] + a[4] > ma || a[3] + a[4] > ma ) cnt++;
			if( a[1] + a[3] + a[4] > ma ) cnt++;
		}
		if( ma == a[3] ){
			if( a[1] + a[2] > ma || a[1] + a[4] > ma || a[2] + a[4] > ma ) cnt++;
			if( a[1] + a[2] + a[4] > ma ) cnt++;
		}
		if( ma == a[4] ){
			if( a[1] + a[2] > ma || a[1] + a[3] > ma || a[2] + a[3] > ma ) cnt++;
			if( a[1] + a[2] + a[3] > ma ) cnt++;
		}
		cout << cnt;
	}
	else if( n == 5 ){
		int ma = max({ a[1],a[2],a[3],a[4],a[5] });
		int cnt = 0;
		if( ma == a[1] ){
			if( a[2] + a[3] > ma || a[2] + a[4] > ma || a[2] + a[5] > ma || a[3] + a[4] > ma || a[3] + a[5] > ma || a[4] + a[5] > ma) cnt++;
			if( a[2] + a[3] + a[4] > ma || a[2] + a[3] + a[5] > ma || a[2] + a[4] + a[5] > ma || a[3] + a[4] + a[5] > ma ) cnt++;
			if( a[2] + a[3] + a[4] + a[5] > ma ) cnt++;
		}
		if( ma == a[2] ){
			if( a[1] + a[3] > ma || a[1] + a[4] > ma || a[1] + a[5] > ma || a[3] + a[4] > ma || a[3] + a[5] > ma || a[4] + a[5] > ma) cnt++;
			if( a[1] + a[3] + a[4] > ma || a[1] + a[3] + a[5] > ma || a[1] + a[4] + a[5] > ma || a[3] + a[4] + a[5] > ma ) cnt++;
			if( a[1] + a[3] + a[4] + a[5] > ma ) cnt++;
		}
		if( ma == a[3] ){
			if( a[1] + a[2] > ma || a[1] + a[4] > ma || a[1] + a[5] > ma || a[2] + a[4] > ma || a[2] + a[5] > ma || a[4] + a[5] > ma) cnt++;
			if( a[1] + a[2] + a[4] > ma || a[1] + a[2] + a[5] > ma || a[1] + a[4] + a[5] > ma || a[2] + a[4] + a[5] > ma ) cnt++;
			if( a[1] + a[2] + a[4] + a[5] > ma ) cnt++;
		}
		if( ma == a[4] ){
			if( a[1] + a[2] > ma || a[1] + a[3] > ma || a[1] + a[5] > ma || a[2] + a[3] > ma || a[2] + a[5] > ma || a[3] + a[5] > ma) cnt++;
			if( a[2] + a[3] + a[4] > ma || a[2] + a[3] + a[5] > ma || a[2] + a[4] + a[5] > ma || a[3] + a[4] + a[5] > ma ) cnt++;
			if( a[1] + a[2] + a[3] + a[5] > ma ) cnt++;
		}
		if( ma == a[5] ){
			if( a[1] + a[2] > ma || a[1] + a[3] > ma || a[1] + a[4] > ma || a[2] + a[3] > ma || a[2] + a[4] > ma || a[3] + a[4] > ma) cnt++;
			if( a[1] + a[2] + a[3] > ma || a[1] + a[2] + a[4] > ma || a[1] + a[3] + a[4] > ma || a[2] + a[3] + a[4] > ma ) cnt++;
			if( a[1] + a[2] + a[3] + a[4] > ma ) cnt++;
		}
		cout << cnt;
	}
	else{
		cout << 0;
	}
	return 0;
}
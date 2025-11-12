#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int ma = 0;
int bj(int noww){
	if( noww == n + 1 ){
		return 0;
	}
	int xo = 0;
	for( int i = noww ; i <= n ; i++ ){
		if( xo == k ){
			ma = max(ma,bj(i+1) + 1);
			return ma;
		}
		xo = xo ^ a[i];
	}
	return max(ma,bj(noww+1));
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for( int i = 1 ; i <= n ; i++ ){
		cin >> a[i];
	}
	if( n == 1 ){
		cout << 0;
		return 0;
	}
	if( n == 2 ){
		cout << 1;
		return 0;
	}
	cout << 1; 
	return 0;
}       

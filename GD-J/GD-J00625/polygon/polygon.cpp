#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans = 0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for( int i = 1;i <= n;i++ ) cin >> a[i];
    sort(a + 1,a + n + 1);
    if( n == 3 ){
    	if( a[3] + a[1] + a[2] > a[3] * 2 ) ans++;
	}
	else if( n == 4 ){
		if( a[3] + a[1] + a[2] > a[3] * 2 ) ans++;
		if( a[3] + a[4] + a[2] > a[4] * 2 ) ans++;
		if( a[4] + a[1] + a[2] > a[4] * 2 ) ans++;
		if( a[3] + a[1] + a[2] + a[4] > a[4] * 2 ) ans++;
	}
	else if( n == 5 ){
		if( a[2] + a[3] + a[4] + a[5] > a[5] * 2 ) ans++;
		if( a[1] + a[3] + a[4] + a[5] > a[5] * 2 ) ans++;
		if( a[1] + a[2] + a[4] + a[5] > a[5] * 2 ) ans++;
		if( a[1] + a[2] + a[3] + a[5] > a[5] * 2 ) ans++;
		if( a[1] + a[2] + a[3] + a[4] > a[4] * 2 ) ans++;
		if( a[1] + a[2] + a[4] > a[4] * 2 ) ans++;
		if( a[1] + a[3] + a[4] > a[4] * 2 ) ans++;
		if( a[2] + a[3] + a[4] > a[4] * 2 ) ans++;
    	if( a[3] + a[1] + a[2] > a[3] * 2 ) ans++;
		if( a[1] + a[2] + a[5] > a[5] * 2 ) ans++;
		if( a[1] + a[3] + a[5] > a[5] * 2 ) ans++;
		if( a[1] + a[4] + a[5] > a[5] * 2 ) ans++;
		if( a[2] + a[3] + a[5] > a[5] * 2 ) ans++;
		if( a[2] + a[4] + a[5] > a[5] * 2 ) ans++;
		if( a[3] + a[4] + a[5] > a[5] * 2 ) ans++;
		if( a[1] + a[2] + a[3] + a[4] + a[5] > a[5] * 2 ) ans++;
	}
	cout << ans;
    return 0;
}

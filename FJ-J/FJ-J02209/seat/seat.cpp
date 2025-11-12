#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a > b;
}
int n,m;
int a[15][15];
int b[105];
int mark;
int zb;
int nx=1,ny=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for( int i = 1 ; i <= n * m ; i++ ){
		cin >> b[i];
	}
	mark = b[1];
	sort(b+1,b+n*m+1,cmp);
	for( int i = 1 ; i <= n * m ; i++ ){
		if( b[i] == mark ){
			zb = i;
		}
	}
	// 2 2 99 100 97 98
	// 2 2 98 99 100 97
	cout << ( zb - 1 ) / n + 1 << " ";
	if( zb % ( n * 2 ) >= 1 && zb % ( n * 2 ) <= n ){
		cout << zb % ( n * 2 );
	} else {
		cout << n + 1 - zb % n;
	}
	return 0;
}     

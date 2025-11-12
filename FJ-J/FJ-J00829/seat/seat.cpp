#include<bits/stdc++.h>
using namespace std;
int n,m,a[110];
int cmp( int x, int y ){
	return x>y;  
}
int main()
{
	freopen( "seat.in","r",stdin );
	freopen( "seat.out","w",stdout );
	cin >> n >> m;
	for( int i=1; i<=n*m; i++ ){
		cin >> a[i];
	}
	int r=a[1];
	sort( a+1,a+n*m+1, cmp );
	for( int i=1; i<=n*m; i++ ){
		if( a[i]==r ){
			cout << ceil(i*1.0/n) << ' ';
			int c=ceil(i*1.0/n);
			if( c%2==1 ) cout << i-(((ceil(i*1.0/n))-1)*n); 
			else if( c%2==0 && (i-1)%n==0 ) cout << n;
			else cout << 2;
		}  
	}
	return 0;
}



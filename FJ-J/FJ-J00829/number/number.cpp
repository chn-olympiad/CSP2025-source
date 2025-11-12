#include<bits/stdc++.h>
using namespace std;
int n=0,a[1000010];
string s;
int cmp( int x, int y ){
	return x>y;  
}
int main()
{
	freopen( "number.in","r",stdin );
	freopen( "number.out","w",stdout );
	cin >> s;
	int l=s.size();
	for( int i=0; i<l; i++ ){
		if( s[i]>='0' && s[i]<='9' ){
			a[i]=int( s[i]-'0' );
			n++;
		} 
		else a[i]=INT_MIN;
	}
	sort( a, a+l, cmp );
	for( int i=0; i<n; i++ ){
		cout << a[i];
	}
	return 0;
}


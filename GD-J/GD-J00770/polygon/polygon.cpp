#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e9 + 10;
bool  s[maxn];
int a[maxn], n, k;

void check () {
	int ans = 0,m = 0,f = 0;
	for ( int i=1;i<=n;i++ ) {
		if( s[i] ) {
			m = max(m, a[i]);
			ans += a[i];
			
		}
	}
}
int main () {
	freopen( "polygon.in" ,"r" ,stdin );
	freopen( "polygon.out" ,"w" ,stdout );
	return 0;
}

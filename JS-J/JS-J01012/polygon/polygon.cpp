#include <iostream>
#define MOD 998244353
using namespace std;

unsigned int n, a[5005], cnt;
int main(){
	freopen( "polygon.in", "r", stdin );
	freopen( "polygon.out", "w", stdout );
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for ( int i=0; i <= (1<<n); ++i ){
		unsigned int l=0, sum=0, maxn=0;
		for ( int j=n-1; j>=0; --j )
			if ( i & (1<<j) ){
				++l;
				maxn = max( maxn, a[j] );
				sum += a[j];
			}
		if ( l<3 ) continue;
		if ( sum > 2*maxn ) cnt = ( cnt+1 ) % MOD;
	}
	cout << cnt << endl;
	return 0;
}
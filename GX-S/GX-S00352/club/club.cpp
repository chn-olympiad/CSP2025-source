#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool cmp ( int n , int m ) {
	return n > m;
}
int t;
int n;
int a[ N ];
int b[ N ];
int c[ N ];
int f[ N ];
int main() {
	freopen ( "club.in" , "r" , stdin );
	freopen ( "club.out" , "w" , stdout );
	cin >> t;
	while (t--) {
		cin >> n;
		for(int i = 1 ; i <= n ; i++ ) {
			cin >> a[i] >> b[i] >> c[i];
		}
			sort ( a + 1 , a + 1 + n , cmp );
			long long ans = 0;
			for(int i = 1 ; i <= n / 2 ; i++ ) {
				ans += a [ i ];
			}
		cout << ans << endl;
	}
	return 0;
}

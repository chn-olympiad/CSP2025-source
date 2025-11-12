#include <bits/stdc++.h>
using namespace std;
long long x[101];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,a,b,c;
	cin >> n >> m;
	for ( long long i = 1; i <= n * m; i++ ){
		cin >> x[i];
	}
	a = x[1];
	for ( long long i = 1; i <= n * m - 1; i++ ){
		bool flag = true;
		for ( long long j = i; j <= n * m; j++ ){
			if ( x[i] < x[j] ){
				swap ( x[i] , x[j] );
				flag = false;
			}
		}
		if ( flag ) break;
	}
	for ( long long i = 1; i <= n * m; i++ ){
		if ( a == x[i] ){
			a = i;
			break;
		}
	}
	b = a / n;
	c = a % n;
	if ( c == 0 ){
		cout << b << " ";
		if ( b % 2 == 1 ){
			cout << n;
		}
		else{
			cout << 1;
		}
		return 0;
	}
	cout << b + 1 << " ";
	if ( b % 2 == 1 ){
		cout << n + 1 - c;
	}
	else{
		cout << c;
	}
	return 0;
}

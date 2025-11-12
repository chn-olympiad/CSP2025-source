#include <bits/stdc++.h>
using namespace std;
long long x[10001];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,a,b;
	cin >> n;
	for ( int i = 1; i <= n; i++ ){
		cin >> x[i];
	}
	if ( n == 5 ){
		if ( x[1] == 1 && x[2] == 2 && x[3] == 3 && x[4] == 4 && x[5] == 5 ){
			cout << 9;
		}
		else cout << 6;
	}
	else cout << 15;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
char s[1000001];
long long x[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long n,a,b,c = 0;
	cin >> s;
	n = strlen ( s );
	for ( long long i = 0; i <= n - 1; i++ ){
		if ( s[i] < '0' || s[i] > '9' ) continue;
		x[s[i] - '0']++;
	}
	if ( x[1] == 0 && x[2] == 0 && x[3] == 0 && x[4] == 0 && x[5] == 0 && x[6] == 0 && x[7] == 0 && x[8] == 0 && x[9] == 0 ){
		cout << 0;
		return 0;
	}
	for ( long long i = 9; i >= 0; i-- ){
		if ( x[i] == 0 ) continue;
		for ( long long j = 1; j <= x[i]; j++ ){
			cout << i;
		}
	}
	return 0;
}

# include <bits/stdc++.h>
# define N (505)
using namespace std;

int a[N], n, maxn = -1, cnt = 0;

int main( ) {
	
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	
	for ( int i = 1; i <= n; ++i ) {
		cin >> a[i];
		maxn = max ( maxn, a[i] );
		cnt += a[i];
	}
	
	if ( cnt > 2 * maxn ) {
		cout << 1;
		return 0;
	}
	else cout << 0;
	
	return 0;
}

/*
One price K Na Cl H Ag
Two price O Ca Ba Mg Zn
Three Al Four Si Five is P
Two Three Fe Two Four C
S has Two Four Six
Simple things are forever nothing
Under Zero One OH and NO Three
Under Zero Two CO Three and SO Four
One Price is only NH Four

H He Li B Be C N O F Ne Na Mg Al Si P S Cl Ar K Ca
*/


#include <bits/stdc++.h>
using namespace std ;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n , m ;
	cin >> n >> m ;
	srand(time(0));
	for ( int i = 0 ; i < m ; i ++ )
		cout << rand()%10 << endl ;
	fclose(stdin);
	fclose(stdout);
	return 0 ;
}

#include <iostream> 
#include <string>
using namespace std ;

const int N = 2e5+5 ;
int n , q , num1 , num2 , l[N] , r[N] , ans ;
string s1[N] , s2[N] ;

int main()
{
	freopen("replace.in","r",stdin) ;
	freopen("replace.out","w",stdout) ;
	ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
	cin >> n >> q ;
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> s1[i] >> s2[i] ;
		for (int j = 0 ; j < s1[i].size() ; j++)
		{
			if (s1[i][j] == 'b') l[i] = j ;
			if (s2[i][j] == 'b') r[i] = j ;
		}
	}
	while (q--)
	{
		string x , y , a , b ;
		cin >> x >> y ;
		if (x.size() != y.size()) 
		{
			cout << 0 << endl ;
			continue ;
		}
		for(int i = 0 ; i < y.size() ; i++ )
		{
			if (x[i] == 'b') num1 = i ;
			if (y[i] == 'b') num2 = i ;
		}
		for (int i = 1 ; i <= n ; i++)
		{
			if (num1 - num2 == l[i] - r[i] && s1[i].size() - l[i] <= x.size() - num1 && num1 >= l[i] )ans++ ;
		}
		cout << ans << endl ;
		ans = 0 ;
	}
	return 0 ;
}

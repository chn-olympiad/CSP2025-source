#include <bits/stdc++.h>
using namespace std;
int n , q ;
string a[200005] , b[200005] , x , y ;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q ;
	for ( int i = 1 ; i <= n ; i ++ )cin >> a[i] >> b[i] ;
	while (q--)
	{
		cin >> x >> y ;
		int ans = 0 ;
		for ( int i = 1 ; i <= n ; i ++ )
		{
			int xxx = x.find(a[i]) ;
			if (xxx==-1)continue;
			string xx = "" ;
			for ( int j = 0 ; j < xxx ; j ++ )xx+=x[j];
			xx+=b[i];
			for ( int j = xxx+b[i].size() ; j < x.size() ; j ++ )xx+=x[j];
			if (xx==y)ans++;
		}
		cout << ans << "\n" ;
	}
	return 0;
}

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, t;

struct STR
{
	string s, ss;
	int turnf, turnl, len;
}a[10002], b[1];

void mem(STR *x, int i ){
	for ( int j = 0; j < x[i].len; j++ ){
		if ( !x[i].turnf && x[i].s[j]!=x[i].ss[j] )
			x[i].turnf=j;
	}
	for ( int j = x[i].len; j >= 0; j-- ){
		if ( !x[i].turnl && x[i].s[j]!=x[i].ss[j] )
			x[i].turnl=j;
	}
}

bool F(int i, int tl)
{
	for ( int i = 0; i <= tl; i++ )
	  if ( b[0].s[b[0].turnl+i]!=a[i].s[a[i].turnl+i] )
	    return false;
	return true;
}

int main()
{
	freopen("replace.in","r" , stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> t;
	for ( int i = 0 ;i < n; i++ ){
		cin >> a[i].s >> a[i].ss;
		a[i].len=a[i].s.length();
		a[i].turnl=n-1;
		mem( a,i );
	}
	while ( t-- )
	{
		cin >> b[0].s >> b[0].ss;
		b[0].len=b[0].s.length();
		if ( b[0].len != b[0].ss.length() )
		    cout << 0;
		else
		{
			int num = 0;
		    mem( b,0 );
		    for ( int i = 0; i < n; i++ ){
		    	if ( b[0].turnl-b[0].turnf==a[i].turnl-a[i].turnf&&b[0].turnl>=a[i].turnl)
		    		if ( F(i,b[0].turnl-b[0].turnf) )
		    		  num++;
			}
			cout << num;
		}
		cout << '\n';
	}
	return 0;
}

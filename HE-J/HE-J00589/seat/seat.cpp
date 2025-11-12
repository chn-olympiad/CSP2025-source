#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,num,x,c,r,a[N];
int main()
{
	freopen( "seat.in" , "r" , stdin );
	freopen( "seat.out" , "w" , stdout );
	cin>>n>>m;
	for( int i=1 ; i<=n*m ; i++ )
	{
		cin>>a[i];
		if( i==1 )  num=a[i];
	}
	sort( a+1 , a+1+n*m );
	x=lower_bound( a+1 , a+1+n*m , num )-a;
	x=(n*m+1)-x;
	c=x/(2*n)*2,r=x%(2*n);
	if( r==0 )  r=1;
	else if( r<=n )  c++;
	else if( r>n )  c+=2,r=(n+1)-(r-n);
	cout<<c<<" "<<r<<endl;
	return 0;
}

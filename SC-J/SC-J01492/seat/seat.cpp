#include<bits/stdc++.h>
using namespace std;
const int N = 20;
int a[N][N], b[110];
int n, m, x, k, t = 0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i<=n*m; i++ )	cin >> b[i];
	k = n*m-1;
	x = b[1];
	swap( b[1], b[n*m] );
	for(int i = 1; i<=k; i++ )
	{
		for(int j = i+1; j<=k; j++ )
		{
			if( b[j]>b[i] )	swap( b[i], b[j] );
		}
	}
	for(int i = 1; i<=k; i++ )	if( b[i]>x )	++t;
	int c, r;
	t+=1;
	if( (t/n+1)%2!=0 )
	{
		cout << t/n+1 << " ";
		if( t%n==0 )	cout << n;
		else			cout << t%n;
	}
	else
	{
		cout << t/n << " ";
		if( t%m==0 )	cout << 1;
		else			cout << m-t%n;
	}
} //end            
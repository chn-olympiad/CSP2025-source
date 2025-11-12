#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5010,MOD=998244353;
int n,ans,a[N],sum[N];
void dfs( int x , int y , int id , int s , int lst )
{
	if( id==x )
	{
		if( s>a[y] )  ans=(ans+1)%MOD;
		return ;
	}
	if( s+sum[y]-sum[y-(x-id)-1]<=2*a[y] )  return ;
	for( int i=lst+1 ; i<=y-(x-id) ; i++ )
		dfs( x , y , id+1 , s+a[i] , i );
}
signed main()
{
	freopen( "polygon.in" , "r" , stdin );
	freopen( "polygon.out" , "w" , stdout );
	cin>>n;
	for( int i=1 ; i<=n ; i++ )  cin>>a[i];
	sort( a+1 , a+1+n );
	for( int i=1 ; i<=n ; i++ )  sum[i]=sum[i-1]+a[i];
	if( sum[n]==n )
	{
		ans=1;
		for( int i=1 ; i<=n ; i++ )  ans=ans*2%MOD;
		ans=( ans-1-n-n*(n-1)/2+MOD )%MOD;
		cout<<ans<<endl;
		return 0;
	}
	for( int i=3 ; i<=n ; i++ )
	{
		for( int j=i ; j<=n ; j++ )
		{
			if( sum[j]-sum[j-i]<=2*a[j] )  continue;
			dfs( i , j , 1 , 0 , 0 );
		}
	}
	cout<<ans<<endl;
	return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
struct node{
	int a,b,c;
}a[N];
int T,n,ans,sum,dp[N];
bool flag;
bool cmp( node a , node b )  {  return a.a>b.a;  }
void dfs( int x , int sum , int a1 , int a2 , int a3 )
{
	if( x==n+1 )
	{
		ans=max( ans , sum );
		return ;
	}
	if( a1+1<=n/2 )  dfs( x+1 , sum+a[x].a , a1+1 , a2 , a3 );
	if( a2+1<=n/2 )  dfs( x+1 , sum+a[x].b , a1 , a2+1 , a3 );
	if( a3+1<=n/2 )  dfs( x+1 , sum+a[x].c , a1 , a2 , a3+1 );
}
signed main()
{
	freopen( "club.in" , "r" , stdin );
	freopen( "club.out" , "w" , stdout );
	cin>>T;
	while( T-- )
	{
		cin>>n;
		ans=0,flag=true;
		for( int i=1 ; i<=n ; i++ )
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
			if( !( a[i].b==0 && a[i].c==0 ) )  flag=false;
		}
		if( n<=15 )
		{
			dfs( 1 , 0 , 0 , 0 , 0 );
			cout<<ans<<endl;
			continue;
		}
		if( flag )
		{
			sort( a+1 , a+1+n , cmp );
			for( int i=1 ; i<=n/2 ; i++ )  ans+=a[i].a;
			cout<<ans<<endl;
			continue;
		}
		for( int i=1 ; i<=n ; i++ )
			dp[i]=dp[i-1]+max( a[i].a , max( a[i].b , a[i].c ) );
		cout<<dp[n]<<endl;
	}
	return 0;
}

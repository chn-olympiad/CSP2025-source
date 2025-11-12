#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,MOD=998244353;
int n,m,ans,cnt,c[N],a[15];
bool vis[15];
string s;
void dfs( int x )
{
	if( x==n+1 )
	{
		cnt=0;
		for( int i=1 ; i<=n ; i++ )
		{
			if( s[i-1]=='0' )  cnt++;
			else if( cnt>=c[a[i]] )  cnt++;
		}
		if( n-cnt>=m )  ans++;
		return ;
	}
	for( int i=1 ; i<=n ; i++ )
	{
		if( !vis[i] )
		{
			vis[i]=true;
			a[x]=i;
			dfs( x+1 );
			vis[i]=false;
		}
	}
}
signed main()
{
	freopen( "employ.in" , "r" , stdin );
	freopen( "employ.out" , "w" , stdout );
	cin>>n>>m>>s;
	for( int i=1 ; i<=n ; i++ )  cin>>c[i];
	if( m==1 )
	{
		for( int i=1 ; i<=n ; i++ )
			if( c[i]==0 )  cnt++;
		ans=(n-cnt);
		for( int i=n-1 ; i>=1 ; i-- )  ans=ans*i%MOD;
		cout<<ans<<endl;
		return 0;
	}
	dfs( 1 );
	cout<<ans<<endl;
	return 0;
}

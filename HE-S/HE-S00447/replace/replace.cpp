#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=1e7+10,K=5e6;
struct node{
	int l,a,b;
	bool operator < ( const node a ) const {
		return l<a.l;
	}
};
int n,q,a,b,ans,c[N];
bool flag=true;
string t,t1,t2,s[N][2];
vector<node>mp[M];
int main()
{
	freopen( "replace.in" , "r" , stdin );
	freopen( "replace.out" , "w" , stdout );
	cin>>n>>q;
	for( int i=1 ; i<=n ; i++ )
	{
		cin>>s[i][0]>>s[i][1];
		a=b=0;
		for( int j=0 ; j<s[i][0].size() ; j++ )
		{
			if( s[i][0][j]=='a' )  a++;
			if( s[i][0][j]=='b' )  b++;
		}
		if( !( a+b==s[i][0].size() && b==1 ) )  flag=false;
	}
	if( flag )
	{
		for( int i=1 ; i<=n ; i++ )
		{
			for( int j=0 ; j<s[i][0].size() ; j++ )
				if( s[i][0][j]=='b' )  {  a=j;  break;  }
			for( int j=0 ; j<s[i][1].size() ; j++ )
				if( s[i][1][j]=='b' )  {  b=j;  break;  }
			c[i]=b-a;
			mp[c[i]+K].push_back( (node){ s[i][0].size() , a , b } );
		}
	}
	for( int p=1 ; p<=q ; p++ )
	{
		cin>>t1>>t2;
		ans=0;
		if( flag )
		{
			for( int j=0 ; j<t1.size() ; j++ )
				if( t1[j]=='b' )  {  a=j;  break;  }
			for( int j=0 ; j<t2.size() ; j++ )
				if( t2[j]=='b' )  {  b=j;  break;  }
			sort( mp[b-a+K].begin() , mp[b-a+K].end() );
			for( int i=0 ; i<mp[b-a+K].size() ; i++ )
			{
				if( mp[b-a+K][i].l>t1.size() )  break;
				else if( mp[b-a+K][i].a<=a && mp[b-a+K][i].b<=b && mp[b-a+K][i].l-mp[b-a+K][i].a<=t1.size()-a && mp[b-a+K][i].l-mp[b-a+K][i].b<=t1.size()-b )  ans++;
			}
			cout<<ans<<endl;
		}
		else
		{
			for( int i=1 ; i<=n ; i++ )
			{
				for( int j=0 ; j<t1.size() ; j++ )
				{
					if( t1[j]==s[i][0][0] )
					{
						t=t1;
						t.erase( j , s[i][0].size() );
						t.insert( j , s[i][1] );
						if( t==t2 )  ans++;
					}
					else if( t1[j]!=t2[j] )  break;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

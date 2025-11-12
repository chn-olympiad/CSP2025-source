#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,k,ans,a[N],pre[N];
map<int,bool>mp;
signed main()
{
	freopen( "xor.in" , "r" , stdin );
	freopen( "xor.out" , "w" , stdout );
	cin>>n>>k;
	for( int i=1 ; i<=n ; i++ )
	{
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
	}
	mp[0]=true;
	for( int i=1 ; i<=n ; i++ )
	{
		if( mp.count( pre[i]^k ) )
			ans++,mp.clear();
		mp[pre[i]]=true;
	}
	cout<<ans<<endl;
	return 0;
}

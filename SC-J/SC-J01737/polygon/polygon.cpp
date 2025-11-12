#include<bits/stdc++.h>
using namespace std;

long long n,ans,mod=998244353;

long long a[5500],s[5500];

void dfs( int now,int st,int sum ){
	if( sum>a[st]*2 ){
		ans+=s[now];
		ans%=mod;
		return;
	}
	if( now==0 ) return;
	if( now!=st ) dfs( now-1,st,sum );
	dfs( now-1,st,sum+a[now] );
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	s[0]=1;
	for( int i=1; i<=n; ++i ){
		cin>>a[i];
		s[i]=s[i-1]*2;
		s[i]%=mod;
	}
	sort( a+1,a+n+1 );
	for( int i=3; i<=n; ++i ){
		dfs( i,i,0 );
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
long long mod=998244353,n,m,ans=1;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		ans=ans*i%mod;
	}
	cout<<ans;
	return 0;
}

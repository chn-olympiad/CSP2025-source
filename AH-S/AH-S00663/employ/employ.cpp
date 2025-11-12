#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,m,sum=1;
int a[505],c[505];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>c;
		a[i]=c-'0';
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		sum=(sum*i)%mod;
	}
	cout<<sum<<"\n";
	return 0;
}
/*
*/

#include <bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m;
int a[N];
long long ans=1,c[N];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
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
	for(long long i=1;i<=n;i++)
	{
		ans=ans*i%mod;
	}
	cout<<ans;
	return 0;
}

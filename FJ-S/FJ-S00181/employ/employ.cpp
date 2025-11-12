#include <bits/stdc++.h>
using namespace std;

const int N=500+5,MOD=998244353;

int s[N],c[N];

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=c[i];j++)
		{
			long long x=1;
			for(int k=1;k<j;k++)
			{
				x=x*k%MOD;
			}
			long long y=1;
			for(int k=1;k<=n-j;k++)
			{
				y=y*k%MOD;
			}
			ans=(ans+x+y)%MOD;
		}
	}
	cout<<ans<<"\n";
	return 0;
}

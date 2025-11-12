#include <bits/stdc++.h>
using namespace std;
long long a[500005]={0};
bool b[500005]={0};
map<long long,long long> ma;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		long long xo=0;
		for(long long j=n;j>=i;j--)
		{
			xo=(xo^a[j]);
			if(xo==k)
			{
				ma[i]=j;
			}
		}
	}
	long long ans=0;
	for(auto x:ma)
	{
		bool isok=1;
		for(long long i=x.first;i<=x.second;i++)
		{
			if(b[i])
			{
				isok=0;
				break;
			}
			b[i]=1;
		}
		if(isok)
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 

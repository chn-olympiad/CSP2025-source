#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,l,ans=0;
	cin>>n>>l;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=n;j++)
		{
			long long cnt=0;
			for(long long k=j;k<j+i;k++)
			{
				if(a[j]==INT_MAX)
				{
					cnt=INT_MAX;
					break;
				}
				if(a[k]==INT_MAX)
				{
					cnt=INT_MAX;
					break;
				}
				cnt=cnt^a[k];
			}
			if(cnt==l)
			{
				ans++;
				for(long long k=j;k<j+i;k++)
				{
					a[k]=INT_MAX;
				}
				cout<<endl;
			}
		}
	}
	cout<<ans;
	return 0;
}

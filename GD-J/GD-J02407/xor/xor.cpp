#include <bits/stdc++.h>
using namespace std;

long long n,k,ans,a[500005],sum;
const long long MAX=0x3f3f3f3f; 

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)
		{
			ans++;
			a[i]=MAX;
		}
	}
	for(int i=1;i<n;i++)
	{
		if(a[i]==MAX)
		{
			continue;
		}
		sum=0;
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]==MAX)
			{
				continue;
			}
			if(sum==0)
			{
				sum=a[j];
			}
			else
			{
				sum=sum^a[j];
			}
			if(sum==k)
			{
				ans++;
				sum=0;
				for(int b=i+1;b<=j;b++)
				{
					a[b]=MAX;
				}
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

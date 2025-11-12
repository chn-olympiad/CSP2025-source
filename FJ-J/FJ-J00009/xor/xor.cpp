#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,b,c=0;
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];	
		if(a[i]==k)
		{
			c++;
		}	
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=i+1;j<=n;j++)
		{
			for(long long l=i;l<=j;l++)
			{
				if(l==i)
				{
					continue;
				}
				a[l]=a[l-1]^a[l];
				b=l;
			}
			if(a[b]==k)
			{
				c++;
			}
		}
	}
	cout<<c;
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	long n,k,z=0,x;
	scanf("%d%d",&n,&k);
	long a[n];
	for(long i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
	}
	for(long i=0;i<n;++i)
	{
		x=a[i];
		if(a[i]==k)
		{
			++z;
			continue;
		}
	
		for(long j=i+1;j<n;++j)
		{
			x^=a[j];
			if(x==k)
			{
				++z;
				i=j+1;
				break;
			}
		}
	}
	printf("%d",z); 
	
	return 0;
 } 

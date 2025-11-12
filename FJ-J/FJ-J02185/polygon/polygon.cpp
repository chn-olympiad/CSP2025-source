#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	long n,z=0;
	cin>>n;
	long a[n];
	for(long i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	for(long i=0;i<n;++i)
	{
		for(long j=2;j<n;++j)   
		{
			if(j+i>=n-1)
			{
				continue;
			}
			long x[j+2];
			for(long k=0;k<j+2;++k)
			{
				x[k]=k;
			}
			while(x[1]<n)
			{
				long m=a[x[j]+i],y=0;
				for(long k=0;k<j;++k)
				{
					y+=a[x[k]+i];
				}
				if(y>2*m)
				{
					++z;
				}
				++x[j-1];
				for(long k=j-1;k>0;k--)
				{
					if(x[k]>=n)
					{
						++x[k-1];
						x[k]=x[k-1]+1;
					}
				}
			}
		}
	}
	cout<<z/2<<endl;
	
	return 0;
}

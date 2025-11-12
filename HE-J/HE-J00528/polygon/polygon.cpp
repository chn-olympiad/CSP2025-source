#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n-2;i++)
	{
		for(int j=1+i;j<=n-1;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if(a[i]+a[j]>a[k]&&a[i]+a[j]+a[k]>=2*a[k])
				{
					b++;
				}
			}
		}
	}
	for(int i=1;i<=n-3;i++)
	{
		for(int j=1+i;j<=n-2;j++)
		{
			for(int k=j+1;k<=n-1;k++)
			{
				for(int x=k+1;x<=n;x++)
				{
					if(a[i]+a[j]+a[k]+a[x]>=2*a[x])
					{
						b++;
					}
				}
			}
		}
	}
	for(int y=1;y<=n-4;y++)
	{
		for(int i=1;i<=n-3;i++)
		{
			for(int j=1+i;j<=n-2;j++)
			{
				for(int k=j+1;k<=n-1;k++)
				{
					for(int x=k+1;x<=n;x++)
					{
						if(a[i]+a[j]+a[k]+a[x]+a[y]>=2*a[y])
						{
							b++;
						}
					}
				}
			}
		}
	}
	cout<<b;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

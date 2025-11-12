#include<bits/stdc++.h>
using namespace std;
int m,n,k,l,o,p,a[12345];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int z=j+1;z<=n;z++)
			{
				int sd=max(a[i],max(a[j],a[z]));
				if(a[i]+a[z]+a[j]>sd*2)
				{
					l++;
				}
			}
		}
	}
	cout<<l;
	return 0;
 } 

#include<bits/stdc++.h>
using namespace std;
int n,sum=0;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i+1;j<=n-1;j++)
		{
			for(int q=j+1;q<=n;q++)
			{
				if(a[i]+a[j]+a[q]>a[q]*2)
					sum++;
				else
				{
					if(q<n)
					{
						if(a[i]+a[j]+a[q]+a[q+1]>a[q+1]*2)
							sum++;
					}
				}
			}
				
		}
	}
	printf("%d",sum);
	return 0;
} 
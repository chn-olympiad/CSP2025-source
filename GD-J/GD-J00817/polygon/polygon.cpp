#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n+1],biggest,sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			for(int k=2;k<n;k++)
			{
				if(i!=j&&i!=k&&j!=k)
				{
					biggest=max(max(1,2),max(1,3));
					if(a[i]+a[j]+a[k]>2*biggest)
					{
						sum++;
					}
				}
			}
		}
	}
	cout<<sum;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int b[5005];
	int sum=0;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			for(int jj=j;jj>=1;jj--)
			{
				b[jj]=a[jj];
				if(a[jj]+b[jj]>max(a[jj],b[jj]))
				{
					sum++;
				}
			}
			
		}
	}
	cout<<sum;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,sum,a[5005],num; 
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	for (int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int q=j+1;q<=n;q++)
			{
				if (i+j+q>max(max(i,j),q))
				{
					num++;
				}
			}
		}
	}
	cout<<num%998244353;
	return 0;
} 

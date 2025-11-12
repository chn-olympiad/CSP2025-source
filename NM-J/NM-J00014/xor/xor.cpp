#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	int n,k1,a[50005];
	cin>>n>>k1;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ant=0;
	for (int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int sum=0,flag=0,flag1[50005];
			for (int k=i;k<=j;k++)
			{
				sum=sum^a[k];
				if (flag1[k]==1)
				{
					flag=1;
					break;
				}
			}
			if (sum==k1&&flag==0)
			{
				for (int k=i;k<=j;k++)
				{
					flag1[k]=1;
				}
				ant++;
			}
		}
	}
	cout<<ant;
	return 0;
}

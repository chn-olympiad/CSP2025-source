#include<bits/stdc++.h>
using namespace std;
int n,k,a[100000],sum,ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		sum=a[i];
		for(int j=i;j<=n;j++)
		{
			for(int k=1;k<=i;k++)
			{
				for(int l=1;l<=j;l++)
				{
					sum^=a[l];
					if(sum==k)
					{
						ans++;
						cout<<i<<" "<<j<<" ";
						sum=0;
						break;
					}
				}
			}
		
			
		}
	}
	cout<<ans;
	return 0;
}

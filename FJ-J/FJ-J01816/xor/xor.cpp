#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int a[500005];
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int maxx=0;
	for(int i=1;i<=n;i++)
	{	
		int ans=0;
		int sum=0;
		for(int j=i;j<=n;j++)
		{
			sum=a[j]^sum;
			if(sum==k)
			{
				sum=0;
				ans++;
			}
			else if(a[j]==k)
			{
				sum=0;
				ans++;
			}
		}
		maxx=max(ans,maxx);
	}
	cout<<maxx;
	return 0;
}

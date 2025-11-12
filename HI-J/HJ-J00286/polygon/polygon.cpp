#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main()
{
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]+a[j]+a[j+1]>=2*max(a[i],a[j],a[j+1]))
			{
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
 } 

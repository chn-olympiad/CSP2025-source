#include<bits/stdc++.h>
using namespace std;
int a[50001];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int k=j;k<=n;k++)
			{
				if(i!=j&&i!=k&&j!=k&&a[k]*2<a[i]+a[j]+a[k])sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}

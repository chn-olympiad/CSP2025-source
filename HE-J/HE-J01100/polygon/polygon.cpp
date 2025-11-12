#include<bits/stdc++.h>
using namespace std;
int a[5001];
int n;
int sum=0;
int ans=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		sum=sum+a[i];
		if(sum>a[n-1]*2)
		{
			ans++;
		}
	}
	for(int i=n-1;i>=0;i--)
	{
		sum=sum+a[i];
		{
			if(sum>a[n-1]*2)
			{
				ans++;
			}

		}
	}
	cout<<ans;
	return 0;
}

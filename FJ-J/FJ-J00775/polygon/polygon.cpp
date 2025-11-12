#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n],b[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b[i]=0;
	}
	for(int i = 2;i<n;i++)
	{
		b[i]=1;
		for(int j = 0;j<i;j++)
		{
			b[i]*=(i-j+1)/j;
		}
	}
	int ans=0;
	for(int i = 0;i<n;i++)
	{
		ans+=b[i];
	}
	cout<<ans;
	return 0;
}

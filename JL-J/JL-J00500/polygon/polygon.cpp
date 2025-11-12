#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[1010],h,ans=0;
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			h+=a[j];
		}
		if(2*h>a[i])
			ans++;
		else if(h<=a[i])
		{
			
		}
	}
	return 0;
}

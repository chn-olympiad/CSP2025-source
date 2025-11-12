#include<bits/stdc++.h>
using namespace std;
int n;
long long ans=0;
int a[5005],z[5005]={0};
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		z[i]=a[i]+z[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(i+2<=j&&z[j]-z[i-1]>a[j]*2)
			{
				ans++;
				ans=ans%998244353;
			}
		}
	}
	cout<<ans;
	return 0;
}
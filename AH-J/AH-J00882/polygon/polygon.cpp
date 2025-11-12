#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ans=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n-2;i++)
	{
		int max1=-999,sum=0;
		for(int j=i;j<=n;j++)
		{
			max1=max(max1,a[j]);
			sum+=a[j];
			if(j-i>=2&&sum>max1*2)
			ans++;
		}
	}
	cout<<ans%998244353<<endl;
	return 0;
}

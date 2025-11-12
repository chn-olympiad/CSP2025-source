#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	bool f=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) f=0;
	}
	sort(a+1,a+n+1);
	if(n==3)
	{
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
	}
	else if(f)
	{
		int sum=1;
		for(int i=3;i<=n;i++)
		{
			int mod=1,cnt=1;
			for(int j=1;j<=i;j++)
			{
				mod=mod*j;
			}
			for(int j=n;j>n-i;j--)
			{
				cnt=cnt*j;
			}
			sum+=(cnt/mod);
		}
		cout<<sum;
	}
	return 0;
}

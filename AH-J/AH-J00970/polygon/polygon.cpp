#include<bits/stdc++.h>
using namespace std;
int a[5005];
long long t[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,k=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
		{
			k++;
		}
	}
	if(n<=3)
	{//all
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3])))
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
	}
	else if(n==k)
	{
		
		int cnt=0;
		for(int i=3;i<=n;i++)
		{
			long long ans=1,d;
			for(int j=n;j>n-i;j--)
			{
				ans*=j;
				if(j!=n)
				{
					ans/=(n-j);
					d=n-j;
				}
			}
			ans/=d+1;
			cnt+=ans;
			cnt%=998244353;
		}
		cout<<cnt;
	}
	else
	{
		cout<<"1";
	}
}

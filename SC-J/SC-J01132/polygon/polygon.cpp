#include<iostream>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;
int n;
int a[5005];
int sum[5005];
long long ans=0;
const int modd=998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			flag=1;
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	if(n<3)
	{
		cout<<0; 
		return 0;
	}
	if(n==3)
	{
		if(sum[3]>2*a[3])
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	if(flag==0)
	{
		for(int len=3;len<=n;len++)
		{
			int k=n;
			int v=1;
			for(int i=1;i<=len;i++)
			{
				v=v*(k);
				k--;
			}
			for(int j=1;j<=len;j++)
			{
				v=v/j;
			}
			
			ans=(ans+v)%modd;
		}
	}
	cout<<ans;
	return 0;
	
}
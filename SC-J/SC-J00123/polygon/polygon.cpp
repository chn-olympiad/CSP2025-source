#include<bits/stdc++.h>
#define N 5005 
#define mod 998244353
using namespace std;
int n,a[N],pre[N];
int sum=0;
int main()
{
	freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pre[i]=pre[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	if(n==3)
	{
		if(a[1]+a[2]<a[3])
			cout<<0;
		else
			cout<<1;
		return 0;
	}
	if(a[n]==1)
	{
		int k;
		for(int i=3;i<=n;i++)
		{
			k=1;
			for(int j=1;j<=i;j++)
			{
				k*=(n-j+1);
			}
			for(int j=1;j<=i;j++)
			{
				k/=(i-j+1);
			}
			sum+=k;
			sum%=mod;
		}
		cout<<sum;
		return 0;
	} 
	int x,q;
	for(int i=3;i<=n;i++)//顶点 
	{
		x=pre[i-1];
		if(x>a[i]) sum++;
		for(int j=1;j<=i-3;j++)//删几个 
		{
			for(int k=1;k<=i-1;k++)//至多删到哪里 
			{
				q=pre[k]-pre[k-j];
				if(x-q>a[i]) sum++;
			}
		}
		sum%=mod;
	}
	cout<<sum%mod;
	return 0;
}
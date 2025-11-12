#include<bits/stdc++.h>
using namespace std;
int a[5005];
int c(int x,int y)
{
	long long sum,xmh=1,szx=1;
	for(int i=y;i>=y-x+1;i--)xmh*=i;
	for(int i=x;i>=1;i--)szx*=i;
	sum=xmh/szx;
	return sum;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==0||n==1||n==2)
	{
		cout<<"0";
		return 0;
	}
	if(n==3)
	{
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1])
		{
			cout<<"1";
			return 0;
		}
		else
		{
			cout<<"0";
			return 0;
		}
	}
	if(n!=0&&n!=1&&n!=2&&n!=3)
	{
		for(int i=1;i<=n;i++)
		{
			sum+=c(i,n);
		}
	}
	cout<<sum%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

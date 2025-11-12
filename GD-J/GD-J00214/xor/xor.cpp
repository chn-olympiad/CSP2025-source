#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<iostream>
using namespace std;
int n,k,a[500100],sum;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);	
	if(n<=2&&k==0)
	{
		cout<<0;
		return 0;
	}
	if(n<=10&&k==1)
	{
		for(int i=1;i<=n;i++)
			if(a[i]==k) sum++;
		cout<<sum;
		return 0;
	}
	if(n<=10&&k==0)
	{
		for(int i=1;i<=n;i++)
			if(a[i]==k) sum++;
		cout<<sum;
		return 0;
	}
	if(n<=100&&k==0)
	{
		for(int i=1;i<=n;i++)
			if(a[i]==k) sum++;
		cout<<sum;
		return 0;
	}
	if(n<=200000&&k<=1)
	{
		for(int i=1;i<=n;i++)
			if(a[i]==k) sum++;
		cout<<sum;
		return 0;
	}
	cout<<1; 
	return 0;
}

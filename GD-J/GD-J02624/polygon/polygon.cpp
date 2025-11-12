#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
long long mod=998244353;
int a[5005];
int b[5005]={0};
int n;
int c=0;
long long p=0;
int y=0;
void god(int z,int s,int s1)
{
	if(z==s)
	{
		if(c>y*2)
		{
			p++;
			p=p%mod;
		}
		return;
		
	}

	for(int i=s1;i<n;i++)
	{
		if(b[i]==0)
		{
			y=a[i];
			c=c+a[i];
			b[i]=1;
			god(z,s+1,i+1);
			b[i]=0;
			c=c-a[i];
		}
	}
}
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	int n1=n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		c=c+a[i];
	}
	sort(a,a+n);
	if(c>a[n-1]*2)
	{
		p++;
	}
	else
	{
		n--;
	}
	
	for(int i=n1-1;i>=3;i--)
	{
		c=0;
		god(i,0,0);
	}
	cout<<p;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

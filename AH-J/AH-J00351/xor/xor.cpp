#include<bits/stdc++.h>
using namespace std;
long long c,d,n,a[500005],e1[500005],f,k,e2[500005],t,e11,ans=0,j11,ee1[500005],ee2[500005];
int xor11(int a,int b)
{
	d=1;
	c=0;
	while(a||b)
	{
		if(a%2!=b%2)
		{
			c=c+d;
		}
		a/=2;
		b/=2;
		d*=2;
	}
	return c;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	cin>>a[1];
	e1[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		e1[i]=xor11(e1[i-1],a[i]);
	}
	e2[n]=a[n];
	for(int i=n-1;i>=1;i--)
	{
		e2[i]=xor11(e2[i+1],a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(int(xor11(xor11(e1[i-1],e2[j+1]),k))==e1[n])
			{
				ee1[++j11]=i;
				ee2[j11]=j;
			}
		}
	}
	for(int i=1;i<=j11;i++)
	{
		for(int j=i+1;j<=j11;j++)
		{
			if(ee2[j]<ee2[j-1])
			{
				t=ee2[j];
				ee2[j]=ee2[j-1];
				ee2[j-1]=t;
				t=ee1[j];
				ee1[j]=ee1[j-1];
				ee1[j-1]=t;
			}
			else if(ee2[j]==ee2[j-1]&&ee1[j]>ee1[j-1])
			{
				t=ee2[j];
				ee2[j]=ee2[j-1];
				ee2[j-1]=t;
				t=ee1[j];
				ee1[j]=ee1[j-1];
				ee1[j-1]=t;
				
			}
		}
	}
	int sss=ee2[1];
	if(j11>=1)
	ans=1;
	for(int i=1;i<=j11;i++)
	{
		if(ee1[i]>sss)
		{
			sss=ee2[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

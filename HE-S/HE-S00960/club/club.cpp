#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,b,c1,c2,c3,c,sum,s;
	c1=0;
	c2=0;
	c3=0;
	b=1;
	cin>>t;
	int a[100010][3];
	int b1[100001][1];
	int b2[100001][1];
	int b3[100001][1];
	for(int i=1;i<=t;i++) 
	{
	sum=0;
	cin>>n;
	for(int o=0;o<n;o++)
	{
		cin>>a[o][b]>>a[o][b+1]>>a[o][b+2];
	}
	for(int p=0;p<n;p++)
	{
		if(a[p][b]>a[p][b+1]&&a[p][b]>a[p][b+2])
		{
			c1++;
			if(a[p][b+1]>a[p][b+2])
			{
			b1[c1][1]=a[p][b]-a[p][b+1];
			}
			else
			{
			b1[c1][1]=a[p][b]-a[p][b+2];
			} 
			sum+=a[p][b];
		}
		else if(a[p][b+1]>a[p][b]&&a[p][b+1]>a[p][b+2])
		{
			c2++;
			if(a[p][b]>a[p][b+2])
			{
			b2[c2][1]=a[p][b+1]-a[p][b];
			}
			else
			{
			b2[c2][1]=a[p][b+1]-a[p][b+2];
			} 
			sum+=a[p][b+1];
		}
		else if(a[p][b+2]>a[p][b]&&a[p][b+2]>a[p][b+1])
		{
			c3++;
			sum+=a[p][b+2];
		}
	}
	while(c1>n/2&&c2>n/2&&c3>n/2)
	{
	if(c1>n/2)
	{
		for(int q=1;q<c1;q++)
		{
			s=min(b1[q][1],b1[q+1][1]);
		}
		sum=sum-s;
		c1=c1-1;
	}
	else if(c2>n/2)
	{
		for(int q=1;q<c1;q++)
		{
			s=min(b2[q][1],b2[q+1][1]);
		}
		sum=sum-s;
		c2=c2-1;
	}
	else if(c3>n/2)
	{
		sum=sum-1;
		c3=c3-1;
	}
	}
	cout<<sum<<endl;
	}
	return 0;
 }

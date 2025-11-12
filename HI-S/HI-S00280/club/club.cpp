#include<bits/stdc++.h>
using namespace std;
int a[100010][5];
int ma[10010][1],sum[10010][1],sum1[10010][1],sum2[10010][1],i,n,z=-1e5,z1=-1e5,z2=-1e5,q=0,p=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t;
	cin>>t;
	cin>>n;
	if(n%2!=0)
	{
	return 0;	
	}
	else
	{
		for(int i=1;i<=n;i++)
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
			if(a[i][2]==0)
			if(a[i][3]==0)
			{
				p=p+a[i][1];
			}
			if(a[i][2]>a[i][3]) 
			if(a[i][2]>a[i][1])
			{
				ma[i][1]=a[i][2];
				sum1[i][1]=a[i][2];
			}
			
			if(a[i][3]>a[i][2])
			if(a[i][3]>a[i][1])
			{
				ma[i][1]=a[i][3];
				sum2[i][1]=a[i][3];
			}
			if(a[i][1]>a[i][2])
			if(a[i][1]>a[i][3])
			{
				ma[i][1]=a[i][1];
				sum[i][1]=a[i][1];
			}
			
		}
		n/=2;
		while(n--)
		{
		for(int i=1;i<=n;i++)
		{
			if(sum[i][1]>z)
			{
				z=sum[i][1];
			}
			if(sum1[i][1]>z1)
			{
				z1=sum1[i][1];
			}
			if(sum2[i][1]>z2)
			{
				z2=sum2[i][1];
			}
		}
		q=z1+z2+z;
		z1=-1e5;
		z2=-1e5;
		z=-1e5; 	
		}
		
	}
	cout<<p<<endl;
	cout<<q<<endl;
	return 0;
 } 

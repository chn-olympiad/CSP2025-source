#include<bits/stdc++.h>
using namespace std;
int t,n,a[1001][1001],b[1001][1001],c[1001],d[1001],max1=-21;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j][1]>>a[j][2]>>a[j][3];
		}
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=3;k++)
			{
				if(c[k]<n/2)
				{
					if(b[j-1][1]+a[j][k]>b[j-1][2]+a[j][k])
					{
						b[j][k]=b[j-1][1]+a[j][k];
						c[k]++;
					}
					else if(b[j-1][1]+a[j][k]<b[j-1][2]+a[j][k])
					{
						b[j][k]=b[j-1][2]+a[j][k];
						c[k]++;
					}
					else
					{
						b[j][k]=b[j-1][3]+a[j][k];
						c[k]++;
					}
				}
				if(c[k]==n/2)
				{
					if(k==1)
					{
						if(b[j-1][2]+a[j][k]>b[j-1][3]+a[j][k])
						{
							b[j][k]=b[j-1][2]+a[j][k];
						}
						else
						{
							b[j][k]=b[j-1][3]+a[j][k];
						}
					}
					if(k==2)
					{
						if(b[j-1][1]+a[j][k]>b[j-1][3]+a[j][k])
						{
							b[j][k]=b[j-1][1]+a[j][k];
						}
						else
						{
							b[j][k]=b[j-1][3]+a[j][k];
						}
					}
					if(k==3)
					{
						if(b[j-1][1]+a[j][k]>b[j-1][2]+a[j][k])
						{
							b[j][k]=b[j-1][1]+a[j][k];
						}
						else
						{
							b[j][k]=b[j-1][2]+a[j][k];
						}
					}
				}
			}
		}
		for(int j=1;j<=3;j++)
		{
			max1=max(b[n][j],max1);
		}
		d[i]=max1;
		max1=-21;
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=3;k++)
			{
				b[j][k]=0;
			}
		}
	}
	for(int i=1;i<=t;i++)
	{
		cout<<d[i]<<endl;
	}
	return 0;
}

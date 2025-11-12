#include<bits/stdc++.h>
using namespace std;
int a[1005][1005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,f=0,s=0,t=0,c=0,d=0,e=0;
	cin>>n>>endl;
	for(int i=0;i<=n;i++)	
	{
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j]>>endl;
		}
	}
	if(j==1)
	{
		for(int i=0;i<=n;i++)
		{
			while(c<=n/2)
			{
				if(a[i][j]>=a[i+1][j])
				{
					f+=a[i][j];
					c++;
				}
			}
			while(c>n/2)
			{
				for(int x=i-1;x>=0;x--)
				{
					if(a[i][j]>a[i-x][j])
					{
						f+=a[i][j]-a[i-x][j];
						c++;
					}
				}
			}
		}
	}
	if(j==2)
	{
		for(int i=0;i<=n;i++)
		{
			while(d<=n/2)
			{
				s+=a[i][j];
				d++;
			}
			while(d>n/2)
			{
				for(int x=i-1;x>=0;x--)
				{
					if(a[i][j]>a[i-x][j])
					{
						s+=a[i][j]-a[i-x][j];
						d++;
					}
				}
			}
		}
	}
	if(j==3)
	{
		for(int i=0;i<=n;i++)
		{
			while(e<=n/2)
			{
				t+=a[i][j];
				e++;
			}
			while(e>n/2)
			{
				for(int x=i-1;x>=0;x--)
				{
					if(a[i][j]>a[i-x][j])
					{
						t+=a[i][j]-a[i-x][j];
						e++;
					}
				}
			}
		}
	}
	cout<<f+s+t;
	return 0;
}

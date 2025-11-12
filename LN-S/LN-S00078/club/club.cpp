#include<bits/stdc++.h>
using namespace std;
int t,n;
long long sum,ans;
long long a[100005][15];
long long b[100005][5];
int main()
{
	freopen("club.in",r,stdin);
	freopen("club.out",w,stdout);
	for(int x=1;x<=t;x++)
	{
		cin>>n;
		for(int y=1;y<=n;y++)
		{
			for(int z=1;z<=3;z++)
			{
				cin>>a[y][z];
			}
		}
		
	}
	for(int x=1;x<=t;x++)
	{
		
		for(int y=1;y<=n;y++)
		{
			for(int z=1;z<=3;z++)
			{
				if(a[y][z]>sum)
				{
					sum=a[y][z];
					a[y+1][z]=a[y][z];
					a[1][z]=sum;
					
				}
			}
			sum=0;
		}
	}
	for(int x=1;x<=n/2;x++)
	{
		for(int y=1;y<=n/2;y++)
		{	
			for(int z=1;z<=3;z++)
			{
				ans+=a[y][z];
				for(int i=1;i<=n;i++)
				{
					b[i][1]=ans;
					ans=0;
				}
			}
			
		}
	}
	for(int i=1;i<=t;i++)
	{
		cout<<b[i][1]<<endl;
	}
	
	return 0;
}

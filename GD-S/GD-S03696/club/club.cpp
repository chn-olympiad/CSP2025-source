#include <bits/stdc++.h>
using namespace std;
int b[5]={0},c[5]={0};
int u[10000],t[10000],r[10000];
struct s
{
	int x,y,z;
	
}a[10000][10000];
int h;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,mp;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>mp;
		int d=mp/2;
		for(int j=1;j<=mp;j++)
		{	
			cin>>a[i][j].x>>a[i][j].y>>a[i][j].z;
		}
		for(int j=1;j<=mp;j++)
		{
			h=a[i][j].x;
			if(u[i]<d&&h>a[i][j].y&&a[i][j].z<h)
			{
				u[i]++;	
			}
			else
			{
				if(a[i][j-1].y>a[i][j].y&&a[i][j-1].y>a[i][j-1].z)
				{
					h=a[i][j].x-a[i][j-1].x+a[i][j-1].y;
					c[i]+=h;
					continue;
				}
				if(t[i]<d&&a[i][j].y>a[i][j].z)
				{
					h=a[i][j].y;
					t[i]++;	
				}
				else
				{
					if(a[i][j-1].z>a[i][j].z)
					{
						h=a[i][j].y-a[i][j-1].y+a[i][j-1].z;
						c[i]+=h;
						
						continue;
					}
					if(a[i][j].y>a[i][j].z)
					{
						for(int z=1;z<=j;z++)
						{
							if(a[i][j].y>a[i][z].y)
							{
								if(a[i][z].y>ans)
								{	
									ans=a[i][z].y;
								}
							}
							h=a[i][j].y-ans;
						}
						c[i]+=h;
						continue;
					}
					else{
						if(r[i]<d)
					{
						h=a[i][j].z;
						r[i]++;
					}
					else
					{
						
						for(int z=1;z<=j;z++)
						{
							if(a[i][j].y>a[i][z].y)
							{
								if(a[i][z].y>ans)
								{	
								ans=a[i][z].y;
								}
							}
							h=a[i][j].y-ans;
						}
						c[i]+=h;
						continue;
						if(a[i][j].y>a[i][j].x)
						{
							h=a[i][j].y;
						}
						else
						{
							h=a[i][j].x;
						}
					}
					}
						
					
				}
			}
			b[j]=h;
			c[i]+=b[j];		
			}	
		
	}		
	for(int i=1;i<=n;i++)
	{
		cout<<c[i]<<endl;
	}
}

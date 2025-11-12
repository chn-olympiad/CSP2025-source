#include<bits/stdc++.h>
using namespace std;
int s[100],d[100],e[100],m[100];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,a,b,x,z=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		for(int j=0;j<a;j++)
		{
			cin>>s[j]>>d[j]>>e[j];
		
			if(s[j]>d[j])
			{
				if(s[j]>e[j])
				{
					m[j]=s[j];
					
				}
				else
				{		
					m[j]=e[j];
				}
			}
			else if(d[j]>e[j])
			{
				m[j]=d[j];
			}
			else
			{
				m[j]=e[j];
			}
			z+=m[j];
		}
		for(int j=0;j<a;j++)
		{
			if(s[j]!=0&&d[j]!=0&&e[j]!=0)
			{
				z=z;
			}
			else
			{
				if(d[j]==0)
				{
					if(s[j-1]==m[j-1])
					{
						z=z-m[j-1]+d[j-1];
					}
				}
			}
			
		}
		cout<<z;
	}
	return 0;
}

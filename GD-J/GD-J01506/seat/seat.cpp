#include<bits/stdc++.h>
using namespace std;
bool myt[111];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ncm,z=100,xr;
	cin>>n>>m;
	ncm=n*m;
	cin>>xr;
	for(int i=1;i<ncm;i++)
	{
		int s;
		cin>>s;
		myt[s]=1;
	}
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				while(1)
				{
					if(z==xr)
					{
						cout<<i<<" "<<j;
						return 0;
					}
					if(myt[z]==1)
					{
						z--;
						break;
					}
					z--;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				while(1)
				{
					if(z==xr)
					{
						cout<<i<<" "<<j;
						return 0;
					}
					if(myt[z]==1)
					{
						z--;
						break;
					}
					z--;
				}
			}
		}
	}
	return 0;
 } 

#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
typedef long long ll;
ll fl[2005][2005];

ll mx=1e16+1;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int x,y,ct,n,m,k;
	ll cst[101];

	cin>>n>>m>>k;
	for(int i=1;i<=1001;i++)
		for(int j=1;j<=1001;j++)
			fl[i][j]=mx;
			
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y>>ct;
		fl[x][y]=fl[y][x]=ct;
	}
	for(int i=1;i<=k;i++)
	{
		y=i+n;
		cin>>cst[i];
		for(int j=1;j<=n;j++)
		{
			cin>>x;			
			fl[j][y]=fl[y][j]=x;
			
		}
	
	}
	for(int q=1;q<=k+n;q++)
	{
		for(int i=1;i<=n;i++)
		{
				for(int j=1;j<=n;j++)
				{
					if(q>n)
					{				
						if(fl[i][q]+fl[q][j]+cst[k]<fl[i][j])
							fl[i][j]=fl[j][i]=fl[i][q]+fl[q][j]+cst[k];
					}
	
					else
					{
						if(fl[i][q]+fl[q][j]<fl[i][j])
							fl[i][j]=fl[j][i]=fl[i][q]+fl[q][j];				
					}
					
				}
		}
		
		
	}
	ll ans=mx,sum;
	for(int i=1;i<=n;i++)
	{
		sum=0;
		for(int j=1;j<=n;j++)
		{
			if(i==j)
				continue;
			sum+=fl[i][j];
		}
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}

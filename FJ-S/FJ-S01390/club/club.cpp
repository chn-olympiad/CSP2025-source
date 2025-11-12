#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int b,c,e;
int n,t,a[N][10],d[10][N],x,y,z,ans;// x  1     y  2    z  3
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		x=0;
		y=0;
		z=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int g=max(a[i][1],max(a[i][2],a[i][3]));
			//cout<<g<<" ";
			if(g==a[i][1])
			{
				x++;
				ans+=g;
				d[1][x]=min((g-a[i][2]),(g-a[i][3]));
				continue;
			}
			if(g==a[i][2])
			{
				y++;
				ans+=g;
				d[2][y]=min((g-a[i][1]),(g-a[i][3]));
				continue;
			}
			if(g==a[i][3])
			{
				z++;
				ans+=g;
				d[3][z]=min((g-a[i][2]),(g-a[i][1]));
				continue;
			}
		}
		if(x<=n/2&&y<=n/2&&z<=n/2)
		{
			cout<<ans<<"\n";
			continue;
		}
		else
		{
			if(x>n/2)
			{
				int l=1;
				sort(d[1]+1,d[1]+x+1);
				while(x>n/2)
				{
					x--;
					ans-=d[1][l];
					l++;
				}
			}
			if(y>n/2)
			{
				int l=1;
				sort(d[2]+1,d[2]+y+1);
				while(y>n/2)
				{
					y--;
					ans-=d[2][l];
					l++;
				}
			}
			if(z>n/2)
			{
				int l=1;
				sort(d[3]+1,d[3]+z+1);
				while(z>n/2)
				{
					z--;
					ans-=d[3][l];
					l++;
				}			
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 

#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int x,y,z;
}a[100100];
int b[100100];
int n,T,xx,yy,zz,ans;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		xx=yy=zz=ans=0;
		memset(b,0,sizeof(b));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z)
			{
				ans+=a[i].x;
				xx++;
			}
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z)
			{
				ans+=a[i].y;
				yy++;
			}
			else
			{
				ans+=a[i].z;
				zz++;
			}
		}
		if(xx<=n/2&&yy<=n/2&&zz<=n/2)
		{
			cout<<ans<<'\n';
		}
		else if(xx>n/2)
		{
			int k=xx-n/2;
			for(int i=1;i<=n;i++)
			{
				if(a[i].x>=a[i].y&&a[i].x>=a[i].z)
				{
					b[i]=a[i].x-max(a[i].y,a[i].z);
				} 
				else
				{
					b[i]=1e9;
				}
			}
			sort(b+1,b+n+1);
			for(int i=1;i<=k;i++)
			{
				ans-=b[i];
			}
			cout<<ans<<'\n';
		}
		else if(yy>n/2)
		{
			int k=yy-n/2;
			for(int i=1;i<=n;i++)
			{
				if(a[i].y>=a[i].x&&a[i].y>=a[i].z)
				{
					b[i]=a[i].y-max(a[i].x,a[i].z);
				} 
				else
				{
					b[i]=1e9;
				}
			}
			sort(b+1,b+n+1);
			for(int i=1;i<=k;i++)
			{
				ans-=b[i];
			}
			cout<<ans<<'\n';
		}
		else if(zz>n/2)
		{
			int k=zz-n/2;
			for(int i=1;i<=n;i++)
			{
				if(a[i].z>=a[i].x&&a[i].z>=a[i].y)
				{
					b[i]=a[i].z-max(a[i].x,a[i].y);
				} 
				else
				{
					b[i]=1e9;
				}
			}
			sort(b+1,b+n+1);
			for(int i=1;i<=k;i++)
			{
				ans-=b[i];
			}
			cout<<ans<<'\n';
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

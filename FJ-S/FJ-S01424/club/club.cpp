#include<bits/stdc++.h>
using namespace std;
int t,n,ans,ax[100005],ay[100005],az[100005],lenx,leny,lenz;
struct node
{
	int x,y,z,mincha;
}a[100005];
bool cmp(int xx,int yy)
{
	return a[xx].mincha<a[yy].mincha;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		lenx=leny=lenz=ans=0;
		for(int i=1;i<=n;i++) 
		{
			int xy,xz;
			cin>>a[i].x>>xy>>xz;
			a[i].y=xy-a[i].x;a[i].z=xz-a[i].x;
			if(a[i].y>0)
			{
				if(a[i].y>=a[i].z) 
				{
					ans+=a[i].x+a[i].y;
					ay[++leny]=i;
					a[i].mincha=min(a[i].y,a[i].y-a[i].z);
				}
				else
				{
					ans+=a[i].x+a[i].z;
					az[++lenz]=i;
					a[i].mincha=min(a[i].z,a[i].z-a[i].y);
				}
			}
			else if(a[i].z>0)
			{
				ans+=a[i].x+a[i].z;
				az[++lenz]=i;
				a[i].mincha=min(a[i].z,a[i].z-a[i].y);
			}
			else
			{
				ans+=a[i].x;
				ax[++lenx]=i;
				a[i].mincha=-(max(a[i].z,a[i].y));
			}
		}
		if(lenx>n/2)
		{
			sort(ax+1,ax+lenx+1,cmp);
			for(int i=1;i<=lenx-n/2;i++) 
			{
				ans-=a[ax[i]].mincha;
			}
			cout<<ans<<endl;
		}
		else if(leny>n/2)
		{
			sort(ay+1,ay+leny+1,cmp);
			for(int i=1;i<=leny-n/2;i++) ans-=a[ay[i]].mincha;
			cout<<ans<<endl;
		}
		else if(lenz>n/2)
		{
			sort(az+1,az+lenz+1,cmp);
			for(int i=1;i<=lenz-n/2;i++) 
			{
				ans-=a[az[i]].mincha;
			}
			cout<<ans<<endl;
		}
		else cout<<ans<<endl;
	}
	return 0;
}

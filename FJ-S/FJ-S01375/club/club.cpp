#include<bits/stdc++.h>
using namespace std;
int t,n,ans,sa,sb,sc,ey,ez,anss;
struct node{
	int x,y,z,b;
	bool r;
}a[210000];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std::cin>>t;
	for(int o=1;o<=t;o++)
	{
		sa=0;sb=0;sc=0;ey=0;ez=0;ans=0;
		std::cin>>n;
		for(int i=1;i<=n;i++)
		{
			std::cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].r=0;
			if(a[i].y!=0) ey=1;
			if(a[i].z!=0) ez=1;
		}
		if(n==2)
		{
			anss=0;
			anss=a[1].x+a[2].y;
			if(anss>ans) ans=anss;
			anss=0;
			anss=a[1].x+a[2].z;
			if(anss>ans) ans=anss;
			anss=0;
			anss=a[1].y+a[2].x;
			if(anss>ans) ans=anss;
			anss=0;
			anss=a[1].y+a[2].z;
			if(anss>ans) ans=anss;
			anss=0;
			anss=a[1].z+a[2].x;
			if(anss>ans) ans=anss;
			anss=0;
			anss=a[1].z+a[2].y;
			if(anss>ans) ans=anss;
			std::cout<<ans<<endl;
			continue;
		}
		if(ey==0&&ez==0)
		{
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++) if(a[j].x<a[j+1].x) swap(a[j].x,a[j+1].x);
			for(int i=1;i<=n/2;i++) ans+=a[i].x;
			std::cout<<ans<<endl;
			continue;
		}
		else if(ez==0)
		{
			for(int i=1;i<=n;i++) a[i].b=abs(a[i].x-a[i].y);
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++) if(a[j].b<a[j+1].b) swap(a[j].b,a[j+1].b);
			for(int i=1;i<=n;i++)
			{
				if(a[i].x<a[i].y&&sa<=(n/2))
				{
					ans+=a[i].y;
					sa++;
				}
				else ans+=a[i].x;
			}
			std::cout<<ans<<endl;
			continue;
		}
	}
	return 0;
}
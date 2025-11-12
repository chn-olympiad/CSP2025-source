#include<bits/stdc++.h>
using namespace std;
struct zz{
	int a;
	int b;
	int c;
};
int cmp(zz x,zz y)
{
	if(x.a>=y.a)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int cmpb(zz xb,zz yb)
{
	if(xb.b>=yb.b)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int cmpc(zz xc,zz yc)
{
	if(xc.c>=yc.c)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
zz cl[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int xx=0,xxb=0,xxc=0;
		for(int i=1;i<=n;i++)
		{
			cin>>cl[i].a>>cl[i].b>>cl[i].c;
			if(cl[i].b==0&&cl[i].c==0)
			{
				xx++;
			}
			if(cl[i].b==0&&cl[i].a==0)
			{
				xxb++;
			}
			if(cl[i].a==0&&cl[i].c==0)
			{
				xxc++;
			}
		}
		if(xx==n)
		{
			int ans=0;
			sort(cl+1,cl+n+1,cmp);
			for(int i=1;i<=n/2;i++)
			{
				ans+=cl[i].a;
			}
			cout<<ans;
		}
		else if(xxb==n)
		{
			int ans=0;
			sort(cl+1,cl+n+1,cmpc);
			for(int i=1;i<=n/2;i++)
			{
				ans+=cl[i].c;
			}
			cout<<ans;
		}
		else if(xxc==n)
		{
			int ans=0;
			sort(cl+1,cl+n+1,cmpb);
			for(int i=1;i<=n/2;i++)
			{
				ans+=cl[i].b;
			}
			cout<<ans;
		}
		else
		{
			sort(cl+1,cl+n+1,cmp);
			int ans=0,j=0,ma=n/2,mb=n/2,mc=n/2;
			while(ma>0||j==n)
			{
				j++;
				if(cl[j].a>=cl[j].b&&cl[j].a>=cl[j].c)
				{
					ans+=cl[j].a;
					ma--;
					cl[j].b=0;
					cl[j].c=0;
				}
				cl[j].a=0;
			}
			j=0;
			sort(cl+1,cl+n+1,cmpb);
			while(mb>0||j==n)
			{
				j++;
				if(cl[j].b>=cl[j].a&&cl[j].b>=cl[j].c)
				{
					ans+=cl[j].b;
					mb--;
					cl[j].a=0;
					cl[j].c=0;
				}
				cl[j].b=0;
			}
			j=0;
			sort(cl+1,cl+n+1,cmpc);
			while(mc>0||j==n)
			{
				j++;
				ans+=cl[j].c;
				mc--;
				cl[j].a=0;
				cl[j].c=0;
				cl[j].b=0;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

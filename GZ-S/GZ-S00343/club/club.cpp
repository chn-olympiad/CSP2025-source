//GZ-S00343 贵阳市第三实验中学 王颢阳

#include<bits/stdc++.h>
using namespace std;

struct abc{
	int a;
	int b;
	int c;
	int f;
}p[100010];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=0;
	scanf("%d",&t);
	while(t--)
	{
		int j=100010,n=0,na=0,nb=0,nc=0,ans=0,d=0;
		scanf("%d",&n);
		int k=n/2;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&p[i].a);
			scanf("%d",&p[i].b);
			scanf("%d",&p[i].c);
		}
	    for(int i=0;i<n;i++)
	    {
	    	if(p[i].a>p[i].b&&p[i].a>p[i].c)
	    	{
	    		ans+=p[i].a;
	    		na++;
	    		p[i].f=1;
			}
			else if(p[i].b>p[i].c)	
			{
				ans+=p[i].b;
				nb++;
				p[i].f=2;
		    }     
		    else
		    {
		    	ans+=p[i].c;
		    	nc++;
		    	p[i].f=3;
			}
		}
		while(na>k)
		{
			for(int i=0;i<n;i++)
			{
				if(p[i].f==1)
				{
					d=max(p[i].b,p[i].c);
					j=min(j,p[i].a-d);
				}
			}
			ans-=j;
			na--;
		}
		while(nb>k)
		{
			for(int i=0;i<n;i++)
			{
				if(p[i].f==2)
				{
					d=max(p[i].a,p[i].c);
					j=min(j,p[i].b-d);
				}
			}
			ans-=j;
			nb--;
		}
		while(nc>k)
		{
			for(int i=0;i<n;i++)
			{
				if(p[i].f==3)
				{
					d=max(p[i].a,p[i].b);
					j=min(j,p[i].c-d);
				}
			}
			ans-=j;
			nc--;
		}
		cout<<ans<<endl;
	}	
	return 0;
} 

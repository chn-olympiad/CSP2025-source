#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int n,r,t,ba,bb,bc,qu,vis[N],ra,rb,rc;
struct A
{
	int a;
};A ma[N],mb[N],mc[N];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	for(int _=1;_<=t;_++)
	{
		memset(ma,0,sizeof(ma));
		memset(mb,0,sizeof(mb));
		memset(mc,0,sizeof(mc));
		ra=rb=rc=0;
		ba=bb=bc=0;
		qu=0;
		scanf("%lld",&n);
		r=n/2;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&ma[i].a,&mb[i].a,&mc[i].a);
			if(ma[i].a>mb[i].a)
			{
				if(ma[i].a>mc[i].a)
				{
					if(ra<r)
					{
						ra++;
						ba+=ma[i].a;
						vis[i]=1;
					}
					else
					{
						int mi=0x3f3f3f;
						int mii=0x3f3f3f;
						for(int j=1;j<=i;j++)
						{
							mi=min(mi,ma[i].a);
							if(mi!=mii)
							{
								mii=mi;
								qu=j;
							}
						}
						if(ma[i].a>mi)
						{
							ba-=mi;
							vis[qu]=0;
							ba+=ma[i].a;
							vis[ba]=1;
						}
						
					}
				}
				else
				{
					if(rc<r)
					{
						rc++;
						bc+=mc[i].a;
						vis[i]=1;
					}
					else
					{
						int mi=0x3f3f3f;
						int mii=0x3f3f3f;
						for(int j=1;j<=i;j++)
						{
							mi=min(mi,mc[i].a);
							if(mi!=mii)
							{
								mii=mi;
								qu=j;
							}
						}
						if(mc[i].a>mi)
						{
							bc-=mi;
							vis[qu]=0;
							bc+=mc[i].a;
							vis[ba]=1;
						}
						
					}
				}
			}
			else
			{
				if(mb[i].a>mc[i].a)
				{
					if(rb<r)
					{
						rb++;
						bb+=mb[i].a;
						vis[i]=1;
					}
					else
					{
						int mi=0x3f3f3f;
						int mii=0x3f3f3f;
						for(int j=1;j<=i;j++)
						{
							mi=min(mi,mb[i].a);
							if(mi!=mii)
							{
								mii=mi;
								qu=j;
							}
						}
						if(mb[i].a>mi)
						{
							bb-=mi;
							vis[qu]=0;
							bb+=mb[i].a;
							vis[bb]=1;
						}
					}
				}
				else
				{
					if(rc<r)
					{
						rc++;
						bc+=mc[i].a;
						vis[i]=1;
					}
					else
					{
						int mi=0x3f3f3f;
						int mii=0x3f3f3f;
						for(int j=1;j<=i;j++)
						{
							mi=min(mi,mc[i].a);
							if(mi!=mii)
							{
								mii=mi;
								qu=j;
							}
						}
						if(mc[i].a>mi)
						{
							bc-=mi;
							vis[qu]=0;
							bc+=mc[i].a;
							vis[ba]=1;
						}
						
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(vis[i]=0)
			{
				if(ra<r)
				{
					if(rb<r)
					{
						if(rc<r)
						{
							int y=ma[i].a;
							int u=mb[i].a;
							int x=mc[i].a;
							int mi=max(y,max(u,x));
							if(mi==y)
							{
								ba+=y;
							}
							else if(mi==u)
							{
								bb+=u;
							}
							else if(mi==x)
							{
								bc+=x;
							}
						}
						else
						{
							int y=ma[i].a;
							int u=mb[i].a;
							int mi=max(y,u);
							if(mi==y)
							{
								ba+=y;
							}
							else if(mi==u)
							{
								bb+=u;
							}
						}
					}
					else
					{
						if(rc<r)
						{
							int y=ma[i].a;
							int x=mc[i].a;
							int mi=max(y,x);
							if(mi==y)
							{
								ba+=y;
							}
							else if(mi==x)
							{
								bc+=x;
							}
						}
					}
				}
				else
				{
					if(rb<r)
					{
						if(rc<r)
						{
							int u=mb[i].a;
							int x=mc[i].a;
							int mi=max(u,x);
							if(mi==u)
							{
								bb+=u;
							}
							else if(mi==x)
							{
								bc+=x;
							}
						}
					}
					else
					{
						bc+=mc[i].a;
					}
				}
			}
		}
		cout<<ba+bb+bc<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int maxx=1e5+10;

struct num{
	int a,b,c,maxn,maxw,cha;
}p[maxx];

bool cmp(num ax,num bx)
{
	if(ax.maxn!=bx.maxn)
		return ax.maxn>bx.maxn;
	else
	{
		return ax.cha>bx.cha;
	}
}

int bc[3];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--)
	{
		memset(bc,0,sizeof(bc));
		long long ans=0;
		cin>>n;
		int x,y;
		for (int i=1;i<=n;i++)
		{
			cin>>p[i].a>>x>>y;
			p[i].b=x-p[i].a;
			p[i].c=y-p[i].a;
			if(p[i].b==p[i].c)
			{
				p[i].maxn=p[i].b;
				p[i].maxw=0;
				p[i].cha=0;
			}
			else if(p[i].b>p[i].c)
			{
				p[i].maxn=p[i].b;
				p[i].maxw=1;
				p[i].cha=p[i].b-p[i].c;
			}
			else
			{
				p[i].maxn=p[i].c;
				p[i].maxw=2;
				p[i].cha=p[i].c-p[i].b;
			}
			ans+=p[i].a;
		}
		int change=0;
		sort(p+1,p+n+1,cmp);
		for (int i=1;i<=n/2;i++)
		{
			ans+=p[i].maxn;
			if(p[i].maxw!=0) bc[p[i].maxw]++;
			else
			{
				bc[1]++;
				change++;
			}
		}
		for (int i=n/2+1;i<=n;i++)
		{
			if(p[i].maxn<0) break;
			if(p[i].maxw==0)
			{
				if(bc[1]<n/2)
				{
					bc[1]++;
					change++;
				}
				else
				{
					bc[2]++;
				}
				ans+=p[i].maxn;
				continue;
			}
			bc[p[i].maxw]++;
			if(bc[p[i].maxw]>=n/2)
			{
				if(change>0)
				{
					bc[p[i].maxw]--;
					if(p[i].maxw==1)
					{
						bc[2]++;
					}
					else
					{
						bc[1]++;
					}
					ans+=p[i].maxn;
				}
				else{
					if(p[i].maxw==1)
					{
						if(p[i].c>0&&bc[2]<n/2)
						{
							bc[1]--;
							bc[2]++;
							ans+=p[i].c;
						}
						else
						{
							bc[1]--;
						}
					}
					else
					{
						if(p[i].b>0&&bc[1]<n/2)
						{
							bc[2]--;
							bc[1]++;
							ans+=p[i].b;
						}
						else
						{
							bc[2]--;
						}
					}
				}
			}
			else
			{
				ans+=p[i].maxn;
			}
			
		}
		cout<<ans<<endl;
	}
	return 0;
}

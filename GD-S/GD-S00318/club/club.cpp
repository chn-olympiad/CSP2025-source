#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll N=1e5+6;
struct node{
	ll x,y,z,mi,mo,ma;
}s[N];
int a[N],b[N],c[N];
bool cmp(node l,node r)
{
	if(l.ma==r.ma)
	{
		if(l.mo==r.mo)
		{
			return l.mi>r.mi;
		}
		return l.mo>r.mo;
	}
	return l.ma>r.ma;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t,n,ans;
	scanf("%lld",&t);
	while(t--)
	{
		ans=0;
		ll aa=0,bb=0,cc=0;
		ll af=0,bf=0,cf=0;
		ll as=0,bs=0,cs=0;
		memset(s,0,sizeof s);
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(c,0,sizeof c);
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&s[i].x,&s[i].y,&s[i].z);
			s[i].ma=max(s[i].x,s[i].y);
			s[i].ma=max(s[i].ma,s[i].z);
			s[i].mi=min(s[i].x,s[i].y);
			s[i].mi=min(s[i].mi,s[i].z);
			s[i].mo=s[i].x+s[i].y+s[i].z-s[i].ma-s[i].mi;
		}
		sort(s+1,s+n+1,cmp);
		//for(int i=1;i<=n;i++) printf("%lld %lld %lld\n",s[i].x,s[i].y,s[i].z);
		for(int i=1;i<=n;i++) ans+=s[i].ma;
		//printf("%d\n",ans);
		for(int i=1;i<=n;i++)
		{
			
			if(s[i].x>=s[i].y&&s[i].x>=s[i].z)
			{
				if(aa==n/2)
				{
					if( s[af].x+max(s[i].y,s[i].z) < s[i].x+max(s[af].y,s[af].z) )
					{
						as-=s[af].x;
						as+=s[i].x;
						if(s[af].y>s[af].z)
						{
							bs+=s[af].y;
							bf=af;
							bb++;
						}
						else
						{
							cs+=s[af].z;
							cf=af;
							cc++;
						}
						af=i;
					}
					else
					{
						if(s[i].y>s[i].z)
						{
							bs+=s[i].y;
							bf=i;
							bb++;
						}
						else
						{
							cs+=s[i].z;
							cf=i;
							cc++;
						}
					}
				}
				else
				{
					af=i;
					as+=s[i].x;
					aa++;
				}
			}
			
			if(s[i].y>=s[i].x&&s[i].y>=s[i].z)
			{
				if(bb==n/2)
				{
					if( s[bf].x+max(s[i].x,s[i].z) < s[i].y+max(s[bf].x,s[bf].z) )
					{
						bs-=s[bf].x;
						bs+=s[i].x;
						if(s[bf].x>s[bf].z)
						{
							as+=s[bf].x;
							af=bf;
							aa++;
						}
						else
						{
							cs+=s[bf].z;
							cf=bf;
							cc++;
						}
						bf=i;
					}
					else
					{
						if(s[i].x>s[i].z)
						{
							as+=s[i].x;
							af=i;
							aa++;
						}
						else
						{
							cs+=s[i].z;
							cf=i;
							cc++;
						}
					}
				}
				else
				{
					bf=i;
					bs+=s[i].y;
					bb++;
				}
			}
			
			if(s[i].z>=s[i].y&&s[i].z>=s[i].x)
			{
				if(cc==n/2)
				{
					if( s[cf].z+max(s[i].y,s[i].x) < s[i].z+max(s[cf].y,s[cf].x) )
					{
						cs-=s[cf].z;
						cs+=s[i].z;
						if(s[cf].y>s[cf].x)
						{
							bs+=s[cf].y;
							bf=cf;
							bb++;
						}
						else
						{
							as+=s[cf].x;
							af=cf;
							aa++;
						}
						cf=i;
					}
					else
					{
						if(s[i].y>s[i].x)
						{
							bs+=s[i].y;
							bf=i;
							bb++;
						}
						else
						{
							as+=s[i].x;
							af=i;
							aa++;
						}
					}
				}
				else
				{
					cf=i;
					cs+=s[i].z;
					cc++;
				}
			}
			
		}
		printf("%lld\n",as+bs+cs);
	}
	return 0;
}
